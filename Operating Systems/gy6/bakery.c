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
// posix semaphor requires to link: cc -pthread bakery.c
#define MEMSIZE 1024
int *s;
sem_t* free_;  //free is a C function
sem_t* empty;
sem_t* full;
//
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
void baker()
{
	long int li;
	while(s[1])
	{
	sem_wait(empty);
	sem_wait(free_);
	s[0]+=1;
	printf("Baker: the number of breads: %i\n",s[0]);
	sem_post(free_);
	sem_post(full);
	li=random();
	usleep(li%100000);	// wait 0-100000 microsecond
//	printf("Baker: I made a bread!\n");
	}
}
void customer()
{
	long int li;
	while(s[1])
	{
	sem_wait(full);
	sem_wait(free_);
	s[0]-=1;
	printf("Customer, The number of breads: %i\n",s[0]);
	sem_post(free_);
	sem_post(empty);
	li=random();
	usleep(li%100000);	// wait for a while, 0-100000 microsecond
//	printf("Customer: I ate 1 bread!\n");
	}
}
int main (int argc,char* argv[]) {

    pid_t baker_id,customer_id;
    key_t key;
    int sh_mem_id, N=10;
    char* sem_name1="one";
    char* sem_name2="two";
    char* sem_name3="three";
//
    key=ftok(argv[0],1);
    sh_mem_id=shmget(key,MEMSIZE,IPC_CREAT|S_IRUSR|S_IWUSR);
    s = (int*)shmat(sh_mem_id,NULL,0);
    s[0]=0; 	// the number of breads on the shelf
    s[1]=1;	// the process may start
    free_ = semaphore_create(sem_name1,1);
    empty = semaphore_create(sem_name2,N);	// shelf is empty
    full = semaphore_create(sem_name3,0);
    customer_id = fork();
    if(customer_id>0)
    {    
  	baker_id=fork();
	if (baker_id>0)
	{  
       char buffer[100];
	printf("Parent starts! \n");
	printf("Press down something!\n");
	scanf("%s",&buffer);
	s[1]=0;	// chid's end
	wait(NULL);
	wait(NULL);
	shmdt(s);
	shmctl(sh_mem_id,IPC_RMID,NULL);
       semaphore_delete(sem_name1);
       semaphore_delete(sem_name2);
       semaphore_delete(sem_name3);
	}
	else // baker
	{
		srandom(1000);	// init random generator in baker
		printf("Baker starts!\n");
		baker();
		printf("Baker ended!\n");
		shmdt(s);
	}
    } 
    else {	// customer
		//srandom(10);	// init random generator in customer
		srandom(time(NULL));
		printf("Customer starts!\n");
       		customer();
       		printf("Customer ended\n");  
                shmdt(s);
    }

   return 0;
}


