#pragma once

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROW 9
#define COL 9
#define ROW1 ROW + 2
#define COL1 COL + 2
#define LOOP for(;;)
#define EASY 10

#define MODE EASY
#define SCORE_WIN ROW*COL-EASY
#define UNCHK '#'



void menu();
void gamestart(char bd_1[ROW1][COL1], char bd_2[ROW1][COL1]);
void bd_INIT(char board[ROW1][COL1], char set);
void print_bd(char bd[ROW1][COL1]);
void find_boom(char bd_1[ROW1][COL1], char bd_2[ROW1][COL1], int row, int col);
int get_boom_count(char bd_1[ROW1][COL1], int x, int y);

