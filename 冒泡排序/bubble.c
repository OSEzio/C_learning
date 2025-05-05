#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void bubble_sr(int arr[], int left, int right)
{
	while (left < right)
	{
		if (arr[left] > arr[left + 1])
		{
			int reg = arr[left];
			arr[left] = arr[left + 1];
			arr[left + 1] = reg;
		}
		left++;

	}
	if (left == 0)
		return;
	else
		bubble_sr(arr, 0, right - 1);

}