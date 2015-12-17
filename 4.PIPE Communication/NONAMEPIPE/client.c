#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 60

int main()
{
	int n;
	int fd[2];
	pid_t pid;
	char buf[BUFFER_SIZE];
	if(pipe(fd)==-1)
	{
		printf("error in create pipe\n");
		exit(1);
	}
	if((pid=fork())<0)
	{
		printf("error in fork a sub process\n");
	}
	if(pid>0)
	{
		close(fd[0]);
		write(fd[1],"Welcome!\n",9);
	}
	else
	{
		close(fd[1]);
		read(fd[0],buf,BUFFER_SIZE);
		printf("%s\n",buf);
	}
	return 0;
}