#include <REGX52.H>
#include "Delay.h"
 
/**
  * @brief  矩阵键盘检测
  * @param   无
  * @retval  KeyNumber  返回对应标号的数字，没有按键按下返回0；
  */ 
unsigned char MatrixKey()
{
	unsigned char KeyNumber = 0;
	
	P1 = 0xff;
	P1_3 = 0;
	if(P1_7 == 0){Delay(20);if(P1_7 == 0){while(P1_7 == 0);Delay(20);KeyNumber = 1;}}
	if(P1_6 == 0){Delay(20);if(P1_6 == 0){while(P1_6 == 0);Delay(20);KeyNumber = 5;}}
	if(P1_5 == 0){Delay(20);if(P1_5 == 0){while(P1_5 == 0);Delay(20);KeyNumber = 9;}}
	if(P1_4 == 0){Delay(20);if(P1_4 == 0){while(P1_4 == 0);Delay(20);KeyNumber = 13;}}
	
	P1 = 0xff;
	P1_2 = 0;
	if(P1_7 == 0){Delay(20);if(P1_7 == 0){while(P1_7 == 0);Delay(20);KeyNumber = 2;}}
	if(P1_6 == 0){Delay(20);if(P1_6 == 0){while(P1_6 == 0);Delay(20);KeyNumber = 6;}}
	if(P1_5 == 0){Delay(20);if(P1_5 == 0){while(P1_5 == 0);Delay(20);KeyNumber = 10;}}
	if(P1_4 == 0){Delay(20);if(P1_4 == 0){while(P1_4 == 0);Delay(20);KeyNumber = 14;}}
	
	P1 = 0xff;
	P1_1 = 0;
	if(P1_7 == 0){Delay(20);if(P1_7 == 0){while(P1_7 == 0);Delay(20);KeyNumber = 3;}}
	if(P1_6 == 0){Delay(20);if(P1_6 == 0){while(P1_6 == 0);Delay(20);KeyNumber = 7;}}
	if(P1_5 == 0){Delay(20);if(P1_5 == 0){while(P1_5 == 0);Delay(20);KeyNumber = 11;}}
	if(P1_4 == 0){Delay(20);if(P1_4 == 0){while(P1_4 == 0);Delay(20);KeyNumber = 15;}}
	
	P1 = 0xff;
	P1_0 = 0;
	if(P1_7 == 0){Delay(20);if(P1_7 == 0){while(P1_7 == 0);Delay(20);KeyNumber = 4;}}
	if(P1_6 == 0){Delay(20);if(P1_6 == 0){while(P1_6 == 0);Delay(20);KeyNumber = 8;}}
	if(P1_5 == 0){Delay(20);if(P1_5 == 0){while(P1_5 == 0);Delay(20);KeyNumber = 12;}}
	if(P1_4 == 0){Delay(20);if(P1_4 == 0){while(P1_4 == 0);Delay(20);KeyNumber = 16;}}
	
	return KeyNumber;
}