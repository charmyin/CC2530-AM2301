/********************************************************************
*Filename	:am2301.h
*Description    :am2301驱动函数外部调用接口
*Data		:2013-04-26
*Version	:v1.0
********************************************************************/
#ifndef _AM2301_DRIVER_H_
#define _AM2301_DRIVER_H_

/********************Includes***********************************/
#include "config.h"
#include "type.h"
 
/********************Variables**********************************/
extern u8 crc;					//校验值
extern u8 tempH;				//温度高8位
extern u8 tempL;				//温度低8位
extern u8 humiH;				//湿度高8位
extern u8 humiL;				//湿度低8位
/********************Fuctions***********************************/
extern void AM2301_Read_Data(void);		//读取AM2301的数据
extern boolean AM2301_Check_Data(void);	        //数据校验
 
#endif