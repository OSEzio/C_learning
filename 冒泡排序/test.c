#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "bubble_sr.h"
#define N 10


int main() {

	srand(time(NULL));
	int i = 0;
	int arr[N] = {0};
	for (i = 0;i < N;i++)
	{
		arr[i] = rand()%100;
	}
	printf("随机序列:>\n");
	for (i = 0;i < N;i++)
	{
		printf("%d ", arr[i]);
	}

	bubble_sr(arr, 0, N - 1);

	printf("\n\n排序序列:>\n");
	for (i = 0;i < N;i++)
	{
		printf("%d ", arr[i]);
	}
}
