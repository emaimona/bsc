#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <sys/ipc.h> 
#include <sys/msg.h> 
#include <sys/types.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <sys/wait.h> 

#define MSG_SIZE 256

void handle_signal(int sig) {
    // Do nothing, just catch the signal
}

struct messg { 
     long mtype;//this is a free value e.g for the address of the message
     int mtext; //this is the message itself
}; 

// sendig a message
int send( int mqueue, int val ) 
{ 
     const struct messg m = { 5, val }; 
     int status; 
     
     status = msgsnd( mqueue, &m, sizeof(int) , 0 ); 
	// a 3rd parameter may be : sizeof(m.mtext)
     	// a 4th parameter may be  IPC_NOWAIT, equivalent with  0-val 
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
          printf( "The code of the message is : %ld, text is:  %d\n", m.mtype, m.mtext ); 
     return 0; 
} 


int main(int argc, char *argv[])
{
    int fd[2];
    char msg1[] = "Hello from child!";
    char msg2[] = "Hello from parent!";
    char buf[MSG_SIZE];


     int messg, status; 
     key_t key; 
     
     // msgget needs a key, created by  ftok  
     //. 
     key = ftok("/gau5oe",1); 
     printf ("The key: %d\n",key);
     messg = msgget( key, 0600 | IPC_CREAT ); 

     if ( messg < 0 ) { 
          perror("msgget error 1"); 
          return 1; 
     } 

    pid_t pid;

    if (pipe(fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // Child process
        close(fd[0]); // Close read end of pipe

        // Write message 1 to pipe
        write(fd[1], msg1, strlen(msg1) + 1);

        // Set up signal handler for SIGUSR1
        struct sigaction sa;
        memset(&sa, 0, sizeof(sa));
        sa.sa_handler = handle_signal;
        sigaction(SIGUSR1, &sa, NULL);

        // Wait for signal to write message 2 to pipe
        pause();
        receive( messg ); 

        // Write message 2 to pipe
        write(fd[1], msg2, strlen(msg2) + 1);

        // Close write end of pipe
        close(fd[1]);
        receive( messg ); 
        exit(EXIT_SUCCESS);
    } else { // Parent process
        close(fd[1]); // Close write end of pipe

        // Read message 1 from pipe
        read(fd[0], buf, MSG_SIZE);
        printf("Child says: %s\n", buf);

        send( messg, 7 ); 


        kill(pid, SIGUSR1);


        read(fd[0], buf, MSG_SIZE);
        printf("Child says: %s\n", buf);

        // Close read end of pipe
        close(fd[0]);

        send( messg, 8);  
        
          wait(NULL);
          status = msgctl( messg, IPC_RMID, NULL ); 
          if ( status < 0 ) 
               perror("msgctl error"); 

        exit(EXIT_SUCCESS);
    }
}
