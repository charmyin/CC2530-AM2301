/************************************************************
 * Filename   :uart.h
 * Description:串口函数外部调用接口
 * Created    :2012/11/15 15:15:05
 * Author     :Charles
 * Version    :v1.1
 ***********************************************************/
#ifndef _UART_H_
#define _UART_H_

/*****************Includes**********************************/
#include "type.h"

/*****************Functions*********************************/
extern void UART_Init(void);                 //串口初始化
extern void UART_SendChar(uint8 ch);         //串口发送一个字符
extern void UART_SendString(uint8 *pstr);    //串口发送一个字符串

#endif
