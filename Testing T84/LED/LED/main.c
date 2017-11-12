/*
 * LED.c
 *
 * Created: 11/12/2017 10:42:14 AM
 * Author : SMP
 */ 

#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 8000000UL

int main(void)
{

	// Set delay time
	const int delay_time = 500;

	// Set PORTA5 and PORTA7 to output
	DDRA |= ((1 << PA5) | (1 << PA7));

	// Set PORTB2 to output
	DDRB |= (1 << PB2);

    while (1) 
    {
		// Turn on PA5
		PORTA |= (1 << PA5);
		PORTB &= ~(1 << PB2);

		_delay_ms(delay_time);

		// Turn on PA7
		PORTA &= ~(1 << PA5);
		PORTA |= (1 << PA7);

		_delay_ms(delay_time);

		// Turn on PB2
		PORTA &= ~(1 << PA7);
		PORTB |= (1 << PB2);

		_delay_ms(delay_time);
		
    }

	return 1;
}

