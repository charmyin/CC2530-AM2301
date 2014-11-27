/********************************************************************
*Filename	:am2301.h
*Description    :AM2301的驱动函数
*Data		:2013-04-26
*Version	:v1.0
********************************************************************/

/*******************Includes************************************/
#include "delay.h"
#include "type.h"
#include "config.h"

/******************Local variables******************************/
u8 humiH;				//湿度高8位
u8 humiL;				//湿度低8位
u8 tempH;				//温度高8位
u8 tempL;				//温度低8位
u8 crc;					//校验值

/********************************************************
/Function Name:AM2301_Start(void)
/Description  :AM2301起始信号
/Input        :
/Output       :None
/Return       :None
********************************************************/ 
void AM2301_Start(void)
{
  AMDAT = 0;
  delay_100us(2);//起始信号低电平1~5ms
  AMDAT = 1;	//释放总线
  
  AMIN;		//设置为输入	
//AMDAT = 1;	//AVR上拉
  delay_10us();	//等待响应20~200us
  delay_10us();
  delay_10us();
  delay_10us();
}

/********************************************************
/Function Name:AM2301_Wait_ACK(void)
/Description  :等待AM2301响应
/Input        :None
/Output       :None
/Return       :None
********************************************************/
boolean AM2301_Wait_ACK(void)
{
  u8 i = 2;
  if(AMDAT == 0)
  {
    while(!AMDAT && i++);   //80us低电平
            
    i = 2;
    while(AMDAT && i++);    //80us高电平
            
    return 1;		    //AM2301响应成功
  }
  else
    return 0;		    //AM2301未响应
}
 
/********************************************************
/Function Name:AM2301_Read_Byte(void)
/Description  :从AM2301中读取一个字节数据
/Input        :None
/Output       :None
/Return       :None
********************************************************/ 
u8 AM2301_Read_Byte(void)
{
  u8 temp = 0, i;
  
  for(i = 0; i <8; i++)
  {	
    u8 t = 2;			
    while(!AMDAT && t++);	//等待50us前导码

    delay_10us();		//等待30us
    delay_10us();
    delay_10us();
    
    if(AMDAT)		        //如果是高电平，则数据时"1"，否则为"0"
    {
      temp <<= 1;
      temp |= 0x01;			
      t = 2;
      while(AMDAT && t++);      //等待70us高电平结束
    }
    else
      temp <<= 1;		
  }
  
  return temp;	
}

/********************************************************
/Function Name:AM2301_Read_Data(void)
/Description  :从AM2301中读取所有40位数据
/Input        :
/Output       :None
/Return       :None
********************************************************/ 
void AM2301_Read_Data(void)
{
  AM2301_Start();			//发送起始信号
  if(AM2301_Wait_ACK())			//等待响应
  {
    humiH = AM2301_Read_Byte();		//读取湿度高8位		
    humiL = AM2301_Read_Byte();		//读取湿度低8位		
    tempH = AM2301_Read_Byte();		//读取温度高8位		
    tempL = AM2301_Read_Byte();		//读取温度低8位	
    crc = AM2301_Read_Byte();		//读取校验数据
  }
  
  AMOUT;				//读取完数据之后将数据口设为输出模式
  AMDAT = 1;				//且释放总线
}

/********************************************************
/Function Name:AM2301_Check_Data(void)
/Description  :校验数据
/Input        :None
/Output       :None
/Return       :None
********************************************************/ 
boolean AM2301_Check_Data(void)
{
  u8 temp;
  temp = humiH + humiL + tempH + tempL;	//校验数据
  if(crc == temp)
    return 1;			        //数据有效
  else
    return 0;			        //数据无效
}
