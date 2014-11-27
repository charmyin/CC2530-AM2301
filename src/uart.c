/************************************************************
 * Filename   :uart.c
 * Description:串口驱动函数
 * Created    :2012/11/15 15:15:05
 * Author     :Charles
 * Version    :v1.1
 ***********************************************************/

/********************Includes*******************************/
#include <ioCC2530.h>
#include <string.h>
#include "delay.h"
#include "type.h"

/********************Variables******************************/

/********************************************************
/Function Name:UART_Init()
/Description  :串口初始化
/Input        :None
/Output       :None
/Return       :None
********************************************************/ 
void UART_Init(void)
{
//    CLKCONCMD &= ~0x40;               //设置系统时钟源为32MHZ晶振
//    while(CLKCONSTA & 0x40);          //等待晶振稳定
//    CLKCONCMD &= ~0x47;               //设置系统主时钟频率为32MHZ
    
    PERCFG = 0x00;		      //位置1 P0口
    P0SEL |= 0x3c;		      //P0_2,P0_3,P0_4,P0_5用作串口
    P2DIR &= ~0XC0;                   //P0优先作为UART0

    U0CSR |= 0x80;     		      //UART方式
    U0GCR |= 10;		      //BAUD_E	(BAUD_E=10,BAUD_M:0~12)       
    U0BAUD |= 0;		      //波特率设为9600,BAUD_M(226~255,BAUD_E=9)
    UTX0IF = 0;                       //UART0 TX中断标志初始置位0
}

/********************************************************
/Function Name:UART_SendChar(uint8 ch)
/Description  :串口发送字符
/Input        :ch--要发送的字符
/Output       :None
/Return       :None
********************************************************/ 
void UART_SendChar(uint8 ch)
{
  U0DBUF = ch;
  while(!UTX0IF);
  UTX0IF = 0;
}

/********************************************************
/Function Name:UART_SendString(uint8 *pstr)
/Description  :串口发送字符串
/Input        :*pstr--要发送的字符串的首地址
/Output       :None
/Return       :None
********************************************************/ 
void UART_SendString(uint8 *pstr)
{
  while(*pstr)
  {
    UART_SendChar(*pstr);
    pstr++;
  }
}
