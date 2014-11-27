/************************************************************
 * main.c
 *
 * Created: 2012/11/15 15:15:05
 * Author: Charles
 ***********************************************************/
 
/*********************Includes********************************/
#include "delay.h"
#include "app.h"
#include "config.h"
#include "type.h"

/*********************Defines*********************************/
#define GAP	500	//间隔时间

/*********************Local variables*************************/

/*********************Local functions*************************/

/*********************Main************************************/
int main(void)
{
  Sys_Init();		//系统初始化	
  
  while(1)
  {
    Data_Process();	//数据接收处理
    Display();		//显示
    Send2PC();          //发送数据到PC机
    delay_s(GAP);	//AM2301间隔至少2s才能读取一次  
  }

  return 0;
}
