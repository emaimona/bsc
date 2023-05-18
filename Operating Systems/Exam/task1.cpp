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
#define MAX_STRING_LENGTH 1024


void handle_signal(int sig) {
    // Do nothing, just catch the signal
}

struct messg { 
    long mtype;
    int mtext;
}; 

// sending a message
int send(int mqueue, int val) {
    const struct messg m = {5, val};
    int status = msgsnd(mqueue, &m, sizeof(m), 0);
    if (status < 0)
        perror("msgsnd error");
    return 0;
}

// receiving a message. 
int receive(int mqueue) {
    struct messg m;
    int status;
    status = msgrcv(mqueue, &m, sizeof(m), 5, 0);
    if (status < 0)
        perror("msgsnd error");
    else
        cout << "Parent sent summary message with count = " << m.mtext << endl;
    return 0;
}

int main(int argc, char* argv[]) {

    if (argc != 3) {
        cout << "Usage: a.out \"Oxford Circus\" 17" << endl;
        exit(1);
    }   

    string message = argv[1];
    message += " ";
    message += argv[2];

    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = handle_signal;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
 
    int fd[2]; // file descriptors for the pipe
    pipe(fd);

    int messg, status; 
    key_t key = ftok(argv[0],1);
    printf ("\nThe key: %d\n",key);
    messg = msgget(key, 0600 | IPC_CREAT); 
    if (messg < 0) { 
        perror("msgget error 1"); 
        exit(EXIT_FAILURE); 
    } 
    pid_t child;
    
    cout << "After breakfast, they are discussing the plan for the day's trip." << endl;

    child = fork();
    if (child < 0) {
        perror("Error fork 1!");
        exit(EXIT_FAILURE);
    } 
       
    // child 1 
    if (child == 0) {
        
        cout << "Student 1 sends a signal to the instructor." << endl;
        kill(getppid(), SIGUSR1);

        char buffer[MAX_STRING_LENGTH];

        close(fd[1]);  // Usually, we close the unused write end
        read(fd[0], buffer, MAX_STRING_LENGTH); // reading max 100 chars
        printf("Student 1 reads the message: %s\n", buffer);
        printf("\n");
        close(fd[0]);

        // One student arrives at the meeting place early and sees that there is a protest, a very large crowd.
        // Therefore, he indicates a new location and sends it to both the partner and the instructor using a message queue.
        int newLocationQueue;
        key_t newLocationKey = ftok(argv[0], 'D');
        if ((newLocationQueue = msgget(newLocationKey, 0600 | IPC_CREAT)) < 0) {
    perror("msgget error for new location");
    exit(EXIT_FAILURE);
}

// Send the new location message
string newLocationMessage = "Big crowd, in an hour at Trafalgar Square!";
send(newLocationQueue, newLocationMessage.length());
msgsnd(newLocationQueue, &newLocationMessage, newLocationMessage.length(), 0);

exit(0);

return 0;
} else {
    pause();        
    cout << "Instructor sends via a pipe where and when they will meet at the end of the day!" << endl;
    close(fd[0]); 
    write(fd[1], message.data(), strlen(message.data()) + 1); 
    close(fd[1]); 
    wait(NULL);
    pid_t child2 = fork();
    if (child2 < 0) {
        perror("Error fork 2!");
        exit(EXIT_FAILURE);
    }

    if (child2 == 0) {
        cout << "\nStudent 2 sends a signal to the instructor." << endl;
        kill(getppid(), SIGUSR2);


        char buffer[MAX_STRING_LENGTH];
        sleep(5);
        // close(fd[1]);  // Usually, we close the unused write end
        read(fd[0], buffer, MAX_STRING_LENGTH); // reading max 100 chars
        printf("Student 2 reads the message: %s\n", buffer);
        printf("\n");
        close(fd[0]);
        exit(0);
    } else {

        pause();
        cout << "Instructor sends via a pipe where and when they will meet at the end of the day!" << endl;
        close(fd[0]); 
        write(fd[1], message.data(), strlen(message.data()) + 1); 
        close(fd[1]); 


        wait(NULL);
    }
    // fflush(NULL); 	// flushes all write buffers (not necessary)

    exit(0);
}

return 0;
}