#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
/*****************************
		1.�ַ�����ת
*******************************/

//int my_Strlen(char arr[])
//{
//	int count = 0;
//	while(*arr != '\0')
//	{
//		count++;
//		arr = arr + 1;
//	}
//
//	return count;
//}
//
//void reverse(char arr[])
//{
//
//	char reg = '\0';
//	int sz = my_Strlen(arr);
//	if (sz < 2)
//	{
//		return;
//	}
//	else
//	{
//		reg = *arr;
//		*arr = *(arr + sz - 1);
//		*(arr + sz - 1) = '\0';
//
//		reverse(arr + 1);
//		*(arr + sz - 1) = reg;
//	} 
//}
//
//int main() {
//	char arr[] = "abcdefg";
//
//	reverse(arr);
//	printf("%s\n", arr);
//
//
//}

//

/*****************************
		2.����һ������ÿλ֮��
*******************************/
//int DigitSum(int n)
//{
//	if (n <= 9)
//		return n;
//	else
//	{
//		int x = n % 10;
//		n = n / 10;
//		return x + DigitSum(n);
//	}
//
//}
//
//int main(){
//
//	int n = 0;
//	printf("���������֣�����ÿλ֮��:>");
//	scanf("%d", &n);
//
//	int sum = DigitSum(n);
//
//	printf("ÿλ֮��Ϊ:> %d", sum);
//	return 0;
//}

/*****************************
		3.��������K��N�η���NΪ����
*******************************/
double my_Pow(int x, int y)
{
	if (y == 0)
		return 1;
	else if (y > 0)
		return x * my_Pow(x, y - 1);
	else
		return (1.0 / x) * my_Pow(x, y + 1);


}

int main()
{
	int K, N;
	printf("����K��N\n");
	scanf("%d %d", &K, &N);
	double ret = my_Pow(K,N);
	printf("%d��%d�η�Ϊ --> %lf", K, N, ret);
	return 0;
}
