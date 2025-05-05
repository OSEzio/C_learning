#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#define LOOP for(;;)
int qs_mid(int a[], int low, int high)				//���ű����ϻὫ�����ָ���������֣����ȫ��С��e���ұ�ȫ������e����ʱ��e���±��Ϊqs_mid
{													//qs_mid����˼�ǿ��ŷָ���±��������м��λ��
	int ex = a[low];								//ȡ��������ߵ�����Ϊ�ָ���ж���������Ϊex
	LOOP
	{
		while (low < high && ex <= a[high])			//����ͱ�־С�ڸ߱�־������ex�ָ���С�ڸ߱�־ָ�������
		high--;										//��߱�־����һλ��ֱ����������������������֮һ
		if (low == high)							//����ǵ�һ�����������㣬����ʱ�ߵͱ�־���
		break;										//������ѭ����˵����ʱ�ӳ�ʼ�趨�ĸ߱�־���ͱ�־�����Χ���Ѿ�������ϣ���ex��ߵ�����ȫ��С��ex��ex�ұߵ�����ȫ������ex
		a[low++] = a[high];							//����ǵڶ������������㣬����ʱ�߱�־ָ�������С��ex��˵����ʱ������Ӧ����ex��ߣ����Խ������֮ǰa[LOW]�Ŀ�λ�low��־����һλ

		while (low < high && ex >= a[low])			//������Ĳ��ִ���һ����
			low++;									//���Է��֣���������п�λ�����������б�־�ƶ���high�����ƣ�����֮����low��־�����ƶ���
		if (low == high)
			break;
		a[high--] = a[low];
	}
	a[low] = ex;									//ֱ�������ұ�־�غϣ���ʱ˵������λ��ߵ����־�<ex<��λ�ұߵ����֣�
	return low;


}

void quicksort(int a[], int low, int high)
{
	int middle = 0;

	if (low >= high)
		return;
	middle = qs_mid(a, low, high);					//Ȼ���ҵ���־λ�����������������ֱ���ж�ο��ŵĵݹ�
	quicksort(a, low, middle - 1);
	quicksort(a, middle + 1, high);
}
