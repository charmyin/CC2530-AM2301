/********************************************************************
*Filename	:am2301.h
*Description    :AM2301����������
*Data		:2013-04-26
*Version	:v1.0
********************************************************************/

/*******************Includes************************************/
#include "delay.h"
#include "type.h"
#include "config.h"

/******************Local variables******************************/
u8 humiH;				//ʪ�ȸ�8λ
u8 humiL;				//ʪ�ȵ�8λ
u8 tempH;				//�¶ȸ�8λ
u8 tempL;				//�¶ȵ�8λ
u8 crc;					//У��ֵ

/********************************************************
/Function Name:AM2301_Start(void)
/Description  :AM2301��ʼ�ź�
/Input        :
/Output       :None
/Return       :None
********************************************************/ 
void AM2301_Start(void)
{
  AMDAT = 0;
  delay_100us(2);//��ʼ�źŵ͵�ƽ1~5ms
  AMDAT = 1;	//�ͷ�����
  
  AMIN;		//����Ϊ����	
//AMDAT = 1;	//AVR����
  delay_10us();	//�ȴ���Ӧ20~200us
  delay_10us();
  delay_10us();
  delay_10us();
}

/********************************************************
/Function Name:AM2301_Wait_ACK(void)
/Description  :�ȴ�AM2301��Ӧ
/Input        :None
/Output       :None
/Return       :None
********************************************************/
boolean AM2301_Wait_ACK(void)
{
  u8 i = 2;
  if(AMDAT == 0)
  {
    while(!AMDAT && i++);   //80us�͵�ƽ
            
    i = 2;
    while(AMDAT && i++);    //80us�ߵ�ƽ
            
    return 1;		    //AM2301��Ӧ�ɹ�
  }
  else
    return 0;		    //AM2301δ��Ӧ
}
 
/********************************************************
/Function Name:AM2301_Read_Byte(void)
/Description  :��AM2301�ж�ȡһ���ֽ�����
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
    while(!AMDAT && t++);	//�ȴ�50usǰ����

    delay_10us();		//�ȴ�30us
    delay_10us();
    delay_10us();
    
    if(AMDAT)		        //����Ǹߵ�ƽ��������ʱ"1"������Ϊ"0"
    {
      temp <<= 1;
      temp |= 0x01;			
      t = 2;
      while(AMDAT && t++);      //�ȴ�70us�ߵ�ƽ����
    }
    else
      temp <<= 1;		
  }
  
  return temp;	
}

/********************************************************
/Function Name:AM2301_Read_Data(void)
/Description  :��AM2301�ж�ȡ����40λ����
/Input        :
/Output       :None
/Return       :None
********************************************************/ 
void AM2301_Read_Data(void)
{
  AM2301_Start();			//������ʼ�ź�
  if(AM2301_Wait_ACK())			//�ȴ���Ӧ
  {
    humiH = AM2301_Read_Byte();		//��ȡʪ�ȸ�8λ		
    humiL = AM2301_Read_Byte();		//��ȡʪ�ȵ�8λ		
    tempH = AM2301_Read_Byte();		//��ȡ�¶ȸ�8λ		
    tempL = AM2301_Read_Byte();		//��ȡ�¶ȵ�8λ	
    crc = AM2301_Read_Byte();		//��ȡУ������
  }
  
  AMOUT;				//��ȡ������֮�����ݿ���Ϊ���ģʽ
  AMDAT = 1;				//���ͷ�����
}

/********************************************************
/Function Name:AM2301_Check_Data(void)
/Description  :У������
/Input        :None
/Output       :None
/Return       :None
********************************************************/ 
boolean AM2301_Check_Data(void)
{
  u8 temp;
  temp = humiH + humiL + tempH + tempL;	//У������
  if(crc == temp)
    return 1;			        //������Ч
  else
    return 0;			        //������Ч
}
