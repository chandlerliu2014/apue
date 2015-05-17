//关于僵死进程
//2015-05-17
//by chandler
//ps:在ubuntu虚拟机上运行，得到的父进程ID为1980，用ps一看，还真是init进程，神奇

#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(void)
{
	pid_t pid;
	printf("parent ID:%ld\n",(long)getpid());
	if ((pid = fork()) < 0) {
		printf("fork error\n");
	} else if (pid == 0) {   //第一个子进程
		printf("第一个子进程ID:%ld\n",(long)getpid());
		if ((pid = fork()) < 0)
			printf("fork error\n");
		else if (pid > 0)   //第一个子进程终止
			exit(0);

		sleep(2);   //第二个子进程，其父进程变为init
		printf("second child,parent pid = %ld\n",(long)getppid());
		exit(0);
	}

	if (waitpid(pid,NULL,0) != pid)
		printf("waitpid error\n");
	printf("done\n");

	exit(0);
}
