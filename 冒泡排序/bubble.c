#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void bubble_sr(int arr[], int left, int right)		//arr为待排序的数组，left为左标志，right为右标志
{
	while (left < right)				//当左标志没有越过右标志的时候，循环持续
	{
		if (arr[left] > arr[left + 1])		//如果检测到左标志位上的元素比下一个元素要大，则将两者交换，之后左标志位右移一次
		{
			int reg = arr[left];
			arr[left] = arr[left + 1];
			arr[left + 1] = reg;
		}
		left++;

	}
	if (left == 0)					//如果左标志位为0，说明根本没有进行++操作，也就是说上面的while循环没有执行，说明此时左标志和右标志处在一个位置且位于数组首元素
		return;					//说明此时只剩一个元素，则不需要排序，直接退出递归
	else
		bubble_sr(arr, 0, right - 1);		//否则，说明进行过排序操作，即，已经将整个数组中最大的元素放置在最右侧，此时将右标左移一次，对剩余的进行递归排序，依次将较大值
							//筛选出，并且放置在右侧，直到数组中只剩一个元素，此时不需要排序；
}
