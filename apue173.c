//setjmp longjmp函数的使用，以及对自动变量、全局变量、寄存器变量、静态变量和易失变量的影响
//2015-05-16
//by chandler
//ps:进行优化之后，autoval和regival存储在寄存器中，因此会在longjmp函数前后值不一样
//奇怪的是，在OS X中，statval也改变了

#include <stdio.h>
#include <setjmp.h>

static void f1(int,int,int,int);
static void f2(void);

static jmp_buf jmpbuffer;  //调用longjmp函数所需参数
static int globval;        //全局参数

int main(void)
{
	int autoval;    //自动变量
	register int regival;   //寄存器变量，存储在cpu寄存器中，访问速度快
	volatile int volaval;   //这个可能就是所谓的易失变量，强制不对其进行优化，每次访问都要从内存中读取
	static int statval;     //静态变量

	globval = 1;autoval = 2;regival = 3;volaval = 4;statval = 5;

	if (setjmp(jmpbuffer) != 0) {
		printf("after longjmp:\n");
		printf("globval = %d, autoval = %d, regival = %d,"
			" volaval = %d, statval = %d\n",
			globval,autoval,regival,volaval,statval);
		exit(0);
	}

	// change variables after setjmp,but before longjmp

	globval = 95; autoval = 96; regival = 97; volaval = 98; statval = 99;

	f1(autoval,regival,volaval,statval);
	exit(0);
}

static void f1(int i,int j,int k,int l)
{
	printf("in f1(): \n");
	printf("globval = %d, autoval = %d, regival = %d,"
		" volaval = %d, statval = %d\n",
		globval,i,j,k,l);
	f2();
}

static void f2(void)
{
	longjmp(jmpbuffer,1);
}

