#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"


void menu()				//菜单
{
	printf("  ********************\n");
	printf("  *****  1.PLAY  *****\n");
	printf("  *****  0.EXIT  *****\n");
	printf("  ********************\n");
	
}

void print_bd(char bd[ROW1][COL1])			//打印
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


void bd_INIT(char board[ROW1][COL1], char set)		//棋盘初始化，目标棋盘，以及需要初始化的样式
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

void boom_INIT(char bd[ROW1][COL1])//填充炸弹，
{
	int count = 0;
	int row = 0;
	int col = 0;
	while (count < MODE)
	{
		row = rand() % ROW + 1;
		col = rand() % COL + 1;
		if (bd[row][col] == '0')		//1表示有炸弹，0表示安全
		{
			bd[row][col] = '1';
			count++;
		}
	}
}



void gamestart(char bd_1[ROW1][COL1],char bd_2[ROW1][COL1])//游戏进行的步骤，
{
	bd_INIT(bd_1,'0');			//初始化棋盘1（棋盘1用于填充炸弹，玩家不可见
	bd_INIT(bd_2,UNCHK);		//初始化棋盘2（棋盘2用于显示界面，玩家可见
	boom_INIT(bd_1);			//在棋盘1上填充炸弹
	system("cls");
	//print_bd(bd_1);			//该代码用于显示棋盘，调试用，正常游玩时需要被注释掉
	print_bd(bd_2);				//显示棋盘2，展示给玩家

	find_boom(bd_1, bd_2, ROW, COL);		//开始筛查炸弹
	
}

void find_boom(char bd_1[ROW1][COL1], char bd_2[ROW1][COL1], int row, int col)
{
	int x, y;			//用于填入坐标
	int flag = 0;		//用于表示标记还是选取，1为选取xy坐标，2表示在xy坐标上标记，插旗
	int score=0;		//分数
	int* score_p = &score;	//需要在子函数递归中实现分数增加的效果，所以此处定义一个score的指针
	LOOP
	{
		if (score == SCORE_WIN)		//首先判断，如果目前分数等于获胜时的分数，则结束
		{
			printf("!!!!!WIN!!!!!\n");
			{
				int i = 0;
				for (i = 1;i <= row;i++)		//为了凸显出雷的位置，将雷表示为*，其余位置表示为.
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
				printf("\nSCORE ---->  %d\n", score);		//输出此时分数
			}
			break;
		}
		printf("请输入坐标（行 列）以及操作（1.检查  2.插旗标记）:>");
		scanf("%d %d %d", &x, &y,&flag);
		if (x<1 || y<1 || x>row || y>col)	//首先判断坐标是否越界
		{
		printf("输入的坐标非法！！\n");
		continue;
		}
		else
		{
			if ((bd_1[x][y] == '1') && bd_2[x][y] != FLAG_CHAR && flag != 2)	//如果查询的坐标为雷，并且未标记，且此时不是标记状态，则游戏结束
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
			else if ((bd_2[x][y] == UNCHK) && (flag == 1))//如果选择的坐标未经筛查过，并且此时是筛查状态
			{
				
				system("cls");
				func(bd_1, bd_2, x, y, score_p);			//则进行筛查，之后打印
				print_bd(bd_2);
				
			}
			else if(flag == 2)						//如果此时是标记状态，
			{
				if (bd_2[x][y] == UNCHK)			//如果对应坐标是常规状态，则标记
				{
					bd_2[x][y] = FLAG_CHAR;
					system("cls");

					print_bd(bd_2);
				}
				else if (bd_2[x][y] == FLAG_CHAR)		//如果已经是标记状态，则移除标记
				{
					bd_2[x][y] = UNCHK;
					system("cls");

					print_bd(bd_2);
				}
				else								//既不是标记也不是常规状态，说明该位置已经被筛查过，
				{
					printf("该坐标无法标记\n");
				}
				
			}
			else									//说明该位置已经被筛查过，或者已经被标记
			{
				printf("该坐标无法检查\n");
			}


		}


	}

	
}

int get_boom_count(char bd_1[ROW1][COL1], int x, int y)//对xy坐标周围8个格子进行筛查，从而确定xy坐标应该填入数字几
{
	
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
void func(char bd_1[ROW1][COL1], char bd_2[ROW1][COL1], int x, int y, int* score_p)
{
	int count = get_boom_count(bd_1, x, y);

	if (count == 0)		//如果xy坐标周围没有雷，则向周围扩展，继续筛查周围没有被筛查的格子，直到筛查到周围8个方向存在雷的格子，递归停止
	{
		*score_p = *score_p + 1;//score+1，用于判断游戏结束
		bd_2[x][y] = BOOM_0;//如果周围没有雷，填入空格
		
		if (x - 1 >= 1 && x - 1 <= ROW && y - 1 >= 1 && y - 1 <= COL && bd_2[x - 1][y - 1] == UNCHK)
			func(bd_1, bd_2, x - 1, y - 1, score_p);
		if (x - 1 >= 1 && x - 1 <= ROW && y  >= 1 && y  <= COL && bd_2[x - 1][y] == UNCHK)
			func(bd_1, bd_2, x - 1, y , score_p);
		if (x - 1 >= 1 && x - 1 <= ROW && y + 1 >= 1 && y + 1 <= COL && bd_2[x - 1][y + 1] == UNCHK)
			func(bd_1, bd_2, x - 1, y + 1, score_p);

		if (x + 1 >= 1 && x + 1 <= ROW && y - 1 >= 1 && y - 1 <= COL && bd_2[x + 1][y - 1] == UNCHK)
			func(bd_1, bd_2, x + 1, y - 1, score_p);
		if (x + 1 >= 1 && x + 1 <= ROW && y >= 1 && y <= COL && bd_2[x + 1][y] == UNCHK)
			func(bd_1, bd_2, x + 1, y, score_p);
		if (x + 1 >= 1 && x + 1 <= ROW && y + 1 >= 1 && y + 1 <= COL && bd_2[x + 1][y + 1] == UNCHK)
			func(bd_1, bd_2, x + 1, y + 1, score_p);

		if (x >= 1 && x <= ROW && y - 1 >= 1 && y - 1 <= COL && bd_2[x][y - 1] == UNCHK)
			func(bd_1, bd_2, x, y - 1, score_p);
		if (x >= 1 && x <= ROW && y + 1 >= 1 && y + 1 <= COL && bd_2[x][y + 1] == UNCHK)
			func(bd_1, bd_2, x, y + 1, score_p);


	}
	else
	{
		*score_p = *score_p + 1;//score+1，用于判断游戏结束
		bd_2[x][y] = count + '0';//填入周围对应数量的雷数
		return;
	}
}