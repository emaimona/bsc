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

int getRandomNumber(int lim, int start) {
    return rand()%lim + start;
}

int counter = 0;

void childSignalHandler(int signum) {
    counter++;
    std::cout << "Parent received signal from child " << counter << " and sends the response"<< endl;
}

int main(int argc, char* argv[]) {
     srand(time(NULL));
    char buffer[1024];
    char* idText[] = {"lion", "bear", "wolf"};
    char* rabbitTypes[] = {"young", "adult", "old"};

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <number_of_children>" << std::endl;
        return 1;
    }

    int n = std::atoi(argv[1]);

    int pipefd1[2], pipefd2[2];
    if (pipe(pipefd1) == -1 || pipe(pipefd2) == -1) {
        std::cerr << "Failed to create pipes." << std::endl;
        return 1;
    }

    signal(SIGPIPE, SIG_IGN); // Ignore SIGPIPE signal to handle broken pipes gracefully
    signal(SIGUSR1, childSignalHandler);

        pid_t pid;

    for (int i = 0; i < n; ++i) {

        int tempPipe[2];
        if (pipe(tempPipe) == -1) {
            std::cerr << "Failed to create pipe." << std::endl;
            return 1;
        }

        pid = fork();

        if (pid < 0) {
            std::cerr << "Error creating child process." << std::endl;
            return 1;
        } else if (pid == 0) {
            // Child process code
            cout<< "Child " << getpid() << " sends a signal to the parent" << endl;

            sleep(1); // Sleep for 2 seconds to allow parent to set up signal handler
            kill(getppid(), SIGUSR1);
            sleep(1);

            close(tempPipe[1]);
            read(tempPipe[0], buffer, sizeof(buffer));
            cout<< "The expedition with "<< buffer <<" is ready to start!"<< endl;
            close(tempPipe[0]);

            sleep(1);
            close(pipefd1[0]); // Close the read end of the pip
            string m = "Message from child ";
            m += to_string(getpid());

            if (write(pipefd1[1], m.data(), 1024) == -1) {
                std::cerr << "Failed to write to pipe." << std::endl;
                return 1;
            }
            close(pipefd1[1]); // Close the write end of the pipe


            cout<< "Child " << getpid() << " finished the observations and sent the results!" << endl;
            close(pipefd2[0]); // Close the read end of the pip
            m = "\nThe identification text is: ";
            m += buffer;
            m += "\n The observed rabit is: ";
            m += rabbitTypes[getRandomNumber(3, 0)];
            m += "\n";

            if (write(pipefd2[1], m.data(), 1024) == -1) {
                std::cerr << "Failed to write to pipe." << std::endl;
                return 1;
            }
            close(pipefd2[1]);
            exit(EXIT_SUCCESS);
            return 0;
        } else {

            string ch =  idText[getRandomNumber(3, 0)];
            cout<< "Parent sends "<< ch << " to child " << (i+1) << endl;
            close(tempPipe[0]);
            write(tempPipe[1],ch.data(), 1024); 
            close(tempPipe[1]);

            sleep(1);
            close(pipefd1[1]); // Close the write end of the pipe
            read(pipefd1[0], buffer, sizeof(buffer));
            std::cout << "Received message from child: " << std::string(buffer) << std::endl;
            close(pipefd1[0]); 
            cout<< endl;

            wait(NULL);

            close(pipefd2[1]); // Close the write end of the pipe
            read(pipefd2[0], buffer, sizeof(buffer));
            std::cout << "Parent reads the message from child: " << std::string(buffer) << std::endl;
            close(pipefd2[0]); 
            cout<< endl;

            // exit(EXIT_SUCCESS);
        }
    }

    // // pause();
    // sleep(3);
    // close(pipefd[1]); // Close the write end of the pipe

    // ssize_t bytesRead;

    // while ((bytesRead = read(pipefd[0], buffer, sizeof(buffer))) > 0) {
    //     if (strlen(buffer) > 0) {
    //         std::cout << "Received message from child: " << std::string(buffer, bytesRead) << std::endl;

    //         wait(NULL);
    //     }
    // }

    // close(pipefd[0]); // Close the read end of the pipe

    // // Parent process waits for all child processes to terminate
    // for (int i = 0; i < n; ++i) {
    //     wait(NULL);
    // }

    return 0;
}

