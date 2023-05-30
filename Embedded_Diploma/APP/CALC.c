#include "StdTypes1.h"
#include "KeyPad.h"
#include "LCD.h"
#include "CALC.h"

 
u8 GREET_FLAG=0;
u8 DEC_NUM=0,HEX_NUM=0,BIN_NUM=0;   //these are the numbers taken from stage {from dec or hex or bin}

u8 FROM_CHOICE=0;
u8 TO_CHOICE=0;

u8 DEC_FLAG_EXIT=0;
u8 HEX_FLAG_EXIT=0;
u8 BIN_FLAG_EXIT=0;

u8 dec2dec_exit=0,dec2hex_exit=0,dec2bin_exit=0;
u8 hex2dec_exit=0,hex2hex_exit=0,hex2bin_exit=0;
u8 bin2dec_exit=0,bin2hex_exit=0,bin2bin_exit=0;

void NUMERIC_CONV_Runnable(void) //done
{
	if(GREET_FLAG==0){
	LCD_SetCursor(0,0);
	LCD_WriteString("Hello!");
	_delay_ms(500);
	LCD_WriteString("        ");
	LCD_SetCursor(0,0);
	LCD_WriteString("CONVERT NUMBERS");
	_delay_ms(500);
	LCD_WriteString("                                      ");
	_delay_ms(500);
	}
	LCD_SetCursor(0,0);
	LCD_WriteString("Convert from...");
	LCD_SetCursor(1,0);
	LCD_WriteString("1:DEC 2:HEX 3:BIN");
	FROM_CHOICE=CALC_ScanNum();
	GREET_FLAG=1; // you willn't see the greeting again
	if(FROM_CHOICE==1) // FROM_DECIMAL
	{
      CALC_DecHandeller();
	}
	else if(FROM_CHOICE==2) // from hex
	{
	  CALC_HexHandeller();
	}
	else if(FROM_CHOICE==3) // from hex
	{
		CALC_BinHandeller();
	}
} 

void CALC_DecHandeller(void)//done
{
	LCD_Clear();
	while(DEC_FLAG_EXIT==0)
	{
		LCD_SetCursor(0,0);
		LCD_WriteString("from DEC to ...");
		LCD_SetCursor(1,0);
		LCD_WriteString("1:DEC 2:HEX 3:BIN");
		TO_CHOICE=CALC_ScanNum();
		
		if(TO_CHOICE==1) // from dec to dec
		{
			LCD_Clear();
			while(dec2dec_exit==0)
			{
				
				LCD_SetCursor(0,0);
				LCD_WriteString("DEC:");
				DEC_NUM=CALC_ScanNum();
				LCD_WriteString("          ");
				LCD_SetCursor(1,0);
				LCD_WriteString("DEC:");
				LCD_WriteNumber(DEC_NUM);
				LCD_WriteString("          ");
				//_delay_ms(2000);
				if(DEC_NUM=='c')
				{
					dec2dec_exit=1;
				}
			}
		}
		else if(TO_CHOICE==2) // from dec to hex
		{
			LCD_Clear();
			while(dec2hex_exit==0){
				LCD_SetCursor(0,0);
				LCD_WriteString("DEC:");
				DEC_NUM=CALC_ScanNum();
				LCD_WriteString("          ");
				LCD_SetCursor(1,0);
				LCD_WriteString("HEX:");
				LCD_WriteNumberInHexa(DEC_NUM);
				LCD_WriteString("          ");
				if(DEC_NUM=='c')
				{
					dec2hex_exit=1;
				}
			}
		}
		else if(TO_CHOICE==3) // from dec to bin
		{
			LCD_Clear();
			while(dec2bin_exit==0){
				LCD_SetCursor(0,0);
				LCD_WriteString("DEC:");
				DEC_NUM=CALC_ScanNum();
				LCD_WriteString("          ");
				LCD_SetCursor(1,0);
				LCD_WriteString("BIN:");
				LCD_WriteNumInBin(DEC_NUM);
				LCD_WriteString("          ");
				if(DEC_NUM =='c')
				{
					dec2bin_exit=1;
				}
			}
			
		}
		
		
		else if(TO_CHOICE=='c')
		{
			DEC_FLAG_EXIT=1;
		}
		else
		{
			LCD_Clear();
			LCD_WriteString("WRONG INPUT");
		}
	}
}
/***************************************************************************************************/

