/********************************************************************
*Filename	:am2301.h
*Description    :am2301���������ⲿ���ýӿ�
*Data		:2013-04-26
*Version	:v1.0
********************************************************************/
#ifndef _AM2301_DRIVER_H_
#define _AM2301_DRIVER_H_

/********************Includes***********************************/
#include "config.h"
#include "type.h"
 
/********************Variables**********************************/
extern u8 crc;					//У��ֵ
extern u8 tempH;				//�¶ȸ�8λ
extern u8 tempL;				//�¶ȵ�8λ
extern u8 humiH;				//ʪ�ȸ�8λ
extern u8 humiL;				//ʪ�ȵ�8λ
/********************Fuctions***********************************/
extern void AM2301_Read_Data(void);		//��ȡAM2301������
extern boolean AM2301_Check_Data(void);	        //����У��
 
#endif