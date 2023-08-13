#include <at89c5131.h>
#include "lcd.h"		//Header file with LCD interfacing functions
#include "serial.c"	//C file with UART interfacing functions
#include "timer.c"

//Test function definitions
void dot()
{
	TR0 = 1;
	j = 800;
	while(j != 0){}
	TR0 = 0;
}
void dash()
{
	TR0 = 1;
	j = 1600;
	while(j != 0){}
	TR0 = 0;
}
//Main function
void main(void)
{ 
	unsigned char ch=0;
	
	//Call initialization functions
	lcd_init();
	uart_init();
	timer_init();
	//These strings will be printed in terminal software
	transmit_string("Press any ALPHANUMERIC KEY to listen audio tunes corresponding to Morse Code\r\n");
	while(1)
	{ 
	      lcd_cmd(0x01);
		    lcd_cmd(0x80);
	      lcd_write_string("Input Please");
		    
		    ES = 1;           //Enable Serial Interrupt
		    REN = 1;			    //Recieve Enable
			      
			  ch = receive_char();  //Receive a character
		    REN = 0;			    //Recieve Disable
		    ES = 0;           //Disable Serial Interrupt
			        //Decide which test function to run based on character sent
			      switch(ch)
			      {
				       case 'A':lcd_cmd(0x01);
								        dot();
							          msdelay(1000);
							          dash();
								        break;
				
			     	   case 'B':lcd_cmd(0x01);
								        dash();
							          msdelay(1000);
							          dot();
							          msdelay(1000);
							          dot();
							          msdelay(1000);
							          dot();
								    break;
							 case 'C':lcd_cmd(0x01);
								        dash();
							          msdelay(1000);
							          dot();
							          msdelay(1000);
							          dash();
							          msdelay(1000);
							          dot();
								    break;
							 case 'D':lcd_cmd(0x01);
								        dash();
							          msdelay(1000);
							          dot();
							          msdelay(1000);
												dot();
								    break;
							 case 'E':lcd_cmd(0x01);
								        dot();
								    break;
							 case 'F':lcd_cmd(0x01);
								        dot();
												msdelay(1000);
												dot();
												msdelay(1000);
												dash();
												msdelay(1000);
												dot();
												
								    break;
							 case 'G':lcd_cmd(0x01);
								        dash();
							          msdelay(1000);
												dash();
												msdelay(1000);
							          dot();
								    break;
							 case 'H':lcd_cmd(0x01);
								        dot();
												msdelay(1000);
												dot();
												msdelay(1000);
												dot();
												msdelay(1000);
												dot();
								    break;
							 case 'I':lcd_cmd(0x01);
								        dot();
												msdelay(1000);
												dot();
								    break;
							 case 'J':lcd_cmd(0x01);
								        dot();
							          msdelay(1000);
							          dash();
												msdelay(1000);
							          dash();
												msdelay(1000);
							          dash();
								    break;
							 case 'K':lcd_cmd(0x01);
							          dash();
												msdelay(1000);
												dot();
							          msdelay(1000);
							          dash();
								    break;
							 case 'L':lcd_cmd(0x01);
								        dot();
							          msdelay(1000);
							          dash();
												msdelay(1000);
												dot();
							          msdelay(1000);
							          dot();
								    break;
							 case 'M':lcd_cmd(0x01);
							          dash();
												msdelay(1000);
												dash();
								    break;
								case 'N':lcd_cmd(0x01);
							          dash();
												msdelay(1000);
												dot();
								    break;
							  case 'O':lcd_cmd(0x01);
							          dash();
												msdelay(1000);
												dash();
												msdelay(1000);
												dash();
								    break;
							 case 'P':lcd_cmd(0x01);
								        dot();
												msdelay(1000);
								        dash();
												msdelay(1000);
												dash();
												msdelay(1000);
												dot();
								    break;
								case 'Q':lcd_cmd(0x01);
							          dash();
												msdelay(1000);
												dash();
												msdelay(1000);
												dot();
												msdelay(1000);
												dash();
								    break;
							 case 'R':lcd_cmd(0x01);
								        dot();
												msdelay(1000);
								        dash();
												msdelay(1000);
												dot();
								    break;
							  case 'S':lcd_cmd(0x01);
								        dot();
												msdelay(1000);
								        dot();
												msdelay(1000);
												dot();
								    break;
							  case 'T':lcd_cmd(0x01);
								        dash();
								    break;
							  case 'U':lcd_cmd(0x01);
								        dot();
												msdelay(1000);
								        dot();
												msdelay(1000);
												dash();
								    break;
							  case 'V':lcd_cmd(0x01);
								        dot();
												msdelay(1000);
								        dot();
												msdelay(1000);
												dot();
												msdelay(1000);
												dash();
								    break;
						  	case 'W':lcd_cmd(0x01);
								        dot();
												msdelay(1000);
								        dash();
												msdelay(1000);
												dash();
								    break;
							  case 'X':lcd_cmd(0x01);
								        dash();
												msdelay(1000);
												dot();
												msdelay(1000);
								        dot();
												msdelay(1000);
												dash();
								    break;
							  case 'Y':lcd_cmd(0x01);
								        dash();
												msdelay(1000);
												dot();
												msdelay(1000);
								        dash();
												msdelay(1000);
												dash();
								    break;
							  case 'Z':lcd_cmd(0x01);
								        dash();
												msdelay(1000);
												dash();
												msdelay(1000);
								        dot();
												msdelay(1000);
												dot();
								    break;
								case '0':lcd_cmd(0x01);
								        dash();
												msdelay(1000);
												dash();
												msdelay(1000);
								        dash();
												msdelay(1000);
												dash();
												msdelay(1000);
												dash();
								    break;
							  case '1':lcd_cmd(0x01);
								        dot();
												msdelay(1000);
												dash();
												msdelay(1000);
								        dash();
												msdelay(1000);
												dash();
												msdelay(1000);
												dash();
								    break;
							  case '2':lcd_cmd(0x01);
								        dot();
												msdelay(1000);
												dot();
												msdelay(1000);
								        dash();
												msdelay(1000);
												dash();
												msdelay(1000);
												dash();
								    break;
							  case '3':lcd_cmd(0x01);
								        dot();
												msdelay(1000);
												dot();
												msdelay(1000);
								        dot();
												msdelay(1000);
												dash();
												msdelay(1000);
												dash();
								    break;
							 case '4':lcd_cmd(0x01);
								        dot();
												msdelay(1000);
												dot();
												msdelay(1000);
								        dot();
												msdelay(1000);
												dot();
												msdelay(1000);
												dash();
								    break;
							  case '5':lcd_cmd(0x01);
								        dot();
												msdelay(1000);
												dot();
												msdelay(1000);
								        dot();
												msdelay(1000);
												dot();
												msdelay(1000);
												dot();
								    break;
						  	case '6':lcd_cmd(0x01);
								        dash();
												msdelay(1000);
												dot();
												msdelay(1000);
								        dot();
												msdelay(1000);
												dot();
												msdelay(1000);
												dot();
								    break;
							  case '7':lcd_cmd(0x01);
								        dash();
												msdelay(1000);
												dash();
												msdelay(1000);
								        dot();
												msdelay(1000);
												dot();
												msdelay(1000);
												dot();
								    break;
							 case '8':lcd_cmd(0x01);
								        dash();
												msdelay(1000);
												dash();
												msdelay(1000);
								        dash();
												msdelay(1000);
												dot();
												msdelay(1000);
												dot();
								    break;
							 case '9':lcd_cmd(0x01);
								        dash();
												msdelay(1000);
												dash();
												msdelay(1000);
								        dash();
												msdelay(1000);
												dash();
												msdelay(1000);
												dot();
							
				       default:lcd_cmd(0x80);
	                     lcd_write_string("Invalid Input");
	                     msdelay(2000);
	                     lcd_cmd(0x01);
								    break;
				
			}
	}
}
/*void Timer0_int(void) interrupt 1
{
	TR0 = 0;
	output = !output;
	j--;
	TL0 = 0x4c;           //load TL and TH values for 2 ms delay
	TH0 = 0x0f6;
	TR0 = 1;
}*/