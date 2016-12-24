/*######################################################################
		Program to interface Servo motor using Header file
	****************************************************************************
	Target system-AVR devlopment board s/n-118010
	microcontroller: ATmega-8
	clock: 12mhz
	compiler WinAVR-20100110
	********************************************************************************
	Lower Right (LR)------>PORTB 0
	Lower Left  (LL)------>PORTB 1
	Upper Right (UR)------>PORTB 2
	Upper Left  (UL)------>PORTB 3
	********************************************************************************/

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

// **************************************** Flip **************************************
			
			mov(200,3);
			mov(-40,2);
			
			_delay_ms(2000);
			
			mov(125,0);
			mov(55,1);
			_delay_ms(500);
			mov(55,0);
			mov(125,1);
			_delay_ms(500);
			mov(90,0);
			mov(90,1);
			_delay_ms(500);
			
			mov(90,3);
			mov(90,2);
			
			_delay_ms(1000);
			}
			}
			}