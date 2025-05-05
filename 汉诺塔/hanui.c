#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int count()
{
	static int num = 0;				//使用静态变量，move函数每执行一次，自增一，从而达到记录步数的效果
	num++;
	return num;
}


void move(char x, char y)
{
	printf("%d :> %c -----> %c\n\n",count(), x, y);	//打印每一步的走法
	/*count();*/
}

void Hanoi(int n, char A, char B, char C)		//函数代表汉诺塔的移动方式，n为层数，A为起始柱，B为辅助柱，C为目标柱;
{
	if (1 == n)
	{
		move(A, C);				//如果只剩一层，则将起始柱的层，移动到目标柱
	}
	else						//否则，先将除底层外所有的层，从A柱，通过C的辅助全部转移到B柱上，之后将A柱上最后一层转移到C柱，最后，将刚刚在B柱上的所有层，通过A柱的辅助，全部转移到C柱
	{
		Hanoi(n - 1, A, C, B);
		move(A,C);
		Hanoi(n - 1, B, A, C);
	}


}


int main()
{
	int n = 0;
	printf("输入N层的汉诺塔，电脑求出解法\nN = ");
	scanf("%d", &n);
	Hanoi(n, 'A', 'B', 'C');

	printf("\n*********************\n");
	printf("    结果为 %d 步数", count() - 1);
	printf("\n*********************\n");

	return 0;
}
