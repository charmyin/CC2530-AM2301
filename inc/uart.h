/************************************************************
 * Filename   :uart.h
 * Description:���ں����ⲿ���ýӿ�
 * Created    :2012/11/15 15:15:05
 * Author     :Charles
 * Version    :v1.1
 ***********************************************************/
#ifndef _UART_H_
#define _UART_H_

/*****************Includes**********************************/
#include "type.h"

/*****************Functions*********************************/
extern void UART_Init(void);                 //���ڳ�ʼ��
extern void UART_SendChar(uint8 ch);         //���ڷ���һ���ַ�
extern void UART_SendString(uint8 *pstr);    //���ڷ���һ���ַ���

#endif
