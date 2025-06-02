#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

#define PASS_DIG 7
unsigned char KeyNum;
unsigned char arr[16] = {'1','2','3','R',
						 '4','5','6',' ',
						 '7','8','9','C',
						 '*','0','#','Y',};
unsigned char dig = 1;
unsigned char Password[] = "7355608";
unsigned char Input[PASS_DIG] = {0};						 
						 
void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"PassWord:>");
	LCD_ShowString(2,1,"-------");//7位数密码,可以用循环打印对应数量的'-'来实现，暂时先这样懒得改
	while(1)
	{
		KeyNum = MatrixKey();
		if(KeyNum != 0)
		{
			if((KeyNum<=3||(KeyNum<=7&&KeyNum>=5)||(KeyNum<=11&&KeyNum>=9)||(KeyNum<=15&&KeyNum>=13))&&dig<=7)
			{
				LCD_ShowChar(2,dig,arr[KeyNum-1]);
				Input[dig-1] = arr[KeyNum-1];
				dig++;
			}
			if(KeyNum == 12)
			{
				LCD_ShowString(2,1,"-------");
				dig = 1;
			}
			if(KeyNum == 16)
			{
				char i = 0;
				char flag = 1;
				for(i = 0;i<PASS_DIG;i++)
				{
					if(Password[i] != Input[i])
					{
						flag = 0;
						break;
					}
				}
				
				if(1 == flag)
				{
					LCD_ShowString(1,12,"     ");	//打印空格，覆盖之前显示的内容
					LCD_ShowString(1,13,"OK");
				}
				else
					LCD_ShowString(1,12,"*ERR*");
			}	
		}
	}

}