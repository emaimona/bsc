#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>

#define MEMSIZE 1024

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

int main (int argc,char* argv[]) {

    pid_t child;
    key_t key;
    int sh_mem_id,semid;
    char *s;

    key=ftok(argv[0],1);
    sh_mem_id=shmget(key,MEMSIZE,IPC_CREAT|S_IRUSR|S_IWUSR);
    s = shmat(sh_mem_id,NULL,0);
//
    semid = semaphore_create(argv[0],0); // sem state is down!!!
//
    child = fork();
    if(child>0){    
    
       char buffer[] = "I like Illes (Pop group:)!\n";
	printf("Parent starts, writes the text into shared memory %s\n",buffer);
       sleep(4);            // child waits during sleep
       strcpy(s,buffer);
       printf("Parent:, semaphore up!\n");
       semaphore_operation(semid,1); // Up
       shmdt(s);	// release shared memory
       wait(NULL);       
       semaphore_delete(semid);
       shmctl(sh_mem_id,IPC_RMID,NULL);
    } else if ( child == 0 ) {	
    
       // critical section
       printf("Child: try to close semaphore !\n");
       semaphore_operation(semid,-1); // down, wait if necessary
       printf("Child: result: %s",s);  
       semaphore_operation(semid,1); // up      
       // end of critical section  
       shmdt(s);
    }

   return 0;
}


