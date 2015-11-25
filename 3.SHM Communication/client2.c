#include <stdlib.h> 
#include <stdio.h>  
#include <unistd.h>  
#include <string.h>
#include <sys/shm.h>
#include <sys/ipc.h>  

#define PATH ""
#define SIZE 0
#define ID 0
int main()
{
	char * shmAddr;
	char * dataAddr = "Hello";
	int key = ftok(PATH,ID);
	int shmID = shmget(key,SIZE,0);
	shmAddr = shmat(shmID,NULL,0);
	printf("%s\n",shmAddr);
	shmdt(shmAddr);
	exit(0);
}