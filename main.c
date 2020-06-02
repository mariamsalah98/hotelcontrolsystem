#include "common_macros.h"
#include "uart.h"
#include "gpio.h"
#include "KPD.h"
#include "stdint.h"
#include "C:\Keil_v5\EE319Kware\inc/tm4c123gh6pm.h"
#ifndef CLOCK
#define CLOCK 16000000UL
#endif
int delay = 0 ;
//void SystemInit() {}
void init (void)
 {
	 UART_init();
	 delay=delay+1 ;
	 GPIO_clkEnable(Port_F) ;
	 delay=delay+1 ;
	 GPIO_init(Port_F);
	 GPIO_setPinDirection( Port_F ,  Pin1 ,OUTPUT);
	 GPIO_clkEnable(Port_B) ;
	 GPIO_init(Port_B);
	 GPIO_setPortDirection(Port_B ,0xF0 );
	 GPIO_clkEnable(Port_B);
	 delay=delay+1 ;
}
 int main(void)
 {
	 init();
	 while(1)
	 {
		 printstring("It's setup mode please enter room numbers \n\r");
		 u8 roomarray[10] ;
		 for(int i = 0 ;  ;i++)
		 {
			 roomarray[i]=recievebyte();
			 if (roomarray[i]=='#')
				 break ;
		 }
		 printstring("setup mode is done please enter a room number \n\r");
		 	 u8 room ;
	room =  recievebyte();
		   for(int i = 0 ; i<3;i++)
		 {
			 if(room==roomarray[i])
			 {
		 printstring("please enter the room status \n\r");
		 u8 status ;
		 status =recievebyte();
		 switch(status)
		 {
			 case '1' :
				printstring(" please enter a password \n\r");
		    u8 password[4] ;
		     for(int i = 0 ; i<4;i++)
			 {
				 password[i]=recievebyte();
			 } 
			   u8 KPD_Array[3][4] ;
			  u8 pass[4] ;
			     for(int i = 0 ; i<4;i++)
			 {
				 KPD_ScanKeys(KPD_Array);
			   KPD_GetKeys( KPD_Array ,&pass[i]); 
			 }   
			   if((password[0]==pass[0]) &&(password[1]==pass[1]) && (password[2]==pass[2]) && (password[3]==pass[3]))
					  GPIO_setPinValue(Port_F ,Pin1 , HIGH);
				 else
					 GPIO_setPinValue(Port_F ,Pin1 , LOW);
			 case '2' :
				 GPIO_setPinValue(Port_F ,Pin1 , HIGH);
			 case '3' :
				 GPIO_setPinValue(Port_F ,Pin1 , LOW);
			 default :
				 GPIO_setPinValue(Port_F ,Pin1 , LOW);
		}
	}
		else
			 printstring("room does not exist \n\r");
		 }
	}
		  }
