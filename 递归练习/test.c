#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
/*****************************
		1.字符串反转
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
		2.计算一个数的每位之和
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
//	printf("请输入数字，计算每位之和:>");
//	scanf("%d", &n);
//
//	int sum = DigitSum(n);
//
//	printf("每位之和为:> %d", sum);
//	return 0;
//}

/*****************************
		3.计算整数K的N次方，N为整数
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
	printf("输入K，N\n");
	scanf("%d %d", &K, &N);
	double ret = my_Pow(K,N);
	printf("%d的%d次方为 --> %lf", K, N, ret);
	return 0;
}
