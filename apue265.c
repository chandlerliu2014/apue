// SIGCLD信号
//2015-06-17
// by chandler

#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static void sig_cld(int);

int main()
{
	pid_t pid;

	if (signal(SIGCHLD,sig_cld) == SIG_ERR)
		printf("signal error\n");
	if ((pid = fork()) < 0) {
		printf("fork error\n");
	} else if (pid == 0) {
		sleep(2);
		_exit(0);
	}

	pause();
	exit(0);
}


static void sig_cld(int signo)
{
	pid_t pid;
	int status;
	
	printf("SIGCLD received\n");

	if (signal(SIGCHLD,sig_cld) == SIG_ERR)
		printf("signal error\n");
	
	if ((pid = wait(&status)) < 0)
		printf("wait error\n");

	printf("pid = %d\n",pid);
}

