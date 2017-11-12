/*
 * PWM.c
 *
 * Created: 11/12/2017 11:23:20 AM
 * Author : Orange
 */ 

#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 8000000UL

const uint8_t gamma8[] = {
	0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,
	1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,
	2,  3,  3,  3,  3,  3,  3,  3,  4,  4,  4,  4,  4,  5,  5,  5,
	5,  6,  6,  6,  6,  7,  7,  7,  7,  8,  8,  8,  9,  9,  9, 10,
	10, 10, 11, 11, 11, 12, 12, 13, 13, 13, 14, 14, 15, 15, 16, 16,
	17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 24, 24, 25,
	25, 26, 27, 27, 28, 29, 29, 30, 31, 32, 32, 33, 34, 35, 35, 36,
	37, 38, 39, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 50,
	51, 52, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 66, 67, 68,
	69, 70, 72, 73, 74, 75, 77, 78, 79, 81, 82, 83, 85, 86, 87, 89,
	90, 92, 93, 95, 96, 98, 99,101,102,104,105,107,109,110,112,114,
	115,117,119,120,122,124,126,127,129,131,133,135,137,138,140,142,
	144,146,148,150,152,154,156,158,160,162,164,167,169,171,173,175,
	177,180,182,184,186,189,191,193,196,198,200,203,205,208,210,213,
215,218,220,223,225,228,231,233,236,239,241,244,247,249,252,255 };

const int delay_time = 5;


int main(void){
	// Data direction of PORTB2 to output
	DDRB |= (1 << PB2);
	DDRA |= (1 << PA7) | (1 << PA5);

	// Clear on compare match, fast PWM timers 0 and 1  (pg 80)
	TCCR0A = (1 << COM0A1) | (1 << COM0B1) | (1 << WGM00) | (1 << WGM01);
	TCCR1A = (1 << COM0B1) | (1 << WGM00) | (1 << WGM01);

	// No scaling
	TCCR0B = (1 << CS00);
	TCCR1B = (1 << CS00);

	// Start all at 0
	OCR0A = 0;
	OCR0B = 0;
	OCR1B = 0;

	while(1){
		for(int i = 0; i < 256; i++){
			OCR0A = gamma8[i];
			_delay_ms(delay_time);
		}
		for(int j = 255; j >= 0; j--){
			OCR0A = gamma8[j];
			_delay_ms(delay_time);
		}
		PORTB &= ~(1 << PB2); // Turn off completely

		for(int i = 0; i < 256; i++){
			OCR0B = gamma8[i];
			_delay_ms(delay_time);
		}
		for(int j = 255; j >= 0; j--){
			OCR0B = gamma8[j];
			_delay_ms(delay_time);
		}
		PORTA &= ~(1 << PA7); // Turn off completely

		for(int i = 0; i < 256; i++){
			OCR1B = gamma8[i];
			_delay_ms(delay_time);
		}
		for(int j = 255; j >= 0; j--){
			OCR1B = gamma8[j];
			_delay_ms(delay_time);
		}
		PORTA &= ~(1 << PA5); // Turn off completely
	
	}

	return 1;
}
	