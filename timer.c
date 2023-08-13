#include <at89c5131.h>

sbit output = P0^5;
sbit flag = PSW^5;
	unsigned int j;
void timer_init(void)
{
	  TMOD|=0x01;
		TMOD&=0xf1;       //configure timer 0 in mode 1
	  TL0 = 0x4c;           //load TL and TH values for 2 ms delay
	  TH0 = 0x0f6;           
	  EA = 1;         //enable global interrupt
	  ET0 = 1;        //enable timer 0 interrupts
	  TR0 = 0;
}
void Timer0_int(void) interrupt 1
{
	TR0 = 0;
	output = !output;
	j--;
	TL0 = 0x4c;           //load TL and TH values for 2 ms delay
	TH0 = 0x0f6;
	TR0 = 1;
}