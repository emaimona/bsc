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
int send( int mqueue ) 
{ 
     const struct messg m = { 5, "Big crowd, in an hour at Trafalgar Square!" }; 
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
     // the last parameter is the number of the message
	// if it is 0, then we read the first one
	// if  >0 (e.g. 5), then message type 5 will be read
	 
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

int main(int argc, char* argv[]) {

    // if (argc != 3) {
    //     cout << "Usage: a.out \"Oxford Circus\" 17" << endl;
    //     exit(1);
    // }   

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


    // share memory
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

    // message += argv[1];
    // message += argv[2];


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
                    
                    // strcat(s, "Daily list:' (Null character at the end)\n");
                    // semaphore_operation(semid,1); // Up
                    
                    int status;
                    pause();
                    // cout<< "Student 1 sent a signal\n";
                    pause();
                    // sleep(1);
                    cout<< "The students (children's processes) are ready, they leave for the tank museum\n";
                    cout<< "They arrive, the instructor asks one of them to write on a pipe which tank they liked best\n";

                    

                    waitpid(child1, &status, 0);
                    // receive( messg ); 
                    

                    // // sleep(3);
                    // cout<< endl<< endl;


                    
                    

                    waitpid(child2, &status, 0);

                    close(pipefd2[1]);
                    read(pipefd2[0], buffer, sizeof(buffer));
                    printf("Profesoor reads message from Student 2: %s\n", buffer);
                    close(pipefd2[0]);

                    
                    // strcat(s, "Tutor: Piccadilly Circus, Buckingham Palace, Hyde Park\n");

                    // cout << "\nProfessor process is finished" << endl;

                    // printf("\nThe daily attactions of Three are:\n%s", s);
                    // shmdt(s);
                    exit(EXIT_SUCCESS);
                    return 0;
                } else {
                    // Child 2 process
                    // sleep(3);
                    // semaphore_operation(semid,-1); // down, wait if necessary
                    // strcat(s, "Child2: Westminster, London Eye, Soho\n");
                    // shmdt(s);
                    // semaphore_operation(semid,1); 


                    cout << "Student 2 sent a signal" << endl;
                    kill(getppid(), SIGUSR2);

                    sleep(3);
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


                   

                    exit(EXIT_SUCCESS);
                    return 0;
                }
            }
        } else {
            // Child 1 process

            // sleep(1);
            // semaphore_operation(semid,-1); // down, wait if necessary
            // strcat(s, "Child1: British Museum, Tower, Big Ben\n");
            // shmdt(s);
            // semaphore_operation(semid,1); 

            // sleep(1);
            cout << "Student 1 sent a signal" << endl;
            kill(getppid(), SIGUSR1);

            sleep(2);
            message = "Tiger 1";
            printf("Students 1 writes to Student 2: %s!\n", message.data());
            close(pipefd1[0]);
            write(pipefd1[1], message.data(), 1024); 
            close(pipefd1[1]);


            

            // printf("Student 1 arrives early and send a new location..\n");
            // send( messg );  // Parent sends a message. 
        
            // cout << "Student 1 process is finished" << endl;
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