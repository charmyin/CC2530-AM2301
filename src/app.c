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
#define AM_PORT_INIT  {/*P1SEL &= ~0x02;*/ P1DIR |= 0x02; AMDAT = 1;} //AM2301端口初始化,GPIO输出
/*P1SEL &= ~0x65; P0SEL &= ~0x81; \*/
#define LCD_PORT_INIT {P1DIR |= 0x65; P0DIR |= 0x81;}		  //LCD端口初始化

/******************Variables****************************/
u8 Temp[] = "Temp:   .  C";
u8 Humi[] = "Humi:   .  %";
u8 i = '0';

/********************************************************
/Function Name:AM2301_Start(void)
/Description  :系统初始化
/Input        :
/Output       :None
/Return       :None
********************************************************/ 
void Sys_Init(void)
{
  AM_PORT_INIT;
  LCD_PORT_INIT;
  ResetLCD();			//LCD初始化
  initLCDM();
  ClearRAM();
  UART_Init();
}
 
/********************************************************
/Function Name:AM2301_Start(void)
/Description  :显示
/Input        :
/Output       :None
/Return       :None
********************************************************/ 
void Display(void)
{
  Print8(0, 0, Temp);		//显示温度
  Print8(0, 1, Humi);		//显示湿度
}
 
/********************************************************
/Function Name:Data_Process()
/Description  :数据接收及处理
/Input        :None
/Output       :None
/Return       :None
********************************************************/ 
void Data_Process(void)
{
  u16 temp;
  AM2301_Read_Data();

  if(AM2301_Check_Data())				//温度正负检测
  {
    if((tempH & 0x80) == 0x80)
      Temp[5] = '-';
    else
      Temp[5] = '+';
            
    temp = (tempH & 0xef) * 256 + tempL;
    Temp[6] = temp / 100 + 0x30;			//分离每位数据并转换为ASCII码	
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
/Description  :发送数据到PC机
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
