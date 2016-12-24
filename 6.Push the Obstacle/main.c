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
		for (char i=0;i<=35;i++)		// Left leg forward
			{
			mov(90-i,2);
			_delay_ms(10);
			}
		for (char i=0;i<=45;i++)
			{
			mov(90-i,0);
			_delay_ms(5);
			}
			for (char i=0;i<=45;i++)
			{
			mov(45+i,0);
			_delay_ms(5);
			}
			
		for (char i=0;i<=35;i++)		
			{
			mov(55+i,2);
			_delay_ms(10);
			}
			}}}