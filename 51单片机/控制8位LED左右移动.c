#include <REGX52.H>
#include <INTRINS.H>
void Delay(unsigned int xms)	//毫秒数 <= 65535	//	//@11.0592MHz
{
	unsigned char i, j;
	while(xms--)
	{	
		_nop_();
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
	
	}
}



void main()
{
	int PP2 = 0x08;//0000 0001
	P2 = ~PP2;
	while(1)
	{
		if(0 == P3_1)		//如果检测到按下K0的信号
		{
			Delay(20);		//延时20ms
			if(0 == P3_1)	//重新检测一遍是否按下K0
			{
				if(0x01 == PP2)
				{
					PP2 = 0x80;
				}
				else
				PP2=PP2>>1;
				while(0 == P3_1);
				Delay(20);
				if(1 == P3_1)
				P2 = ~PP2;	
			}
		}
		if(0 == P3_0)		//如果检测到按下K0的信号
		{
			Delay(20);		//延时20ms
			if(0 == P3_0)	//重新检测一遍是否按下K0
			{
				if(0x80 == PP2)
				{
					PP2 = 0x01;
				}
				else
				PP2<<=1;
				while(0 == P3_0);
				Delay(20);
				if(1 == P3_0)
				P2 = ~PP2;	
			}
		}
	
	
	
	
	}



}
