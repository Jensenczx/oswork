/*
管道为字节流，通过一个进程指向另一个进程，有匿名管道，只能够用来在父子之间进行字节流的交互
命名管道可以用来在非父子进程之间进行一个数据的交互
1.创建管道，指向目的进程，绑定本地进程
2.制定读写权限打开管道，向管道中写或者读数据
3.关闭管道，对方从管道中拿到数据
4.管道的读写都是采用阻塞机制，有两个端，一个用来读，一个用来写，读写端必须都有数据，管道是单向的传输，单方向只能以一种权限打开
5.open打开的一个管道的时候，可以为其制定是否为阻塞
*/
#include <unistd.h>  
#include <stdlib.h>  
#include <fcntl.h>  
#include <limits.h>  
#include <sys/types.h>  
#include <sys/stat.h>  
#include <stdio.h>  
#include <string.h>  

#define FIFO_NAME "/oswork/pipe/myfifo"
#define FILE_NAME "/oswork/pipe/myfile.txt" 

int main()
{
	int res;
	int pipe_id;
	char buffer[] = "Hello world";
	char data[20];
	if((fd=open(FILE_NAME,O_CREAT|O_RDWR))==-1)
        {
                printf("ERROR IN OPEN A FILE\n");
                exit(1);
        }
        if(write(fd,buffer,sizeof(buffer))==-1)
        {
                printf("ERROR IN WRITE INTO A FILE");
                exit(1);
        }
	if(access(FIFO_NAME,F_OK)==-1)
	{
		res = mkfifo(FIFO_NAME,O_WRONLY);
		if(res!=0)
		{
			printf("Error in creating fifo.\n");
			exit(1);
		}
	}
	pipe_id = open(FIFO_NAME,O_WRONLY);
	if(pipe_id!= -1)
	{
		if(read(fd,data,sizeof(buffer))==-1)
		{
			printf("ERROR IN READ A FILE\n");
			exit(1);
		}
		if(write(pipe_id,data,sizeof(data))>0)
		{
			close(fd);
			close(pipe_id);
		}else{
			printf("Error in writing.\n");
			exit(1);
		}
	}else
	{
		printf("Error in opening.\n");
		exit(1);
	}
}