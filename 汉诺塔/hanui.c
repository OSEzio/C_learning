#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int count()
{
	static int num = 0;
	num++;
	return num;
}


void move(char x, char y)
{
	printf("%d :> %c -----> %c\n\n",count(), x, y);
	/*count();*/
}

void Hanoi(int n, char A, char B, char C)
{
	if (1 == n)
	{
		move(A, C);
	}
	else
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