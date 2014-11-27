/******************************************************************
 * app.h
 *
 * Created: 2012/11/15 0:09:53
 * Author: Charles
 ****************************************************************/ 
 #ifndef _APP_H_
 #define _APP_H_
 /*******************Includes******************************/
 
 /*******************Functions*****************************/
 extern void Sys_Init(void);		//系统初始化 
 extern void Display(void);		//LCD显示
 extern void Send2PC(void);                 //发送数据到PC机
 extern void Data_Process(void);	//数据接收及处理
 
 #endif