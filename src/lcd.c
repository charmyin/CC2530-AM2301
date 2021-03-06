/********************************************************************
*Filename   :LCD.c
*Description:LCD的驱动函数
*Data	    :2013-04-26
*Version    :v1.0
********************************************************************/

/*********************Includes**************************************/
#include <string.h>
#include "type.h"
#include "config.h"
#include "delay.h"

//-------------  ASCII字符库----------------------------------------------------------------
//说明：该字库为5*7点阵字符字模库，但字库格式为8*8点阵字模数据，第8行为行间距，
//      第6-8列为字间距。可以使用6*8点阵、7*8点阵、8*8点阵形式的字符显示
__code const INT8U ASCIITAB[]={
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,    /*" "=00H*/
  0x00,0x00,0x00,0x4F,0x00,0x00,0x00,0x00,    /*"!"=01H*/
  0x00,0x00,0x07,0x00,0x07,0x00,0x00,0x00,    /*"""=02h*/
  0x00,0x14,0x7F,0x14,0x7F,0x14,0x00,0x00,    /*"#"=03h*/
  0x00,0x24,0x2A,0x7F,0x2A,0x12,0x00,0x00,    /*"$"=04h*/
  0x00,0x23,0x13,0x08,0x64,0x62,0x00,0x00,    /*"%"=05h*/
  0x00,0x36,0x49,0x55,0x22,0x50,0x00,0x00,    /*"&"=06h*/
  0x00,0x00,0x05,0x03,0x00,0x00,0x00,0x00,    /*"'"=07h*/
  0x00,0x00,0x1C,0x22,0x41,0x00,0x00,0x00,    /*"("=08h*/
  0x00,0x00,0x41,0x22,0x1C,0x00,0x00,0x00,    /*")"=09h*/
  0x00,0x14,0x08,0x3E,0x08,0x14,0x00,0x00,    /*"*"=0Ah*/
  0x00,0x08,0x08,0x3E,0x08,0x08,0x00,0x00,    /*"+"=0Bh*/
  0x00,0x00,0x50,0x30,0x00,0x00,0x00,0x00,    /*";"=0Ch*/
  0x00,0x08,0x08,0x08,0x08,0x08,0x00,0x00,    /*"-"=0Dh*/
  0x00,0x00,0x60,0x60,0x00,0x00,0x00,0x00,    /*"."=0Eh*/
  0x00,0x20,0x10,0x08,0x04,0x02,0x00,0x00,    /*"/"=0Fh*/
  0x00,0x3E,0x51,0x49,0x45,0x3E,0x00,0x00,    /*"0"=10h*/
  0x00,0x00,0x42,0x7F,0x40,0x00,0x00,0x00,    /*"1"=11h*/
  0x00,0x42,0x61,0x51,0x49,0x46,0x00,0x00,    /*"2"=12h*/
  0x00,0x21,0x41,0x45,0x4B,0x31,0x00,0x00,    /*"3"=13h*/
  0x00,0x18,0x14,0x12,0x7F,0x10,0x00,0x00,    /*"4"=14h*/
  0x00,0x27,0x45,0x45,0x45,0x39,0x00,0x00,    /*"5"=15h*/
  0x00,0x3C,0x4A,0x49,0x49,0x30,0x00,0x00,    /*"6"=16h*/
  0x00,0x01,0x01,0x79,0x05,0x03,0x00,0x00,    /*"7"=17h*/
  0x00,0x36,0x49,0x49,0x49,0x36,0x00,0x00,    /*"8"=18h*/
  0x00,0x06,0x49,0x49,0x29,0x1E,0x00,0x00,    /*"9"=19h*/
  0x00,0x00,0x36,0x36,0x00,0x00,0x00,0x00,    /*":"=1Ah*/
  0x00,0x00,0x56,0x36,0x00,0x00,0x00,0x00,    /*";"=1Bh*/
  0x00,0x08,0x14,0x22,0x41,0x00,0x00,0x00,    /*"<"=1Ch*/
  0x00,0x14,0x14,0x14,0x14,0x14,0x00,0x00,    /*"="=1Dh*/
  0x00,0x00,0x41,0x22,0x14,0x08,0x00,0x00,    /*">"=1Eh*/
  0x00,0x02,0x01,0x51,0x09,0x06,0x00,0x00,    /*"?"=1Fh*/
  0x00,0x32,0x49,0x79,0x41,0x3E,0x00,0x00,    /*"@"=20h*/
  0x00,0x7E,0x11,0x11,0x11,0x7E,0x00,0x00,    /*"A"=21h*/
  0x00,0x41,0x7F,0x49,0x49,0x36,0x00,0x00,    /*"B"=22h*/
  0x00,0x3E,0x41,0x41,0x41,0x22,0x00,0x00,    /*"C"=23h*/
  0x00,0x41,0x7F,0x41,0x41,0x3E,0x00,0x00,    /*"D"=24h*/
  0x00,0x7F,0x49,0x49,0x49,0x49,0x00,0x00,    /*"E"=25h*/
  0x00,0x7F,0x09,0x09,0x09,0x01,0x00,0x00,    /*"F"=26h*/
  0x00,0x3E,0x41,0x41,0x49,0x7A,0x00,0x00,    /*"G"=27h*/
  0x00,0x7F,0x08,0x08,0x08,0x7F,0x00,0x00,    /*"h"=28h*/
  0x00,0x00,0x41,0x7F,0x41,0x00,0x00,0x00,    /*"I"=29h*/
  0x00,0x20,0x40,0x41,0x3F,0x01,0x00,0x00,    /*"J"=2Ah*/
  0x00,0x7F,0x08,0x14,0x22,0x41,0x00,0x00,    /*"K"=2Bh*/
  0x00,0x7F,0x40,0x40,0x40,0x40,0x00,0x00,    /*"L"=2Ch*/
  0x00,0x7F,0x02,0x0C,0x02,0x7F,0x00,0x00,    /*"M"=2Dh*/
  0x00,0x7F,0x06,0x08,0x30,0x7F,0x00,0x00,    /*"N"=2Eh*/
  0x00,0x3E,0x41,0x41,0x41,0x3E,0x00,0x00,    /*"O"=2Fh*/
  0x00,0x7F,0x09,0x09,0x09,0x06,0x00,0x00,    /*"P"=30h*/
  0x00,0x3E,0x41,0x51,0x21,0x5E,0x00,0x00,    /*"Q"=31h*/
  0x00,0x7F,0x09,0x19,0x29,0x46,0x00,0x00,    /*"R"=32h*/
  0x00,0x26,0x49,0x49,0x49,0x32,0x00,0x00,    /*"S"=33h*/
  0x00,0x01,0x01,0x7F,0x01,0x01,0x00,0x00,    /*"T"=34h*/
  0x00,0x3F,0x40,0x40,0x40,0x3F,0x00,0x00,    /*"U"=35h*/
  0x00,0x1F,0x20,0x40,0x20,0x1F,0x00,0x00,    /*"V"=36h*/
  0x00,0x7F,0x20,0x18,0x20,0x7F,0x00,0x00,    /*"W"=37h*/
  0x00,0x63,0x14,0x08,0x14,0x63,0x00,0x00,    /*"X"=38h*/
  0x00,0x07,0x08,0x70,0x08,0x07,0x00,0x00,    /*"Y"=39h*/
  0x00,0x61,0x51,0x49,0x45,0x43,0x00,0x00,    /*"Z"=3Ah*/
  0x00,0x00,0x7F,0x41,0x41,0x00,0x00,0x00,    /*"["=3Bh*/
  0x00,0x02,0x04,0x08,0x10,0x20,0x00,0x00,    /*"\"=3Ch*/
  0x00,0x00,0x41,0x41,0x7F,0x00,0x00,0x00,    /*"]"=3Dh*/
  0x00,0x04,0x02,0x01,0x02,0x04,0x00,0x00,    /*"^"=3Eh*/
  0x00,0x40,0x40,0x40,0x40,0x40,0x00,0x00,    /*"_"=3Fh*/
  0x00,0x01,0x02,0x04,0x00,0x00,0x00,0x00,    /*"`"=40h*/
  0x00,0x20,0x54,0x54,0x54,0x78,0x00,0x00,    /*"a"=41h*/
  0x00,0x7F,0x48,0x44,0x44,0x38,0x00,0x00,    /*"b"=42h*/
  0x00,0x38,0x44,0x44,0x44,0x28,0x00,0x00,    /*"c"=43h*/
  0x00,0x38,0x44,0x44,0x48,0x7F,0x00,0x00,    /*"d"=44h*/
  0x00,0x38,0x54,0x54,0x54,0x18,0x00,0x00,    /*"e"=45h*/
  0x00,0x00,0x08,0x7E,0x09,0x02,0x00,0x00,    /*"f"=46h*/
  0x00,0x0C,0x52,0x52,0x4C,0x3E,0x00,0x00,    /*"g"=47h*/
  0x00,0x7F,0x08,0x04,0x04,0x78,0x00,0x00,    /*"h"=48h*/
  0x00,0x00,0x44,0x7D,0x40,0x00,0x00,0x00,    /*"i"=49h*/
  0x00,0x20,0x40,0x44,0x3D,0x00,0x00,0x00,    /*"j"=4Ah*/
  0x00,0x00,0x7F,0x10,0x28,0x44,0x00,0x00,    /*"k"=4Bh*/
  0x00,0x00,0x41,0x7F,0x40,0x00,0x00,0x00,    /*"l"=4Ch*/
  0x00,0x7C,0x04,0x78,0x04,0x78,0x00,0x00,    /*"m"=4Dh*/
  0x00,0x7C,0x08,0x04,0x04,0x78,0x00,0x00,    /*"n"=4Eh*/
  0x00,0x38,0x44,0x44,0x44,0x38,0x00,0x00,    /*"o'=4Fh*/
  0x00,0x7E,0x0C,0x12,0x12,0x0C,0x00,0x00,    /*"p"=50h*/
  0x00,0x0C,0x12,0x12,0x0C,0x7E,0x00,0x00,    /*"q"=51h*/
  0x00,0x7C,0x08,0x04,0x04,0x08,0x00,0x00,    /*"r"=52h*/
  0x00,0x58,0x54,0x54,0x54,0x64,0x00,0x00,    /*"s"=53h*/
  0x00,0x04,0x3F,0x44,0x40,0x20,0x00,0x00,    /*"t"=54h*/
  0x00,0x3C,0x40,0x40,0x3C,0x40,0x00,0x00,    /*"u"=55h*/
  0x00,0x1C,0x20,0x40,0x20,0x1C,0x00,0x00,    /*"v"=56h*/
  0x00,0x3C,0x40,0x30,0x40,0x3C,0x00,0x00,    /*"w"=57h*/
  0x00,0x44,0x28,0x10,0x28,0x44,0x00,0x00,    /*"x"=58h*/
  0x00,0x1C,0xA0,0xA0,0x90,0x7C,0x00,0x00,    /*"y"=59h*/
  0x00,0x44,0x64,0x54,0x4C,0x44,0x00,0x00,    /*"z"=5Ah*/
  0x00,0x00,0x08,0x36,0x41,0x00,0x00,0x00,    /*"{"=5Bh*/
  0x00,0x00,0x00,0x77,0x00,0x00,0x00,0x00,    /*"|"=5Ch*/
  0x00,0x00,0x41,0x36,0x08,0x00,0x00,0x00,    /*"}"=5Dh*/
  0x00,0x02,0x01,0x02,0x04,0x02,0x00,0x00,    /*"~"=5Fh*/
  0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00     /*" "=0x60*/
 };

									
