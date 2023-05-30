
# define F_CPU 8000000
#include<util/delay.h>
/************************/
#include "MemoryMap.h"
#include "UTILS.h"
#include "StdTypes1.h"
/************************/
#include "DIO_interface.h"
#include "LCD.h"
#include "KeyPad.h"
#include "CALC.h"

/************************/


	
	

int main(void)
{ 
	DIO_Init();
	LCD_Init();	
	KEYPAD_Init();
	
   
   while(1)
   {
	NUMERIC_CONV_Runnable();
   }

 }


