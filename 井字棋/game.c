#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "game.h"
#include <stdlib.h>
#include <Windows.h>

void menu() {
	printf("*************************\n");
	printf("********  1.PLAY  *******\n");
	printf("********  0.EXIT  *******\n");
	printf("*************************\n");
}

void print_Board(char board[ROW][COL])
{
	int i = 0;
	int j = 0;
	for (i = 0;i < ROW;i++)
	{
		for (j = 0;j < COL;j++)
		{
			printf(" %c ",board[i][j]);
			if (j < COL - 1)
			{
				printf("|");
			}

		}
		printf("\n");
		if (i < ROW - 1)
		{
			int a = 0;
			for (a = 0;a < COL;a++)
			{
				printf("---");
				if (a < COL - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}


	}


}

void init_Board(char board[ROW][COL]) {
	int i = 0;
	int j = 0;
	for (i = 0;i < ROW;i++)
	{
		for (j = 0;j < COL;j++)
		{
			board[i][j] = ' ';
		}
	}
}

void game(char board[ROW][COL])
{
	//printf("��ʼ��Ϸ");
	system("cls");
	init_Board(board);
	print_Board(board);
	
	LOOP{
		

		pla_rd(board);
		system("cls");

		print_Board(board);
		if (check(board, 'P') == 0)
		{
			Sleep(2500);
			system("cls");

			return;
		}
		else if (check(board, 'P') == 2)
		{
			printf("�޴�����,ƽ��\n");

			Sleep(2500);
			system("cls");


			return;
		}
		
		

		cmp_rd(board);
		system("cls");
		print_Board(board);
		if (check(board, 'C') == 0)
		{
			Sleep(2500);
			system("cls");


			return;
		}
		else if (check(board, 'C') == 2)
		{
			printf("�޴�����,ƽ��\n");
			Sleep(2500);
			system("cls");


			return;
		}
		
	}

	

}

void pla_rd(char board[ROW][COL])
{
	int x, y;
	int flag = 0;
	
	do {
		printf("�������������:>");
		scanf("%d %d", &x, &y);
		if (x > 3 || y > 3 || x < 1 || y < 1)
		{
			printf("������Χ����\n");
			flag = 0;
		}
		else
		{
			if (board[3 - y][x - 1] == ' ')
			{
				board[3 - y][x - 1] = '*';
				flag = 1;
			}
			else
			{
				printf("�ø���û�п�λ\n");
				flag = 0;
			}
		}
	} while (!flag);
}
void cmp_rd(char board[ROW][COL])
{
	int x, y;
	int flag = 0;
	printf("������������:>");
	do {
		
		x = rand() % 3 + 1;
		y = rand() % 3 + 1;

		if (board[3 - y][x - 1] == ' ')
		{
			board[3 - y][x - 1] = '#';
			flag = 1;
		}
		else
		{
			flag = 0;
		}
		
	} while (!flag);

	printf("%d %d\n", x, y);
}

int check(char board[ROW][COL],char class)
{
	if (class == 'P')
	{
		int i = 0;
		for (i = 0;i < ROW;i++)
		{
			if ((board[i][0] == '*') && (board[i][1] == '*') && (board[i][2] == '*'))
			{
				printf("\n���P1��ʤ\n");
				return 0;
			}

			if ((board[0][i] == '*') && (board[1][i] == '*') && (board[2][i] == '*'))
			{
				printf("\n���P1��ʤ\n");
				return 0;
			}
		}

		if ((board[0][0] == '*') && (board[1][1] == '*') && (board[2][2] == '*'))
		{
			printf("\n���P1��ʤ\n");
			return 0;
		}
		if ((board[0][2] == '*') && (board[1][1] == '*') && (board[2][0] == '*'))
		{
			printf("\n���P1��ʤ\n");
			return 0;
		}
	}
	if (class == 'C')
	{
		int i = 0;
		for (i = 0;i < ROW;i++)
		{
			if ((board[i][0] == '#') && (board[i][1] == '#') && (board[i][2] == '#'))
			{
				printf("\n���Ի�ʤ\n");
				return 0;
			}

			if ((board[0][i] == '#') && (board[1][i] == '#') && (board[2][i] == '#'))
			{
				printf("\n���Ի�ʤ\n");
				return 0;
			}
		}
		if ((board[0][0] == '#') && (board[1][1] == '#') && (board[2][2] == '#'))
		{
			printf("\n���Ի�ʤ\n");
			return 0;
		}
		if ((board[2][0] == '#') && (board[1][1] == '#') && (board[0][2] == '#'))
		{
			printf("\n���Ի�ʤ\n");
			return 0;
		}
	}

	int i, j;
	int flag = 0;
	for (i = 0;i < ROW;i++)
	{
		for (j = 0;j < COL;j++)
		{
			if (board[i][j] == ' ')
			{
				flag = 1;
				return 1;
			}
		}

	}
	if (flag == 0)
		return 2;
}