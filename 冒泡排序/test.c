#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "bubble_sr.h"
#define N 100
#define ROW 10
#define COL 10

int main() {

	srand(time(NULL));
	int i = 0;
	int arr[N] = {0};
	for (i = 0;i < N;i++)
	{
		arr[i] = rand()%1000;
	}
	printf("Ëæ»úÐòÁÐ:>\n");
	for (i = 0;i < ROW;i++)
	{
		int j = 0;
		for (j = 0;j < COL;j++)
		{
			printf("%d\t", arr[10*i+j]);
		}
		printf("\n");
	}

	bubble_sr(arr, 0, N - 1);

	printf("\n\nÅÅÐòÐòÁÐ:>\n");
	for (i = 0;i < ROW;i++)
	{
		int j = 0;
		for (j = 0;j < COL;j++)
		{
			printf("%d\t", arr[10 * i + j]);
		}
		printf("\n");


	}
}