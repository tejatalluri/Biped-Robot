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
			
// ***************************************** Right Leg Up ***************************************
			
			for (char i=0;i<=120;i++)
			{
			mov(90+i,3);
			_delay_ms(20);
			}
			
			for (char i=0;i<=100;i++)
			{
			mov(90-i,2);
			_delay_ms(20);
			}
			
			_delay_ms(600);
			
// **************************************** Right Leg Down **************************************
			
			for (char i=0;i<=100;i++)
			{
			mov((-10+i),2);
			_delay_ms(20);
			}
			
			for (char i=0;i<=130;i++)
			{
			mov(220-i,3);
			_delay_ms(20);
			}
			
			_delay_ms(600);
			
// ***************************************** Left Leg Up ***************************************
			
			for (char i=0;i<=130;i++)
			{
			mov(90-i,2);
			_delay_ms(20);
			}
			
			for (char i=0;i<=120;i++)
			{
			mov(90+i,3);
			_delay_ms(20);
			}
			
			_delay_ms(600);
			
// **************************************** Left Leg Down **************************************
			
			for (char i=0;i<=120;i++)
			{
			mov(210-i,3);
			_delay_ms(20);
			}
			
			for (char i=0;i<=140;i++)
			{
			mov((-40+i),2);
			_delay_ms(20);
			}
			
			_delay_ms(1000);
			
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
			
// **************************************** Walking **************************************
			
			while(1)
			{
			
			for (char i=0;i<=40;i++)		// Right leg forward
			{
			mov(90+i,3);
			_delay_ms(15);
			}
			
			for (char i=0;i<=20;i++)
			{
			mov(90+i,1);
			_delay_ms(15);
			}
			
			for (char i=0;i<=30;i++)
			{
			mov(90+i,0);
			_delay_ms(15);
			}
			
			for (char i=0;i<=40;i++)
			{
			mov(130-i,3);
			_delay_ms(15);
			}
			
			for (char i=0;i<=35;i++)		// Left leg forward
			{
			mov(90-i,2);
			_delay_ms(15);
			}
			
			for (char i=0;i<=5;i++)
			{
			mov(90+i,0);
			_delay_ms(15);
			}
			
			for (char i=0;i<=0;i++)
			{
			mov(90+i,1);
			_delay_ms(40);
			}
			
			for (char i=0;i<=35;i++)
			{
			mov(55+i,2);
			_delay_ms(15);
			}
			
			}
			
			
			
			
			
			//_delay_ms(1000);
		
	
		}
	   
	   
	   /*for(char i=0;i<=10;i++)
		forward();
		stop();
		_delay_ms(2000);
	   for(char i=0;i<=10;i++)
		backward();	
		stop();
		_delay_ms(2000);*/
	   }
	 }