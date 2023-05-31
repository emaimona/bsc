#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <limits>



//* C libraries
#include <sys/ipc.h> 
#include <sys/msg.h> 
#include <cstdio> 
#include <cstdlib> 
#include <csignal>
#include <cstring> 
#include <unistd.h> 
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>


using namespace std;

int signal_number=0;

void handler(int signumber){
    // printf("\nSignal with number %i has arrived\n",signumber);
    signal_number = signumber;
}

struct messg { 
     long mtype;//this is a free value e.g for the address of the message
     char mtext [ 1024 ]; //this is the message itself
}; 

// sendig a message
int send( int mqueue, const char* message ) 
{ 
     struct messg m = { 5, "" }; 
     strcpy(m.mtext, message);

     int status; 
     status = msgsnd( mqueue, &m, strlen ( m.mtext ) + 1 , 0 ); 
     if ( status < 0 ) 
          perror("msgsnd error"); 
     return 0; 
} 
     
// receiving a message. 
int receive( int mqueue ) 
{ 
     struct messg m; 
     int status; 
	 
     status = msgrcv(mqueue, &m, 1024, 5, 0 ); 
     
     if ( status < 0 ) 
          perror("msgsnd error"); 
     else
          printf( "The message was : %s\n", m.mtext ); 
     return 0; 
} 



int semaphore_create(const char* pathname,int semaphore_value){
    int semid;
    key_t key;
    
    key=ftok(pathname,1);    
    if((semid=semget(key,1,IPC_CREAT|S_IRUSR|S_IWUSR ))<0)
	perror("semget");
    // semget 2. parameter is the number of semaphores   
    if(semctl(semid,0,SETVAL,semaphore_value)<0)    //0= first semaphores
        perror("semctl");
       
    return semid;
}


void semaphore_operation(int semid, int op){

    struct sembuf operation;
    
    operation.sem_num = 0;
    operation.sem_op  = op; // op=1 up, op=-1 down 
    operation.sem_flg = 0;
    
    if(semop(semid,&operation,1)<0) // 1 number of sem. operations
        perror("semop");	    
}

void semaphore_delete(int semid){
      semctl(semid,0,IPC_RMID);
}


int getRandomSpendMoney() {
    return rand()%50 + 100; 
}

