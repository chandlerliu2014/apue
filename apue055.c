//创建一个有空洞的文件
//2015-05-11
//by chandler

//ps: 运行程序之后,得到file.hole文件,用ls -l file.hole命令查看权限,与FILE_MODE对应
//od -c可查看实际存储的数据

#include <unistd.h> //write
#include <fcntl.h> //creat
#include <stdio.h>

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main()
{
	int fd;
	
	if ((fd = creat("file.hole",FILE_MODE)) < 0) {
		printf("creat error\n");
		return -1;
	}

	if (write(fd,buf1,10) != 10) {
		printf("write error\n");
		return -1;
	}

	if (lseek(fd,16384,SEEK_SET) == -1) {
		printf("lseek error\n");
		return -1;
	}

	if (write(fd,buf2,10) != 10) {
		printf("write error\n");
		return -1;
	}
	return 0;
}
