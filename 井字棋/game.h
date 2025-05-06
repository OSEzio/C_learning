#pragma once

#define ROW 3
#define COL 3
#define P1 'P'
#define LOOP for(;;)

#define TRUE 1
#define FAULT 0

void menu();
void game(char board[ROW][COL]);
void pla_rd(char board[ROW][COL]);
void cmp_rd(char board[ROW][COL]);
int check(char board[ROW][COL], char class);