/********************************************************************
*Functionname:SendCmd()
*Description :向LCD发送命令
*Inputparam  :Command——命令
*Outputparam :None
*Return      :None
********************************************************************/                                   
void SendCmd(uchar Command)
{
  uchar j, bit7;

  L_CK = 1;
  L_LD = 0;
  L_CS = 0;
  for (j = 0; j < 8; j++)
  {
    bit7 = Command & 0x80;
    if (bit7 == 0)
    {
      L_DA = 0;
    }
    else
    {
      L_DA = 1;
    }

    L_CK = 0;
    L_CK = 1;
    Command = Command << 1;
  }
  
  L_CS = 1;
}

/********************************************************************
*Functionname:SendData()
*Description :向LCD发送数据
*Inputparam  :DData——数据
*Outputparam :None
*Return      :None
********************************************************************/  
void SendData(uchar DDate)
{
  uchar j, bit7;

  L_CK = 1;
  L_LD = 1;
  L_CS = 0;
  
  for (j = 0; j < 8; j++)
  {
    bit7 = DDate & 0x80;
    if (bit7 == 0)
    {
      L_DA = 0;
    }
    else
    {
      L_DA = 1;
    }

    L_CK = 0;
    L_CK = 1;
    DDate = DDate << 1;
  }
  
  L_CS = 1;
}

