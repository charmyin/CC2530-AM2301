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
 extern void Sys_Init(void);		//ϵͳ��ʼ�� 
 extern void Display(void);		//LCD��ʾ
 extern void Send2PC(void);                 //�������ݵ�PC��
 extern void Data_Process(void);	//���ݽ��ռ�����
 
 #endif