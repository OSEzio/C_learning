#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"


void menu()				//�˵�
{
	printf("  ********************\n");
	printf("  *****  1.PLAY  *****\n");
	printf("  *****  0.EXIT  *****\n");
	printf("  ********************\n");
	
}

void print_bd(char bd[ROW1][COL1])			//��ӡ
{
	int i = 0;
	int j = 0;
	printf("\n************ɨ����Ϸ************\n\n");
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
	printf("\n************ɨ����Ϸ************\n");

}


void bd_INIT(char board[ROW1][COL1], char set)		//���̳�ʼ����Ŀ�����̣��Լ���Ҫ��ʼ������ʽ
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

void boom_INIT(char bd[ROW1][COL1])//���ը����
{
	int count = 0;
	int row = 0;
	int col = 0;
	while (count < MODE)
	{
		row = rand() % ROW + 1;
		col = rand() % COL + 1;
		if (bd[row][col] == '0')		//1��ʾ��ը����0��ʾ��ȫ
		{
			bd[row][col] = '1';
			count++;
		}
	}
}



void gamestart(char bd_1[ROW1][COL1],char bd_2[ROW1][COL1])//��Ϸ���еĲ��裬
{
	bd_INIT(bd_1,'0');			//��ʼ������1������1�������ը������Ҳ��ɼ�
	bd_INIT(bd_2,UNCHK);		//��ʼ������2������2������ʾ���棬��ҿɼ�
	boom_INIT(bd_1);			//������1�����ը��
	system("cls");
	//print_bd(bd_1);			//�ô���������ʾ���̣������ã���������ʱ��Ҫ��ע�͵�
	print_bd(bd_2);				//��ʾ����2��չʾ�����

	find_boom(bd_1, bd_2, ROW, COL);		//��ʼɸ��ը��
	
}

void find_boom(char bd_1[ROW1][COL1], char bd_2[ROW1][COL1], int row, int col)
{
	int x, y;			//������������
	int flag = 0;		//���ڱ�ʾ��ǻ���ѡȡ��1Ϊѡȡxy���꣬2��ʾ��xy�����ϱ�ǣ�����
	int score=0;		//����
	int* score_p = &score;	//��Ҫ���Ӻ����ݹ���ʵ�ַ������ӵ�Ч�������Դ˴�����һ��score��ָ��
	LOOP
	{
		if (score == SCORE_WIN)		//�����жϣ����Ŀǰ�������ڻ�ʤʱ�ķ����������
		{
			printf("!!!!!WIN!!!!!\n");
			{
				int i = 0;
				for (i = 1;i <= row;i++)		//Ϊ��͹�Գ��׵�λ�ã����ױ�ʾΪ*������λ�ñ�ʾΪ.
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
				printf("\nSCORE ---->  %d\n", score);		//�����ʱ����
			}
			break;
		}
		printf("���������꣨�� �У��Լ�������1.���  2.�����ǣ�:>");
		scanf("%d %d %d", &x, &y,&flag);
		if (x<1 || y<1 || x>row || y>col)	//�����ж������Ƿ�Խ��
		{
		printf("���������Ƿ�����\n");
		continue;
		}
		else
		{
			if ((bd_1[x][y] == '1') && bd_2[x][y] != FLAG_CHAR && flag != 2)	//�����ѯ������Ϊ�ף�����δ��ǣ��Ҵ�ʱ���Ǳ��״̬������Ϸ����
			{
				
				printf("��Ϸ����\n");
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
			else if ((bd_2[x][y] == UNCHK) && (flag == 1))//���ѡ�������δ��ɸ��������Ҵ�ʱ��ɸ��״̬
			{
				
				system("cls");
				func(bd_1, bd_2, x, y, score_p);			//�����ɸ�飬֮���ӡ
				print_bd(bd_2);
				
			}
			else if(flag == 2)						//�����ʱ�Ǳ��״̬��
			{
				if (bd_2[x][y] == UNCHK)			//�����Ӧ�����ǳ���״̬������
				{
					bd_2[x][y] = FLAG_CHAR;
					system("cls");

					print_bd(bd_2);
				}
				else if (bd_2[x][y] == FLAG_CHAR)		//����Ѿ��Ǳ��״̬�����Ƴ����
				{
					bd_2[x][y] = UNCHK;
					system("cls");

					print_bd(bd_2);
				}
				else								//�Ȳ��Ǳ��Ҳ���ǳ���״̬��˵����λ���Ѿ���ɸ�����
				{
					printf("�������޷����\n");
				}
				
			}
			else									//˵����λ���Ѿ���ɸ����������Ѿ������
			{
				printf("�������޷����\n");
			}


		}


	}

	
}

int get_boom_count(char bd_1[ROW1][COL1], int x, int y)//��xy������Χ8�����ӽ���ɸ�飬�Ӷ�ȷ��xy����Ӧ���������ּ�
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

	if (count == 0)		//���xy������Χû���ף�������Χ��չ������ɸ����Χû�б�ɸ��ĸ��ӣ�ֱ��ɸ�鵽��Χ8����������׵ĸ��ӣ��ݹ�ֹͣ
	{
		*score_p = *score_p + 1;//score+1�������ж���Ϸ����
		bd_2[x][y] = BOOM_0;//�����Χû���ף�����ո�
		
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
		*score_p = *score_p + 1;//score+1�������ж���Ϸ����
		bd_2[x][y] = count + '0';//������Χ��Ӧ����������
		return;
	}
}