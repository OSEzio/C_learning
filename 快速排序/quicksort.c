#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#define LOOP for(;;)
int qs_mid(int a[], int low, int high)				//快排本质上会将数组分割成两个部分，左边全部小于e，右边全部大于e，此时，e的下标就为qs_mid
{													//qs_mid的意思是快排分割的下表，在数组中间的位置
	int ex = a[low];								//取数组最左边的数作为分割的判断数，命名为ex
	LOOP
	{
		while (low < high && ex <= a[high])			//如果低标志小于高标志，并且ex分割数小于高标志指向的数字
		high--;										//则高标志左移一位，直到不满足上两个条件其中之一
		if (low == high)							//如果是第一个条件不满足，即此时高低标志汇合
		break;										//则跳出循环，说明此时从初始设定的高标志到低标志这个范围，已经整理完毕，即ex左边的数字全部小于ex，ex右边的数字全部大于ex
		a[low++] = a[high];							//如果是第二个条件不满足，即此时高标志指向的数字小于ex，说明此时该数字应该在ex左边，所以将其放在之前a[LOW]的空位里，low标志右移一位

		while (low < high && ex >= a[low])			//和上面的部分大致一样，
			low++;									//可以发现，如果左面有空位，则对右面进行标志移动（high向左移），反之，则low标志向右移动，
		if (low == high)
			break;
		a[high--] = a[low];
	}
	a[low] = ex;									//直到，左右标志重合，此时说明，空位左边的数字均<ex<空位右边的数字，
	return low;


}

void quicksort(int a[], int low, int high)
{
	int middle = 0;

	if (low >= high)
		return;
	middle = qs_mid(a, low, high);					//然后找到标志位，对左右两侧的数组分别进行多次快排的递归
	quicksort(a, low, middle - 1);
	quicksort(a, middle + 1, high);
}
