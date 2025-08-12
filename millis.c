#include "main.h"



uint32_t clockCyclesToUS(uint32_t cycle, uint8_t pre_scale){
    uint16_t us;
   return us = (cycle * pre_scale) / (F_CPU/ 1000000);
}
uint32_t MICROSECONDS_PER_TIMER0_OVERFLOW = clockCyclesToUS(256, 64);
uint16_t FRACT_REMAINDER = (MICROSECONDS_PER_TIMER0_OVERFLOW % 1000);
uint16_t FRACT_MAX = 1000;
uint16_t TOTAL_MILLIS = 0;

unsigned long millisec = 0;
unsigned long extra_us = 0;

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


int main(void){
    TCCR0B |= (1 << CS01) | (1 << CS00);
    TIMSK0 |= (1 << TOIE0);
    sei();
    
    while(1){
    }
}