#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/msg.h>
#include <cstring>
#include <cstdlib>

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <limits>

//* C libraries
#include <sys/ipc.h> 
#include <sys/msg.h> 
#include <sys/types.h> 
#include <cstdio> 
#include <cstdlib> 
#include <csignal>
#include <cstring> 
#include <unistd.h> 
#include <sys/wait.h> 


using namespace std;

int signal_number=0;

void handler(int signumber){
    // printf("\nSignal with number %i has arrived\n",signumber);
    signal_number = signumber;
}

int main(int argc, char* argv[]) {

     struct sigaction sigact;
    sigact.sa_handler=handler;
    sigemptyset(&sigact.sa_mask);   
    sigact.sa_flags=0;
    sigaction(SIGTERM,&sigact,NULL);
    sigaction(SIGUSR1,&sigact,NULL);
    sigaction(SIGUSR2,&sigact,NULL);
    string message;

    if (argc != 3) {
        cout << "Usage: a.out \"Oxford Circus\" 17" << endl;
        exit(1);
    }   

    message += argv[1];
    message += argv[2];

    int pipefd1[2];
    int pipefd2[2];

    char buffer[1024]; 
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
                    cout<< "Student 1 sent a signal\n";
                    printf("Professor Answers Student 1!\n");
                    close(pipefd1[0]);
                    write(pipefd1[1], message.data(), 1024); 
                    close(pipefd1[1]);

                    fflush(NULL); 
                    waitpid(child1, &status, 0);
                    

                    cout<< endl<< endl;
                    pause();
                    cout<< "Student 2 sent a signal\n";
                    printf("Professor Answers Student 2!\n");
                    close(pipefd2[0]);
                    write(pipefd2[1], message.data(), 1024); 
                    close(pipefd2[1]);

                    fflush(NULL); 
                    waitpid(child2, &status, 0);

                    cout << "\n\Professor process is finished" << endl;
                } else {
                    // Child 2 process
                    sleep(3);
                    cout << "Student 2 process is started" << endl;
                    kill(getppid(), SIGUSR2);

                    close(pipefd2[1]);
                    read(pipefd2[0], buffer, sizeof(buffer));
                    printf("Student 2 read the message: %s\n", buffer);
                    close(pipefd2[0]);
                    cout << "Student 2 process is finished" << endl;
                }
            }
        } else {
            // Child 1 process

            cout << "Student 1 process is started" << endl;
            kill(getppid(), SIGUSR1);

            close(pipefd1[1]);
            read(pipefd1[0], buffer, sizeof(buffer));
            printf("Student 1 read the message: %s\n", buffer);
            close(pipefd1[0]);

            cout << "Student 1 process is finished" << endl;
        }
    }


   


    return 0;
}