#include <stdio.h>

int main()
{

	{
  		a^=b;
		b^=a;
		a^=b;							//对a与b交换
	}

	{
		int count = 0;
    	while (n != 0) 
		{
        n &= (n - 1); 
        count++;						//可以判断n这个数字，二进制下有多少个1，
										//原理是每次进行&=操作，都会将数字最右端的1置零，每操作一次count自增1，直到n为0，此时count == 按位与等的操作次数 == 1的个数；
    	}
		
	}













  


  return 0;
}