/********************************************************************
*Functionname:initLCDM()
*Description :LCD初始化
*Inputparam  :None
*Outputparam :None
*Return      :None
********************************************************************/  
void initLCDM(void)
{
  SendCmd(0xa2);
  SendCmd(0xa0);
  SendCmd(0xc8);
  SendCmd(0x40);
  SendCmd(0x2c);
  SendCmd(0x2e);
  SendCmd(0x2f);
  SendCmd(0x26);
  SendCmd(0x81);
  SendCmd(CONTRASTLEVEL);		//设置对比度
  SendCmd(0x1a);
  SendCmd(0xaf);
}

/********************************************************************
*Functionname:ResetLCD()
*Description :LCD复位
*Inputparam  :None
*Outputparam :None
*Return      :None
********************************************************************/ 
void ResetLCD(void)
{
//  P1SEL &= ~0x65; 	        //GPIO
//  P0SEL &= ~0x81;		//GPIO
  P1DIR |= 0x65; 		//输出
  P0DIR |= 0x81;		//输出
  
  L_BK = 1;
  
  L_RS = 1;
  L_RS = 0;
  delay_ms(10);
  L_RS = 1;
  delay_ms(800);
}

/********************************************************************
*Functionname:ClearRAM()
*Description :LCD显示缓冲区清零
*Inputparam  :None
*Outputparam :None
*Return      :None
********************************************************************/ 
void ClearRAM(void)
{
  uint8 i,j;
  for (i = 0; i < 8; i++)
  {
    SendCmd(i|0xb0);
    SendCmd(0x10);
    SendCmd(0x00);
    for (j = 0; j < 132; j++)
    {
      SendData(0);
    }
  }
}

/********************************************************************
*Functionname:Print8()
*Description :LCD显示字符串
*Inputparam  :x------显示位置x坐标
*	      y------显示位置y坐标
*             pstr--要显示的字符串的首地址
*Outputparam :None
*Return      :None
********************************************************************/ 
void Print8(uint8 x, uint8 y, uchar *pstr)
{
  uchar j;
  uint16 addr;
  SendCmd(y|0xb0);
  SendCmd((x >> 4)|0x10);
  SendCmd(x&0x0f);
  
  while (*pstr > 0)
  {
    addr = *pstr++;
    addr = (addr - 0x20)*8;
    for (j = 0; j < 6; j++)
    {
      SendData(ASCIITAB[addr+j]);
    }
  }
}









