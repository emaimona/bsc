#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <limits>
#include <fstream>



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
     int validVotes;
     int invalidVotes;
}; 

// sendig a message
int send( int mqueue,  int valid, int invalid ) 
{ 
    struct messg m = { 5, valid, invalid};
    // strcat(m.mtext, message);
     int status; 
     status = msgsnd( mqueue, &m, sizeof(int)*4 , 0 ); 
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
     else {
        int valid = m.validVotes;
        int invalid = m.invalidVotes;
        string result = "The are ";
        result += to_string(m.validVotes);
        result += " valid votes and ";
        result += to_string(m.invalidVotes);
        result += " invalid votes.\n";
        
        result +="The percentage is ";
        result += to_string((int)((float)valid/(valid+invalid)*100));
        result += "%\n";
        cout<< result << endl;

        std::ofstream outputFile("output.txt");
        if (!outputFile) {
            std::cerr << "Failed to open the file." << std::endl;
            return 1;
        }

        outputFile << result;
        outputFile.close();
        std::cout << "Data has been written to the file." << std::endl<< endl;

    }
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

int getRandomNumber() {
    return rand()%100 + 1;
}

bool voteOrNot(int number) {
    return rand()%2;
}

int voteInParty() {
    return rand()%3 + 4;
} 

int main(int argc, char* argv[]) {
    srand(time(NULL)); //the starting value of random number generation

    if (argc != 2) {
        cout << "Usage: a.out 17" << endl;
        exit(1);
    }   

    struct sigaction sigact;
    sigact.sa_handler=handler;
    sigemptyset(&sigact.sa_mask);   
    sigact.sa_flags=0;
    sigaction(SIGUSR1,&sigact,NULL);
    sigaction(SIGUSR2,&sigact,NULL);
    char buffer[1024]; 
    string message;
    int votes = atoi(argv[1]);
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
                    semaphore_operation(semid,1);

                    cout<< "The chairman waits until both members indicate that they are ready to work."<< endl;
                    pause();
                    cout<< "Signal from Data validator has arrived"<< endl;
                    pause();
                    cout<< "Signal from Ballot handler has arrived"<< endl;


                    cout<< "The Chairman read " << votes << " votes from the cmd line."<< endl;
                    cout<< "The Chairman send the voters ID to the data validator member"<< endl;
                    // strcat(s, "Daily list:' (Null character at the end)\n");
                    // semaphore_operation(semid,1); // Up
                    
                    // int status;
                    // pause();
                    // cout<< "Student 1 sent a signal\n";
                    // printf("Professor Answers Student 1!\n");
                    message = "";
                    for (int i = 0; i < votes; i++) {
                        message += to_string(getRandomNumber());
                        message += " ";
                    }

                    close(pipefd1[0]);
                    write(pipefd1[1], message.data(), 1024); 
                    close(pipefd1[1]);

                    waitpid(child2, &status, 0);

                    sleep(1);
                    cout<< "The Chairman receives the result from the Ballot handler."<< endl;
                    receive( messg );
                    waitpid(child1, &status, 0);


                    semaphore_operation(semid,-1); // down, wait if necessary
                    cout<<"The Chairmen prints the file result received, and announces the winner"<< endl;
                    cout<< s << endl;
                    shmdt(s);
                    semaphore_operation(semid,1); 
                    exit(EXIT_SUCCESS);

                } else {
                    // Child 2 process
                    // sleep(1);
                    kill(getppid(), SIGUSR2);

                    sleep(2);
                    close(pipefd1[1]);
                    read(pipefd1[0], buffer, sizeof(buffer));
                    cout<< "Data validator receives the voters ID from the chairman."<< endl;
                    close(pipefd1[0]);

                    cout << "Printing...." << endl;
                    char* token = std::strtok(buffer, " ");
                    string validVotes;

                    while (token != nullptr) {
                        cout<< token << " ";
                        validVotes += voteOrNot(atoi(token)) ? "vote" : "no_vote";
                        validVotes += " ";

                        token = std::strtok(nullptr, " ");
                    }
                    cout<< endl;


                    cout<< "Data validator sends the result to the Ballot"<< endl;
                    close(pipefd2[0]);
                    write(pipefd2[1], validVotes.data(), 1024); 
                    close(pipefd2[1]);

                    cout<< " ->  "<< validVotes << endl;
                    exit(EXIT_SUCCESS);
                }
            }
        } else {
            // Child 1 process

            sleep(1);
            kill(getppid(), SIGUSR1);

            sleep(1);

            close(pipefd2[1]);
            read(pipefd2[0], buffer, sizeof(buffer));
            cout<< "The Ballot handler receives the result from the data validator."<< endl;
            close(pipefd2[0]);

            char* token = std::strtok(buffer, " ");
            int validVotes = 0;
            while (token != nullptr) {
                if (!strcmp(token, "vote"))
                    validVotes++;
                token = std::strtok(nullptr, " ");
            }
            cout<< endl;

            cout<< "The Ballot handler sends the result to the chairman."<< endl;

            send( messg , validVotes, votes - validVotes);  // Parent sends a message. 

            int FOUR = 0, FIVE = 0, SIX = 0;
            for (int i = 0; i < validVotes; i++) {
                int party = voteInParty();
                if (party == 4)
                    FOUR++;
                else if (party == 5)
                    FIVE++;
                else
                    SIX++;
            }

            string res = "The number of votes for party 4: " + to_string(FOUR) + "\n";
            res += "The number of votes for party 5: " + to_string(FIVE) + "\n";
            res += "The number of votes for party 6: " + to_string(SIX) + "\n";
            res += "-> The winner was the party";
            res += (FOUR > FIVE ? (FOUR > SIX ? " 4" : " 6") : (FIVE > SIX ? " 5" : " 6"));
            res += "\n";

            semaphore_operation(semid,-1); // down, wait if necessary
            strcat(s, res.data());
            shmdt(s);
            semaphore_operation(semid,1); 

            // cout << "Student 1 process is finished" << endl;
            exit(EXIT_SUCCESS);
        }
    }

    

   
    status = msgctl( messg, IPC_RMID, NULL ); 
    shmctl(sh_mem_id,IPC_RMID,NULL);
    fflush(NULL); 
    if ( status < 0 ) 
        perror("msgctl error"); 


    return 0;
}