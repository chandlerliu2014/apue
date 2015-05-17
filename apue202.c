//exec函数实例
//2015-05-17
//by chandler

#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char *env_init[] = { "USER=unknown","PATH=/tmp",NULL};

int main(void)
{
	pid_t pid;

	if ((pid = fork()) < 0) {
		printf("fork error\n");
	} else if (pid == 0) {
		//传入路径，记得该路径位存放echoall程序的路径，另外，execle函数需要传入环境变量，这里是env_init
		if (execle("/Users/chandler/apue/echoall","echoall","myargl","MY ARG2",(char *)0,env_init) < 0)  
		printf("execle error\n");
	}

	if (waitpid(pid,NULL,0) < 0)
		printf("wait error\n");
	
	if ((pid = fork()) < 0) {
		printf("fork error\n");
	} else if (pid == 0) {
		if (execlp("echoall","echoall","only 1 arg",(char *)0) < 0) //将echoall所在路径加入PATH中，execlp函数不需要传入环境变量，默认传入调用者的环境
			printf("execlp error\n");
	}

	exit(0);
}
