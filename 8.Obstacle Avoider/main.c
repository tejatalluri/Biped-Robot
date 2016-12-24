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
	   	for (char i=0;i<=35;i++)	// left leg forward 	
			{						    // UR MOTOR TO RIGHT DRIRECTION
			mov(90-i,2);
			_delay_ms(15);
			}
			
			for (char i=0;i<=25;i++) // LR MOTOR TO RIGHT DRIRECTION
			{
			mov(90-i,0);
			_delay_ms(15);
			}
			
			for (char i=0;i<=35;i++) // LL MOTOR TO LEFT DRIRECTION
			{
			mov(90-i,1);
			_delay_ms(40);
			}
			for (char i=0;i<=30;i++)		// UR MOTOR TO LEFT DRIRECTION
			{
			mov(65+i,2);
			_delay_ms(15);
			}
			for (char i=0;i<=40;i++)		// Right leg forward 
			{          					 // UR MOTOR TO RIGHT DRIRECTION
			mov(90+i,3);
			_delay_ms(15);
			}
			
			for (char i=0;i<=0;i++) // LL MOTOR TO LEFT DRIRECTION
			{
			mov(90+i,1);
			_delay_ms(15);
			}
			
			for (char i=0;i<=05;i++) // LR MOTOR TO LEFT DRIRECTION
			{
			mov(90+i,0);
			_delay_ms(15);
			}
			
			for (char i=0;i<=40;i++)// UR MOTOR TO LEFT DRIRECTION
			{
			mov(130-i,3);
			_delay_ms(15);
			}
			
		if((PINC & 0x01) == 0x00)
		{  
		for(char x=1;x<=3;x++)
			{
		
			for (char i=0;i<=40;i++)		// Right leg forward
			{								// UL MOTOR TO RIGHT DRIRECTION
			mov(90+i,3);
			_delay_ms(15);
			}
			
			for (char i=0;i<=40;i++) //  LL MOTOR TO LEFT DRIRECTION
			{
			mov(90-i,1);
			_delay_ms(15);
			}
			
			for (char i=0;i<=27;i++)//  Lr MOTOR TO RIGHT DRIRECTION
			{
			mov(90-i,0);
			_delay_ms(15);
			}
			
			for (char i=0;i<=40;i++)// UL MOTOR TO LEFT DRIRECTION
			{
			mov(130-i,3);
			_delay_ms(15);
			}
			 
			for (char i=0;i<=35;i++)		// Left leg forward
			{								//UR TO RIGHT DIR
			mov(90-i,2);
			_delay_ms(15);
			}
			
			for (char i=0;i<=33;i++)
			{
			mov(90+i,0);
			_delay_ms(15);
			}
			
			for (char i=0;i<=17;i++)
			{
			mov(90+i,1);
			_delay_ms(40);
			}
			for (char i=0;i<=30;i++)		
			{
			mov(65+i,2); // //UR TO LEFT DIR
			_delay_ms(15);
			}
			
			   
		
			}
			
	}
		}}