#include <at89c5131.h>
bit tx_complete = 0,rx_complete = 0; //Bit flags for interrupts	
sbit f = PSW^1;
void uart_init(void)
{
	TMOD|= 0x20;
	TMOD&=0x2f;			//Configure Timer 1 in Mode 2
	TH1 = 243;					//Load TH1 to obtain require Baudrate (Refer Serial.pdf for calculations)
	SCON=0x40;			//Configure UART peripheral for 8-bit data transfer 
	TR1 = 1;			//Start Timer 1
	EA = 1;			  //Enable Global Interrupt
	ES = 1;				//Enable Serial Interrupt
}

void transmit_char(unsigned char ch)
{
	SBUF=ch;				//Load data in SBUF
	while(!tx_complete); 			//Wait for tx_complete flag (interrupt to complete)
	tx_complete = 0;		//Clear tx_complete flag 
}

void transmit_string(unsigned char *s)
{
	while(*s != 0)
	{
			transmit_char(*s++);
	}
}

unsigned char receive_char(void)
{
	unsigned char ch = 0;
	while(!rx_complete);				//Wait for rx_complete(interrupt to complete)
	rx_complete = 0;
	ch = SBUF;					//Read data from SBUF
	return ch;					//Return read character
}
	

void serial_ISR(void) interrupt 4
{
		if(TI==1)			//check whether TI is set
		{
			TI = 0;			//Clear TI flag
			tx_complete = 1;	//Set tx_complete flag indicating interrupt completion
		}
		else if(RI==1)			//check whether RI is set
		{
			RI = 0;			//Clear RI flag
			rx_complete = 1;	//Set rx_complete flag indicating interrupt completion
		}
}