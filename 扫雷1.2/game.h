#pragma once

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROW 9		//期望的棋盘行数
#define COL 9		//期望的棋盘列数
#define ROW1 ROW + 2
#define COL1 COL + 2
#define LOOP for(;;)	//死循环
#define EASY 10		//简单模式 雷的数量

#define MODE EASY	//模式调整为简单
#define SCORE_WIN ROW*COL-EASY	//获胜目标分数
#define UNCHK '*'			//未知区域棋盘样式
#define FLAG_CHAR 'P'		//标记样式
#define BOOM_0 ' '

void menu();
void gamestart(char bd_1[ROW1][COL1], char bd_2[ROW1][COL1]);
void bd_INIT(char board[ROW1][COL1], char set);
void print_bd(char bd[ROW1][COL1]);
void find_boom(char bd_1[ROW1][COL1], char bd_2[ROW1][COL1], int row, int col);
int get_boom_count(char bd_1[ROW1][COL1], int x, int y);

void func(char bd_1[ROW1][COL1], char bd_2[ROW1][COL1], int x, int y, int* score_p);
