/********************************************************************
*Filename	:LCD.h
*Description    :LCD�������������ⲿ���ýӿ�
*Data		:2013-04-26
*Version	:v1.0
********************************************************************/
#ifndef _LCD_H_
#define _LCD_H_

/*************************Includes**********************************/
#include "type.h"

/*********************Fuctions**************************************/
extern void ResetLCD(void);	                        //LCD��λ
extern void ClearRAM(void);				//�����ʾ����
extern void Print8(uint8 x, uint8 y, uchar *pstr);	//��ӡ�ַ���
extern void initLCDM(void);

#endif