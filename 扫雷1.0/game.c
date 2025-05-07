#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"


void menu()
{
	printf("  ********************\n");
	printf("  *****  1.PLAY  *****\n");
	printf("  *****  0.EXIT  *****\n");
	printf("  ********************\n");
	
}

void print_bd(char bd[ROW1][COL1])
{
	int i = 0;
	int j = 0;
	printf("\n************扫雷游戏************\n\n");
	for (i = 0;i <= ROW;i++)
	{
		printf("  %d ", i);
		for (j = 1;j <= COL;j++)
		{
			if (0 == i)
				printf("%d ", j);
			else
				printf("%c ", bd[i][j]);

		}
		printf("\n");
	}
	printf("\n************扫雷游戏************\n");

}


void bd_INIT(char board[ROW1][COL1], char set)
{
	int i = 0;
	for (i = 0;i < ROW1;i++)
	{
		int j = 0;
		for (j = 0;j < COL1;j++)
		{
			board[i][j] = set;
		}

	}

}

void boom_INIT(char bd[ROW1][COL1])
{
	int count = 0;
	int row = 0;
	int col = 0;
	while (count < MODE)
	{
		row = rand() % 9 + 1;
		col = rand() % 9 + 1;
		if (bd[row][col] == '0')
		{
			bd[row][col] = '1';
			count++;
		}
	}
}



void gamestart(char bd_1[ROW1][COL1],char bd_2[ROW1][COL1])
{
	bd_INIT(bd_1,'0');
	bd_INIT(bd_2,UNCHK);
	boom_INIT(bd_1);

	print_bd(bd_1);
	print_bd(bd_2);

	find_boom(bd_1, bd_2, ROW, COL);
	
}

void find_boom(char bd_1[ROW1][COL1], char bd_2[ROW1][COL1], int row, int col)
{
	int x, y;
	int score=0;
	LOOP
	{
		if (score == SCORE_WIN)
		{
			break;
		}
		printf("请输入坐标（行 列）:>");
		scanf("%d %d", &x, &y);
		if (x<1 || y<1 || x>row || y>col)
		{
		printf("输入的坐标非法！！\n");
		continue;
		}
		else
		{
			if (bd_1[x][y] == '1')
			{
				printf("游戏结束\n");
				int i = 0;
				for (i = 1;i <= row;i++)
				{
					int j = 0;
					for (j = 1;j <= col;j++)
					{
						if (bd_1[i][j] == '1')
						{
							bd_1[i][j] = '*';

						}
						else
						{
							bd_1[i][j] = '.';
						}
					}

				}
				print_bd(bd_1);
				printf("\nSCORE ---->  %d\n", score);
				break;
			}
			else if(bd_2[x][y] == UNCHK)
			{
				int count = get_boom_count(bd_1,x,y);
				bd_2[x][y] = count + '0';
				score++;
				print_bd(bd_2);
				
			}
			else
			{
				printf("该坐标已经检查过\n");
			}


		}


	}
	printf("!!!!!WIN!!!!!\n");
	{
		int i = 0;
		for (i = 1;i <= row;i++)
		{
			int j = 0;
			for (j = 1;j <= col;j++)
			{
				if (bd_1[i][j] == '1')
				{
					bd_1[i][j] = '*';

				}
				else
				{
					bd_1[i][j] = '.';
				}
			}

		}
		print_bd(bd_1);
		printf("\nSCORE ---->  %d\n", score);
	}
}

int get_boom_count(char bd_1[ROW1][COL1], int x, int y)
{
	//static int table[ROW][COL] = { 0 };
	int count = 0;
	int i, j;
	for (i = -1;i <= 1;i++)
	{
		for (j = -1;j <= 1;j++)
		{
			if (bd_1[x + i][y + j] == '1')
			{
				count++;
			}

		}

	}
	return count;
}