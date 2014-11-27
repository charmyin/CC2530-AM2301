/********************************************************************
*Filename   :delay.c
*Description:��ʱ����
*Data	    :2013-04-26
*Version    :v1.0
********************************************************************/

/***********************Includes************************************/
#include "type.h"

/********************************************************************
*Functionname:delay_us()
*Description :us����ʱ����
*Inputparam  :us������ʱus��
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
*Description :ms����ʱ����
*Inputparam  :ms������ʱms��
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
*Description :s����ʱ����
*Inputparam  :s������ʱs��
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
*Description :��ʱ������us����ʱ����
*Inputparam  :us������ʱus��
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
*Description :��ʱ10us
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
*Description :��ʱ100us
*Inputparam  :i--��ʱ��us
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