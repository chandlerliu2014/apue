//打开一个文件,然后unlink它
//2015-05-13
//by chandler

//可以再试试link函数
//linux中调用link函数创建一个指向目录文件的硬链接失败

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

/*int main(void)
{
	if (open("tempfile",O_RDWR) < 0)
		printf("open error\n");
	if (unlink("tempfile") < 0)
		printf("unlink error\n");
	printf("file unlinked\n");
	sleep(15);
	printf("done\n");
	return 0;
}*/

int main(void)
{
	char existfile[] = "/tmp/myfile";
	char filelink[] = "/tmp/filelink";

	char existdir[] = "/tmp/mydir";
	char dirlink[] = "/tmp/dirlink";

	if (link(existfile,filelink) < 0)
		printf("link error for file:%s\n",filelink);
	
	if (link(existdir,dirlink) < 0)
		printf("link error for dir:%s\n",dirlink);

	return 0;
}