int main(int argc, char* argv[]) {
    srand(getpid());


    struct sigaction sigact;
    sigact.sa_handler=handler;
    sigemptyset(&sigact.sa_mask);   
    sigact.sa_flags=0;
    sigaction(SIGUSR1,&sigact,NULL);
    sigaction(SIGUSR2,&sigact,NULL);
    char buffer[1024]; 
    string message;
    int pipefd1[2];
    int pipefd2[2];
    int messg, status; 
    key_t key; 


     key = ftok(argv[0],1); 
     printf ("The key: %d\n",key);
     messg = msgget( key, 0600 | IPC_CREAT ); 


    // shared memory
    int pid;
    int sh_mem_id, semid;
    

    if ((sh_mem_id=shmget(key,1024,IPC_CREAT|S_IRUSR|S_IWUSR))== -1) {
        perror("shmget");
        exit(1);
    }
    char *s = (char*)(shmat(sh_mem_id, NULL, 0));

    semid = semaphore_create(argv[0],0);

    if ( messg < 0 ) { 
        perror("msgget error"); 
        exit(EXIT_FAILURE); 
    } 


    if (pipe(pipefd1) == -1 || pipe(pipefd2) == -1) 
    {
        perror("Error with pipes!");
        exit(EXIT_FAILURE);
    }

    pid_t child1, child2;
    child1 = fork();
    if (child1 < 0) {
        perror("fork error");
    } else {
        if (child1 > 0) {
            // Parent process
            child2 = fork();
            if (child2 < 0) {
                perror("fork error");
            } else {
                if (child2 > 0) {
                    // Parent process
                    
                    
                    int status;
                    pause();
                    // cout<< "Student 1 sent a signal\n";
                    pause();
                    // sleep(1);
                    cout<< "The students (children's processes) are ready, they leave for the tank museum\n";
                    cout<< "They arrive, the instructor asks one of them to write on a pipe which tank they liked best\n";

                    pause();
                    close(pipefd2[1]);
                    read(pipefd2[0], buffer, sizeof(buffer));
                    printf("Professor reads message from Student 2: %s\n", buffer);
                    close(pipefd2[0]);

                    sleep(4);
                    cout<< "\nProfessor reads message from Student 1:" << endl;
                    receive( messg ); 

                    sleep(1);
                    cout<< "\nProfessor sends a message to Student 1!" << endl;
                    send(messg, "I'm is going to bed and that dinner will be postponed until the next day");

                    semaphore_operation(semid,1); // Up
                    //* child sends a signal
                    waitpid(child1, &status, 0);
                    
                    semaphore_operation(semid,-1); // Down

                    kill(child2, SIGUSR1);
                    sleep(1);
                    cout<< "\nProfessor reads message from Student 2!" << endl;
                    receive( messg ); 
                    
                    // kill(getpid(), SIGUSR1);
                    cout<< "\nProfessor sends a message to Student 2!" << endl;
                    send(messg, "I'm is going to bed and that dinner will be postponed until the next day");
                    
                    semaphore_operation(semid,1); // Up

                    waitpid(child2, &status, 0);

            
                    cout << "\nProfessor process is finished!" << endl;
                    cout<< "The students wrote in shared memory: " << s << endl;
                    
                    exit(EXIT_SUCCESS);
                    return 0;
                } else {
                    // Child 2 process
                    srand(getpid());

                    cout << "Student 2 sent a signal" << endl;
                    kill(getppid(), SIGUSR2);

                    pause();
                    close(pipefd1[1]);
                    read(pipefd1[0], buffer, sizeof(buffer));
                    printf("Student 2 read the message from Student 1: %s\n", buffer);
                    close(pipefd1[0]);


                    message = buffer;
                    message += ", T-55";
                    cout<< "The Student 2 sends a message to the professor : " << message << endl;
                    close(pipefd2[0]);
                    write(pipefd2[1], message.data(), 1024); 
                    close(pipefd2[1]);
                    kill(getppid(), SIGUSR2);

                    pause();
                    message = "I will be late getting back, I'll get back by bus.";
                    cout<< "\nStudent 2 sends a message to the professor!"<< endl;
                    send( messg , message.data()); 

                    pause();
                    cout<< "\nStudent 2 reads message from Professor:" << endl;
                    receive( messg ); 

                    semaphore_operation(semid,-1); // down, wait if necessary
                    message = "\n-> Student 2 spent " + to_string(getRandomSpendMoney()) + " Forints.";
                    strcat(s, message.data());
                    shmdt(s);
                    semaphore_operation(semid,1); 

                    exit(EXIT_SUCCESS);
                    return 0;
                }
            }
        } else {
            // Child 1 process
            srand(getpid());

            cout << "Student 1 sent a signal" << endl;
            kill(getppid(), SIGUSR1);

            sleep(1);
            message = "Tiger 1";
            printf("\nStudent 1 writes to Student 2: %s!\n", message.data());
            close(pipefd1[0]);
            write(pipefd1[1], message.data(), 1024); 
            close(pipefd1[1]);
            kill(child2, SIGUSR2);


            
            sleep(3);
            message = "I will be late getting back, I'll get back by taxi.";
            cout<< "Student 1 sends another message to the professor"<< endl;
            send( messg , message.data()); 

            sleep(5);
            cout<< "\nStudent1 reads message from Professor:" << endl;
            receive( messg ); 

             // sleep(1);
            semaphore_operation(semid,-1); // down, wait if necessary
            message = "\n-> Student 1 spent " + to_string(getRandomSpendMoney()) + " Pounds";
            strcat(s, message.data());
            shmdt(s);
            semaphore_operation(semid,1); 

            exit(EXIT_SUCCESS);
            return 0;
        }
    }

    

   
    status = msgctl( messg, IPC_RMID, NULL ); 
    shmctl(sh_mem_id,IPC_RMID,NULL);
    fflush(NULL); 
    if ( status < 0 ) 
        perror("msgctl error"); 


    return 0;
}