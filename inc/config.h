/********************************************************************
*Filename	:config.h
*Description    :ϵͳ�˿ڶ���
*Data		:2013-04-26
*Version	:v1.0
********************************************************************/

#ifndef _CONFIG_H_
#define _CONFIG_H_

/**********************Includes*************************************/
#include <ioCC2530.h>

/**********************LCD���ƶ˿ڶ���**********************************/
#define L_CS P1_2	//_CS
#define L_RS P1_0	//_RES  hardware reset
#define L_LD P0_0 	//A0 
#define L_CK P1_5	//SCLK
#define L_DA P1_6	//SI
#define L_BK P0_7	//backlight

#define CONTRASTLEVEL  0x88		//LCD�Աȶ�
/*********************AM2301�˿ڶ���********************************/
#define AMDAT	    P1_1		//AM2301�˿�
#define AMOUT       {P1DIR |= 0x02;}	//AM2301�˿���Ϊ���
#define AMIN	    {P1DIR &= ~0x02;}	//AM2301�˿���Ϊ����

#endif