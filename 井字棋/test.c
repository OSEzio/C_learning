#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include "game.h"
#include <stdlib.h>
#include <time.h>


int main()
{
	srand((unsigned int)time(NULL));

	char board[ROW][COL] = { 0 };
	int flag = 1;
	do {
		menu();
		scanf("%d", &flag);
		switch (flag)
		{
		case 1:
			game(board);
			break;
		case 0:
			printf("结束游戏\n");
			break;
		default:
			printf("**** 输入错误，重新输入 ****\n");
			break;

		}



	} while (flag);




	return 0;
}