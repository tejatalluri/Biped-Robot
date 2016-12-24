#include <avr/io.h>
	#include <avr/interrupt.h>
	#include<util/delay.h>
	#include "servo.h"
	#define DELAY 300
	stop()
	{
		mov(90,0);		//LR
		mov(80,1);		//LL
		mov(90,2);		//UR
		mov(90,3);		//UL
	}

	int main()
	 {
	 
	 DDRC=0x00;
	 PORTC=0x0f;
	 
	 servo_init();
	 
		stop();
	 _delay_ms(2000);
	 
	 while(1)
	   {
		if((PINC & 0x01) == 0x00)
		{
			while((PINC & 0x01)==0x00);
			while(1)
			{
			  
			for (char i=0;i<=55;i++)		// RIGHT leg UP
			{
			mov(90-i,2);
			_delay_ms(5);
			}
			for (char i=0;i<=55;i++)		// RIGHT leg DOWN
			{
			mov(45+i,2);
			_delay_ms(5);
			}
			
			for (char i=0;i<=55;i++)		// LEFT leg UP
			{
			mov(90+i,3);
			_delay_ms(5);
			}
			for (char i=0;i<=55;i++)		// LEFT leg DOWN
			{
			mov(145-i,3);
			_delay_ms(5);
			}
			
			}
			
		    }
			}
			}
			