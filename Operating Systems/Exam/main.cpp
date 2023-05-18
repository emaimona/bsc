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

#define MAX_TEXT_LENGTH 100
using namespace std;
// Structure for message queue
struct Message {
    long mtype;  // Message type
    char mtext[MAX_TEXT_LENGTH];  // Message text
};

// Structure for shared memory
struct SharedMemory {
    int count;  // Number of processes that have written
    char text[MAX_TEXT_LENGTH];  // Shared text
};

void handle_signal(int sig) {
    // Do nothing, just catch the signal
}

// Semaphore operations
void semaphore_operation(int semid, int op) {
    struct sembuf operation;
    operation.sem_num = 0;
    operation.sem_op = op;  // op = 1 for up, op = -1 for down
    operation.sem_flg = 0;
    semop(semid, &operation, 1);  // Perform semaphore operation
}

void semaphore_delete(int semid){
      semctl(semid,0,IPC_RMID);
}

int main(int argc, char* argv[]) {
     struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = handle_signal;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    int pipefd[2];  // Pipe file descriptors
    int msgqid;  // Message queue ID
    int shmid;  // Shared memory ID
    int semid;  // Semaphore ID
    pid_t child1, child2;

    // Create pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(1);
    }

    // Create message queue
    key_t msgqkey = ftok(argv[0], 'A');
    if ((msgqid = msgget(msgqkey, IPC_CREAT | 0666)) == -1) {
        perror("msgget");
        exit(1);
    }

    // Create shared memory
    key_t shmkey = ftok(argv[0], 'B');
    if ((shmid = shmget(shmkey, sizeof(SharedMemory), IPC_CREAT | 0666)) == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory to the process
    SharedMemory* shm = (SharedMemory*)shmat(shmid, NULL, 0);
    shm->count = 0;
    strcpy(shm->text, "Daily list:");

    // Create semaphore
    key_t semkey = ftok(argv[0], 'C');
    if ((semid = semget(semkey, 1, IPC_CREAT | 0666)) == -1) {
        perror("semget");
        exit(1);
    }
    // Initialize semaphore value to 1 (unlocked)
    semaphore_operation(semid, 1);

    // Fork child processes
    child1 = fork();
    if (child1 == 0) {
        // Child 1 (PHD student 1)
        close(pipefd[0]);  // Close unused read end of the pipe
        cout<< "\nStudent 1 send a signal to the instructor.\n"<< endl;
        kill(getppid(), SIGUSR1);
        // Send signal to parent through pipe
        std::string signal = "Ready for the day trip!";
        write(pipefd[1], signal.c_str(), signal.length() + 1);

        sleep(1);
        // Receive meeting location from parent through pipe
        char meetingLocation[MAX_TEXT_LENGTH];
        read(pipefd[0], meetingLocation, sizeof(meetingLocation));
        std::cout << "Child 1: Meeting location received from parent: " << meetingLocation << std::endl;
        

        // Send new location message to parent and partner through message queue
        Message msg;
        msg.mtype = 1;  // Message type
    std::string newLocation = "Big crowd, in an hour at Trafalgar Square!";
    strcpy(msg.mtext, newLocation.c_str());
    msgsnd(msgqid, &msg, sizeof(msg.mtext), 0);
    std::cout << "Child 1: Sent new location message to parent and partner" << std::endl;

    close(pipefd[1]);  // Close write end of the pipe

    exit(0);
} else {
    child2 = fork();
    if (child2 == 0) {
        // Child 2 (PHD student 2)
        close(pipefd[0]);  // Close unused read end of the pipe

        // Send signal to parent through pipe
        std::string signal = "Ready for the day trip!";
        write(pipefd[1], signal.c_str(), signal.length() + 1);

        // Receive meeting location from parent through pipe
        char meetingLocation[MAX_TEXT_LENGTH];
        read(pipefd[1], meetingLocation, sizeof(meetingLocation));
        std::cout << "Child 2: Meeting location received from parent: " << meetingLocation << std::endl;

        // Send new location message to parent and partner through message queue
        Message msg;
        msg.mtype = 1;  // Message type
        std::string newLocation = "Big crowd, in an hour at Trafalgar Square!";
        strcpy(msg.mtext, newLocation.c_str());
        msgsnd(msgqid, &msg, sizeof(msg.mtext), 0);
        std::cout << "Child 2: Sent new location message to parent and partner" << std::endl;

        close(pipefd[1]);  // Close write end of the pipe

        exit(0);
    } else {
        // Parent (Teacher)
        close(pipefd[1]);  // Close write end of the pipe

        // Wait for both children to be ready
        char signal1[MAX_TEXT_LENGTH];
        char signal2[MAX_TEXT_LENGTH];
        read(pipefd[0], signal1, sizeof(signal1));
        read(pipefd[0], signal2, sizeof(signal2));
        std::cout << "Parent: Children are ready for the day trip!" << std::endl;

        // Send meeting location to children through pipe
        write(pipefd[0], argv[1], strlen(argv[1]) + 1);
        std::cout << "Parent: Meeting location sent to children" << std::endl;

        // Receive new location messages from children through message queue
        Message msg;
        while (msgrcv(msgqid, &msg, sizeof(msg.mtext), 1, IPC_NOWAIT) != -1) {
            std::cout << "Parent: New location received from child: " << msg.mtext << std::endl;
        }

        close(pipefd[0]);  // Close read end of the pipe

        // Wait for children to terminate
        wait(NULL);
        wait(NULL);

        // Write daily attractions to shared memory
        semaphore_operation(semid, -1);  // Lock shared memory access

        // Write child processes' attractions to shared memory
        strcat(shm->text, " Child1: British Museum, Tower, Big Ben;");
        strcat(shm->text, " Child2: Westminster, London Eye, Soho;");

        semaphore_operation(semid, 1);  // Unlock shared memory access

        // Print daily attractions from shared memory
        std::cout << "Parent: Daily attractions: " << shm->text << std::endl;

        // Detach and remove shared memory
        shmdt(shm);
        shmctl(shmid, IPC_RMID, NULL);
        
        // Delete the semaphore
        semaphore_delete(semid);

        exit(0);
    }
}

return 0;

}