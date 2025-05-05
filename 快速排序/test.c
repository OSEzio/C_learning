#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#define N 10	//�Զ��ٸ����ֽ��п���
#define LOOP for(;;)
int qs_mid(int a[], int low, int high)
{
	int ex = a[low];
	LOOP
	{
		while (low < high && ex <= a[high])
		high--;
		if (low == high)
		break;
		a[low++] = a[high];

		while (low < high && ex >= a[low])
			low++;
		if (low == high)
			break;
		a[high--] = a[low];
	}
	a[low] = ex;
	return low;


}

void quicksort(int a[], int low, int high)
{
	int middle = 0;

	if (low >= high)
		return;
	middle = qs_mid(a, low, high);
	quicksort(a, low, middle - 1);
	quicksort(a, middle + 1, high);
}

int main()
{
	int arr[N] = {0};
	int i = 0;
	printf("���� %d �����֣���������:>",N);
	for (i = 0;i < N;i++)
	{
		scanf("%d", arr + i);
	}
	quicksort(arr, 0, N - 1);

	printf("�����������Ϊ��");
	for (i = 0;i < N;i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}

