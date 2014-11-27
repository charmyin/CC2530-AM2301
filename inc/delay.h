/********************************************************************
*Filename	:delay.h
*Description    :延时函数外部调用接口
*Data		:2013-04-26
*Version	:v1.0
********************************************************************/
#ifndef _DELAY_H_
#define _DELAY_H_

/***********************Includes************************************/
#include "type.h"

/************************Functions**********************************/
extern void delay_us(uint16 us);    //us级延时函数
extern void delay_ms(uint16 ms);    //ms级延时函数
extern void delay_s(uint16 s);      //s级演示函数
extern void delay_10us(void);       //延时10us
extern void delay_100us(uint16 i);  //延时100us

#endif