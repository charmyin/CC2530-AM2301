/************************************************************
 * Filename   :uart.c
 * Description:������������
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
/Description  :���ڳ�ʼ��
/Input        :None
/Output       :None
/Return       :None
********************************************************/ 
void UART_Init(void)
{
//    CLKCONCMD &= ~0x40;               //����ϵͳʱ��ԴΪ32MHZ����
//    while(CLKCONSTA & 0x40);          //�ȴ������ȶ�
//    CLKCONCMD &= ~0x47;               //����ϵͳ��ʱ��Ƶ��Ϊ32MHZ
    
    PERCFG = 0x00;		      //λ��1 P0��
    P0SEL |= 0x3c;		      //P0_2,P0_3,P0_4,P0_5��������
    P2DIR &= ~0XC0;                   //P0������ΪUART0

    U0CSR |= 0x80;     		      //UART��ʽ
    U0GCR |= 10;		      //BAUD_E	(BAUD_E=10,BAUD_M:0~12)       
    U0BAUD |= 0;		      //��������Ϊ9600,BAUD_M(226~255,BAUD_E=9)
    UTX0IF = 0;                       //UART0 TX�жϱ�־��ʼ��λ0
}

/********************************************************
/Function Name:UART_SendChar(uint8 ch)
/Description  :���ڷ����ַ�
/Input        :ch--Ҫ���͵��ַ�
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
/Description  :���ڷ����ַ���
/Input        :*pstr--Ҫ���͵��ַ������׵�ַ
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
