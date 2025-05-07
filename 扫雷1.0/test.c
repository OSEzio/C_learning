#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"


int main()
{
	srand((unsigned)time(NULL));

	char board_1[ROW1][COL1] = { '0' };
	char board_2[ROW1][COL1] = { '*' };
	int flag = 0;
	do
	{
		menu();
		scanf("%d", &flag);
		switch (flag)
		{
		case 1:
			gamestart(board_1, board_2);
			break;
		case 0:
			printf("正在退出。。。");
			break;
		default:
			printf("错误选项，请重新输入\n\n");
			break;


		}



	} while (flag);



	return 0;
}