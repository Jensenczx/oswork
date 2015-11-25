/*Linux间进程通信的方式种类，各种通信方式的特点
1.共享存储区
2.管道通信系统
3.消息传递系统
4.Socket
*/

/*共享存储区：之前数据的交互经过内核
1.创建进程
2.创建共享存储区,shmget()
3.向共享区写数据，读数据,bind the process by shmat(),shmdt()
4.为数据实现同步*/

/*
shmget(p1,p2,p3)
第一个参数是我们的进程的键值，通过ftok通过文件的目录名称和进程id生成一个键值,还可以通过IPC_PRIVACE
得到，得到只能够用于亲子进程通信，而且要在子进程创建之前进行创建。
第二个参数是指定内存的大小
第三个参数是我们声明的一些权限
*/

/*
shmat(p1,p2,p3)
第一个参数：我们创建的共享内存的标示符
第二个参数：共享区域在当前进程中的起始地址，设为null，系统自己分配
第三个参数：对绑定的内存区域的读写操作
*/

/*
strcpy(desitnation address,source address)
*/

/*
shmdt(shm address)断开与当前区域，删除该共享区域，如果不调用这个函数的话，
每个共享区域设置有一个计数器，当所有和该进程连接的进程断掉之后，该区域就会被删除掉。
*/
#include <stdlib.h>   
#include <sys/shm.h>
#include <sys/ipc.h>  
#include <unistd.h>  
#include <string.h>

#define PATH ""
#define SIZE 512
#define ID 0
int main()
{
	char * shmAddr;
	char * dataAddr = "Hello";
	int key = ftok(PATH,ID);
	int shmID = shmget(key,SIZE,IPC_CREAT);
	shmAddr = shmat(shmID,NULL,0);
	strcpy(shmAddr,dataAddr);
	shmdt(shmAddr);
	exit(0);
}
