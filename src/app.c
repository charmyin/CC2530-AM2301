/******************************************************************
 * app.c
 *
 * Created: 2012/11/15 0:09:53
 * Author: Charles
 ****************************************************************/ 

/*******************Includes******************************/
 #include "delay.h" 
 #include "config.h"
 #include "type.h"
 #include "lcd.h"
 #include "am2301.h"
 #include "uart.h"
 
/******************Defines*****************************/
#define AM_PORT_INIT  {/*P1SEL &= ~0x02;*/ P1DIR |= 0x02; AMDAT = 1;} //AM2301�˿ڳ�ʼ��,GPIO���
/*P1SEL &= ~0x65; P0SEL &= ~0x81; \*/
#define LCD_PORT_INIT {P1DIR |= 0x65; P0DIR |= 0x81;}		  //LCD�˿ڳ�ʼ��

/******************Variables****************************/
u8 Temp[] = "Temp:   .  C";
u8 Humi[] = "Humi:   .  %";
u8 i = '0';

/********************************************************
/Function Name:AM2301_Start(void)
/Description  :ϵͳ��ʼ��
/Input        :
/Output       :None
/Return       :None
********************************************************/ 
void Sys_Init(void)
{
  AM_PORT_INIT;
  LCD_PORT_INIT;
  ResetLCD();			//LCD��ʼ��
  initLCDM();
  ClearRAM();
  UART_Init();
}
 
/********************************************************
/Function Name:AM2301_Start(void)
/Description  :��ʾ
/Input        :
/Output       :None
/Return       :None
********************************************************/ 
void Display(void)
{
  Print8(0, 0, Temp);		//��ʾ�¶�
  Print8(0, 1, Humi);		//��ʾʪ��
}
 
/********************************************************
/Function Name:Data_Process()
/Description  :���ݽ��ռ�����
/Input        :None
/Output       :None
/Return       :None
********************************************************/ 
void Data_Process(void)
{
  u16 temp;
  AM2301_Read_Data();

  if(AM2301_Check_Data())				//�¶��������
  {
    if((tempH & 0x80) == 0x80)
      Temp[5] = '-';
    else
      Temp[5] = '+';
            
    temp = (tempH & 0xef) * 256 + tempL;
    Temp[6] = temp / 100 + 0x30;			//����ÿλ���ݲ�ת��ΪASCII��	
    Temp[7] = temp % 100 / 10 + 0x30;
    Temp[9] = temp % 100 % 10 + 0x30;
    
    temp = humiH * 256 + humiL;
    Humi[6] = temp / 100 + 0x30;
    Humi[7] = temp % 100 / 10 + 0x30;
    Humi[9] = temp % 100 % 10 + 0x30;
  }
}

/********************************************************
/Function Name:Send2PC()
/Description  :�������ݵ�PC��
/Input        :None
/Output       :None
/Return       :None
********************************************************/
void Send2PC(void)
{
  UART_SendString(Temp);
  UART_SendChar('\t');
  UART_SendString(Humi);
  UART_SendChar('\r');
  UART_SendChar('\n');
}
