#include "UART.h"

void UART_init(void){

uint8_t Baudratedecimal;
uint16_t Baudrateinteger;
	
	//enable the uart clock and the port clock and resit the uart before it is used
    SET_BIT(SYSCTL_RCGCUART_R,0); 
    SET_BIT(SYSCTL_RCGCGPIO_R,0); 
    CLEAR_BIT(UART0_CTL_R,0); 
// initiallize the baudrate integer and fractional registers
 // Baudrateinteger= ((CLOCK)/(16*UART_BAUDRATE)) = 16000000/16x9600 =104.1666667
	Baudrateinteger=104;
  UART0_IBRD_R = Baudrateinteger; 
    // Baudratedecimal = ( 0.16667*64) +0.5=11.166667 ; 
	Baudratedecimal=11 ;
    UART0_FBRD_R =  Baudratedecimal ; 
	// Set the word Length to 8 bit and Enable FIFOS , 1 Stop Bit , Parity Disabled
	 UART0_LCRH_R |= (UART_LCRH_WLEN_8|UART_LCRH_FEN);
//enable transmitter and reciever of UART0	
    SET_BIT(UART0_CTL_R,8); 
	  SET_BIT(UART0_CTL_R,9); 
	 // Enable UART0 After Configuration
	  SET_BIT(UART0_CTL_R,0);
	//initiallize the port itself
    GPIO_PORTA_AFSEL_R |= 0x03;  
    GPIO_PORTA_PCTL_R =  ( (GPIO_PORTA_PCTL_R & 0xFFFFFF00) | 0x00000011 ); 
    GPIO_PORTA_DEN_R |= 0x03; 
    GPIO_PORTA_AMSEL_R &= ~0x03; 
}

void printchar(const uint8_t character){ 
    while((UART0_FR_R&UART_FR_TXFF) != 0); // booling until the sending FIFO is not EMPTY
    UART0_DR_R = character;
}





uint8_t recievebyte(void){
    while((UART0_FR_R&UART_FR_RXFE)!= 0); // booling until the receiving FIFO is not EMPTY
    return((unsigned char)(UART0_DR_R&0xFF));
}
void printstring(const char *Str){
	uint8_t x = 0;
	while(Str[x] != '\0')
	{
		printchar(Str[x]);
		x++;
	}
}


