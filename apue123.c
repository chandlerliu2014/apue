//输入输出IO
//2015-05-13
//by chandler

#include <stdio.h>

/*int main(void)
{
	int c;
	while ((c = getc(stdin)) != EOF)
		if (putc(c,stdout) == EOF)
			printf("output error\n");
	
	if (ferror(stdin))
		printf("input error\n");
	
	return 0;
}*/

#define MAXLINE 4096
int main(void)
{
	char buf[MAXLINE];
	
	while (fgets(buf,MAXLINE,stdin) != NULL)
		if (fputs(buf,stdout) == EOF)
			printf("output error\n");

	if (ferror(stdin))
		printf("input error\n");

	return 0;
}
