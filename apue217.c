// 进程会计
// 2015-05-31
// by chandler

// ps: 心情不好的时候，就该敲敲代码
// 之前华为的比赛做得很漫不经心，但确实也经历了一番各种煎熬、灰心丧气还有希望，还有兴奋，最近又开始倒腾ios编程，希望真的能坚持下去
// hi apue,好久不见了

#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;

	if ((pid = fork()) < 0)
		printf("fork error\n");

	else if (pid != 0) {
		sleep(2);
		exit(2);       // terminate with exit status 2
	}

	if ((pid = fork()) < 0)
		printf("fork error\n");
	else if (pid != 0) {
		sleep(4);
		abort();      // terminate with core dump
	}

	if ((pid = fork()) < 0) 
		printf("fork error\n");
	else if (pid != 0) {
		execl("/bin/dd","dd","if=/etc/passwd","of=/dev/null",NULL);
		exit(7);
	}

	if ((pid = fork()) < 0)
		printf("fork error\n");
	else if (pid != 0) {
		sleep(8);
		exit(0);
	}

	sleep(6);
	kill(getpid(),SIGKILL);
	exit(6);
}
