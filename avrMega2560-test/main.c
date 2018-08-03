/*
 * main.c
 *
 *  Created on: 8 Nov 2016
 *      Author: wisnu
 */
#include <avr/io.h>
#include <stdint.h>
#include <avr/pgmspace.h>
#include "test1.h"
#include <avr/interrupt.h>
#include <util/delay.h>

volatile uint16_t sample;

ISR(TIMER0_OVF_vect){
	OCR3A=pgm_read_byte(&test1[sample++]);
	if(sample>test1_length){sample=0;}
	TCNT0=(unsigned char) -250;
}

int main(void){
	DDRE|=_BV(PB3);
	TCCR3B=_BV(CS30);
	TCCR3A=_BV(WGM30)|_BV(COM3A1);
	OCR3A=0;

	TCCR0B=_BV(CS01);
	TIMSK0 |=_BV(TOIE0);
	sei();

	_delay_ms(1000);

	while(1){}
}

