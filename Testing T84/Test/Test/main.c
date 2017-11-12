/*
 * Test.c
 *
 * Created: 11/11/2017 11:04:30 PM
 * Author : Orange
 */ 

#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 8000000


int main(void)
{

	//Set pin to output
	DDRB |= (1 << PB2);

    /* Replace with your application code */
    while (1) 
    {
		// 
		PORTB = (1 << PB2);
		
		// Wait one second
		_delay_ms(1000);
		
		PORTB = ~(1 << PB2);
		
		// Wait one second
		_delay_ms(1000);

    }

	return 1;
}

