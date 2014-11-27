/********************************************************************
*Filename	:LCD.h
*Description    :LCD的驱动函数的外部调用接口
*Data		:2013-04-26
*Version	:v1.0
********************************************************************/
#ifndef _LCD_H_
#define _LCD_H_

/*************************Includes**********************************/
#include "type.h"

/*********************Fuctions**************************************/
extern void ResetLCD(void);	                        //LCD复位
extern void ClearRAM(void);				//清除显示缓存
extern void Print8(uint8 x, uint8 y, uchar *pstr);	//打印字符串
extern void initLCDM(void);

#endif