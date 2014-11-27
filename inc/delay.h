/********************************************************************
*Filename	:delay.h
*Description    :��ʱ�����ⲿ���ýӿ�
*Data		:2013-04-26
*Version	:v1.0
********************************************************************/
#ifndef _DELAY_H_
#define _DELAY_H_

/***********************Includes************************************/
#include "type.h"

/************************Functions**********************************/
extern void delay_us(uint16 us);    //us����ʱ����
extern void delay_ms(uint16 ms);    //ms����ʱ����
extern void delay_s(uint16 s);      //s����ʾ����
extern void delay_10us(void);       //��ʱ10us
extern void delay_100us(uint16 i);  //��ʱ100us

#endif