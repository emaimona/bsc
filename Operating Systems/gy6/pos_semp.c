//*********************************
// Compile with -pthread 
//*****************************


#include <sys/ipc.h>
#include <sys/shm.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>

#define MEMSIZE 1024

sem_t* semaphore_create(char*name,int semaphore_value)
{
    sem_t *semid=sem_open(name,O_CREAT,S_IRUSR|S_IWUSR,semaphore_value );
	if (semid==SEM_FAILED)
	perror("sem_open");
       
    return semid;
}

void semaphore_delete(char* name)
{
      sem_unlink(name);
}

int main (int argc,char* argv[]) {

    pid_t child;
    key_t key;
    int sh_mem_id;
    sem_t* semid;
    char *s;
    char* sem_name="/apple";

    key=ftok(argv[0],1);
    sh_mem_id=shmget(key,MEMSIZE,IPC_CREAT|S_IRUSR|S_IWUSR);
    s = shmat(sh_mem_id,NULL,0);

    semid = semaphore_create(sem_name,0);

    child = fork();
    if(child>0)	// parent
	{    
       	char buffer[] = "I like Illes pop group!\n";
	printf("Parent starts and writes into the shared memory: %s\n",buffer);
       	sleep(4); // wait for a few seconds             
       	strcpy(s,buffer);	// copy data to shared memory
	printf("Parent:, semaphore up!\n");
       	sem_post(semid);	// semaphore up
	shmdt(s);	// release shared memory	
       	wait(NULL);       
       	semaphore_delete(sem_name);
	shmctl(sh_mem_id,IPC_RMID,NULL);
    	} 
	else 
	if ( child == 0 ) //child
		{	
       		/*  critical section   */
		printf("Child tries to close semaphore!\n");
       		sem_wait(semid);	// semaphore down
       		printf("Child: the result is: %s",s);  
       		sem_post(semid);      
       		/*  end of critical section  */  	  
       		shmdt(s);
    		}

   return 0;
}


