#include <unistd.h>  
#include <stdlib.h>  
#include <fcntl.h>  
#include <limits.h>  
#include <sys/types.h>  
#include <sys/stat.h>  
#include <stdio.h>  
#include <string.h>  

#define FIFONAME "/oswork/pipe/myfifo"
int main()
{
	char buffer[PIPE_BUF+1];
	int pipe_id;
	pipe_id = open(FIFONAME,O_RDONLY);
	if(pipe_id != -1)
	{
		read(pipe_id,buffer,PIPE_BUF);
	}else{
		printf("error in reading\n");
	}

}