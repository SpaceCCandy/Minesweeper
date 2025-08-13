#include "main.h"

ISR(TIMER0_OVF_vect) {
    millisec += TOTAL_MILLIS;
    extra_us += FRACT_REMAINDER;

    if (extra_us >= FRACT_MAX){
        millisec++;
        extra_us = 0;
    }
}

unsigned long millis()
{
	unsigned long millis;
	uint8_t oldSREG = SREG;
	cli();
	SREG = oldSREG;
	return millisec;
}