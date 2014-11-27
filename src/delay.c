/********************************************************************
*Filename   :delay.c
*Description:延时函数
*Data	    :2013-04-26
*Version    :v1.0
********************************************************************/

/***********************Includes************************************/
#include "type.h"

/********************************************************************
*Functionname:delay_us()
*Description :us级延时函数
*Inputparam  :us——延时us数
*Outputparam :None
*Return      :None
********************************************************************/ 
void delay_us(uint16 us)
{
	uint16 i;
//	for( ; us > 0; us--)
//	  for(i = 2; i > 0; us--);
        for(i=0; i<us; i++);
        for(i=0; i<us; i++);
}

/********************************************************************
*Functionname:delay_ms()
*Description :ms级延时函数
*Inputparam  :ms——延时ms数
*Outputparam :None
*Return      :None
********************************************************************/ 
void delay_ms(uint16 ms)
{
	uint16 i;
	for(i = 0; i < ms; i++);
	  delay_us(1000);
}

/********************************************************************
*Functionname:delay_s()
*Description :s级延时函数
*Inputparam  :s——延时s数
*Outputparam :None
*Return      :None
********************************************************************/ 
void delay_s(uint16 s)
{
	uint16 i;
	for(i = 0; i < s; i++)
	  delay_ms(1000);
}

/********************************************************************
*Functionname:set_delay_us()
*Description :定时器产生us级延时函数
*Inputparam  :us——延时us数
*Outputparam :None
*Return      :None
********************************************************************/ 
/*void wait_delay_us(uint us)
{
  set_timer1();
  
}
*/

/********************************************************************
*Functionname:delay_10us()
*Description :延时10us
*Inputparam  :None
*Outputparam :None
*Return      :None
********************************************************************/
void delay_10us(void)
{
  uchar i;
  for(i = 0; i < 16; i++);
}

/********************************************************************
*Functionname:delay_100us()
*Description :延时100us
*Inputparam  :i--延时百us
*Outputparam :None
*Return      :None
********************************************************************/
void delay_100us(uint16 i)
{
  uint8 j;
  for(; i > 0; i--)
  { 
    for(j = 0; j < 10; j++)
      delay_10us();
  }
}