void CALC_HexHandeller(void) //done
{
	LCD_Clear();
	while(HEX_FLAG_EXIT==0)
	{
		LCD_SetCursor(0,0);
		LCD_WriteString("from HEX to ...");
		LCD_SetCursor(1,0);
		LCD_WriteString("1:DEC 2:HEX 3:BIN");
		TO_CHOICE=CALC_ScanNum();
		
		if(TO_CHOICE==1) // from HEX to dec
		{
			LCD_Clear();
			while(hex2dec_exit==0)
			{
				
				LCD_SetCursor(0,0);
				LCD_WriteString("HEX:");
				HEX_NUM=CALC_ScanHexNum();
				LCD_WriteString("          ");
				LCD_SetCursor(1,0);
				LCD_WriteString("DEC:");
				LCD_WriteNumber(HEX_NUM);
				LCD_WriteString("          ");
				//_delay_ms(2000);
				if(HEX_NUM=='c')
				{
					hex2dec_exit=1;
				}
			}
		}
		else if(TO_CHOICE==2) // from hex to hex
		{
			LCD_Clear();
			while(hex2hex_exit==0)
			{
			LCD_SetCursor(0,0);
			LCD_WriteString("HEX:");
			HEX_NUM=CALC_ScanHexNum();
			LCD_WriteString("       ");
			LCD_SetCursor(1,0);
			LCD_WriteString("HEX:");
			LCD_WriteNumberInHexa(HEX_NUM);
			LCD_WriteString("       ");
			if(HEX_NUM=='c')
			{
				hex2hex_exit=1;
			}
			}
		}
		else if(TO_CHOICE==3) // from dec to bin
		{
			LCD_Clear();
			while(hex2bin_exit==0)
			{
			LCD_SetCursor(0,0);
			LCD_WriteString("HEX:");
			HEX_NUM=CALC_ScanHexNum();
			LCD_WriteString("       ");
			LCD_SetCursor(1,0);
			LCD_WriteString("BIN:");
			LCD_WriteNumInBin(HEX_NUM);
			LCD_WriteString("       ");
			if(HEX_NUM=='c')
			{
				hex2bin_exit=1;
			}
			}
		}
		else if(TO_CHOICE=='c')
		{
			HEX_FLAG_EXIT=1;
		}
		else
		{
			LCD_Clear();
			LCD_WriteString("WRONG INPUT");
		}
	}
}





void CALC_BinHandeller(void) //done
{
	LCD_Clear();
	while(BIN_FLAG_EXIT==0)
 {
	LCD_SetCursor(0,0);
	LCD_WriteString("from BIN to ...");
	LCD_SetCursor(1,0);
	LCD_WriteString("1:DEC 2:HEX 3:BIN");
	
	TO_CHOICE=CALC_ScanNum(); // taking the option for the second time
	if(TO_CHOICE==1) //bin 2 dec
	{
		LCD_Clear();
		while(bin2dec_exit==0)
		{
		LCD_SetCursor(0,0);
		LCD_WriteString("BIN:");
		BIN_NUM=CALC_ScanBinNum();
		LCD_WriteString("          ");
		LCD_SetCursor(1,0);
		LCD_WriteString("DEC:");
		LCD_WriteNumber(BIN_NUM);
		LCD_WriteString("          ");
		if(BIN_NUM =='c')
		{
			bin2dec_exit=1;
		}
		}
	}
	else if(TO_CHOICE==2)
	{
		LCD_Clear();
		while(bin2hex_exit==0)
		{
		LCD_SetCursor(0,0);
		LCD_WriteString("BIN:");
		BIN_NUM=CALC_ScanBinNum();
		LCD_WriteString("          ");
		LCD_SetCursor(1,0);
		LCD_WriteString("HEX:");
		LCD_WriteNumberInHexa(BIN_NUM);
		LCD_WriteString("          ");
		if(BIN_NUM=='c')
		{
			bin2hex_exit=1;
		}
		}
	}
	else if(TO_CHOICE==3)
	{
		LCD_Clear();
		while(bin2bin_exit==0)
		{
		LCD_SetCursor(0,0);
		LCD_WriteString("BIN:");
		BIN_NUM=CALC_ScanBinNum();
		LCD_WriteString("          ");
		LCD_SetCursor(1,0);
		LCD_WriteString("BIN:");
		LCD_WriteNumInBin(BIN_NUM);
		LCD_WriteString("          ");
		if(BIN_NUM=='c')
		{
			bin2bin_exit=1;
		}
		}
	}
	else if(TO_CHOICE=='c')
	{
		BIN_FLAG_EXIT=1;
	}
	else
	{
		LCD_Clear();
		LCD_WriteString("WRONG INPUT");
	}
 }
}


u16 CALC_ScanNum(void)
{
	u8 key='n';
	u16 num=0;
	
	while(key != '=')
	{
	  key=KEYPAD_Get_Key();
	  if (key != NO_KEY)
	  {
		
		if ( (key>='0' && key<='9') )
		{
			num=num*10+key-'0';
			LCD_WriteChar(key);
		}
		else if (key == 'c')
		{
			num='c';
		}
		
	  }
	}
 
 return num;
}

u16 CALC_ScanHexNum(void)
{
	u8 key='n';
	u16 num=0;
	
	while(key != '=')
	{
		key=KEYPAD_Get_Key();
		if (key != NO_KEY)
		{
			
			if ( (key>='0' && key<='9') )
			{
				num=num*16+key-'0';
				LCD_WriteChar(key);
			}
			else if((key>= 'A' && key<= 'D'))
			{
				num=num*16+(key-'A'+10);
				LCD_WriteChar(key);
			}
			else if (key == 'c')
			{
				num='c';
			}
		}
	}
	
	return num;
}

u16 CALC_ScanBinNum(void)
{
	u8 key='n';
	u16 num=0;
	
	while(key != '=')
	{
		key=KEYPAD_Get_Key();
		if (key != NO_KEY)
		{
			
			if ( (key>='0' && key<='1') )
			{
				num=num*2+key-'0';
				LCD_WriteChar(key);
			}
			else if (key == 'c')
			{
				num='c';
			}
			
		}
	}
	
	return num;
}






