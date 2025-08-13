#include "main.h"
#include "ws2812b.h"

<<<<<<< HEAD
static uint32_t time_status;
=======
uint32_t MICROSECONDS_PER_TIMER0_OVERFLOW;
uint16_t FRACT_REMAINDER;
unsigned long extra_us = 0;
unsigned long millisec = 0;

uint16_t FRACT_MAX = 1000;
uint16_t TOTAL_MILLIS = 0;

uint32_t clockCyclesToUS(uint32_t cycle, uint8_t pre_scale){
    uint16_t us;
   return (cycle * pre_scale) / (F_CPU/ 1000000);
}


const uint8_t item_Colors[11][3] = {
    {255, 255, 255}, // TYPE_SELECT
    {0, 0, 0}, //TYPE_BLANK
    {99, 67, 216},   // TYPE_ONE
    {180, 60, 75},   // TYPE_TWO
    {202, 255, 0},   // TYPE_THREE
    {50, 240, 230},  // TYPE_FOUR
    {130, 245, 49},  // TYPE_FIVE
    {240, 70, 240},  // TYPE_SIX
    {83, 95, 15},    // TYPE_SEVEN
    {83, 95, 15},     // TYPE_EIGHT
    {0, 254, 0},     // TYPE_BOMB
};

ISR(TIMER0_OVF_vect) {
    millisec += TOTAL_MILLIS;
    extra_us += FRACT_REMAINDER;
}
static uint32_t time;
>>>>>>> 91aef4bd21819d2a6725362b5a5ef99f1cc95c6c

void main(void)
{   
    //Time stuff
    TCCR0B |= (1 << CS01) | (1 << CS00);
    TIMSK0 |= (1 << TOIE0);
    sei();

    srand(time(NULL));

    uint32_t MICROSECONDS_PER_TIMER0_OVERFLOW = clockCyclesToUS(256, 64);
    uint16_t FRACT_REMAINDER = (MICROSECONDS_PER_TIMER0_OVERFLOW % 1000);

    //Bombs are mapped and saved.
    for(int i = 0; i < 8;i++)
    {
        bombLocations[i] = generate_random_coords(10); //C: Doesn't prevent 2 bombs being placed in the same location?
        mapvalue[bombLocations[i].face][bombLocations[i].row][bombLocations[i].column].value = bombLocations[i].value;
    }

    uint8_t i;
    for (i = 0; i < sizeof(bombLocations); i++)
    {
        bomb_setn(bombLocations[i]);
    }

    //While loop forever...
    while(true) {

        // Displays selector every 1 second
        if ((millis() - time_status) > 1000) 
        {   
            memcpy(&mapRGB[selector.face][selector.row][selector.column], 
                &item_Colors[0], 
                sizeof(item_Colors[0]));
            //mapRGB[selector.face][selector.row][selector.column][i] = item_Colors[0]; //Color to white
        }

        else if ((millis() - time_status) > 2000) 
        {
            time = millis();
            memcpy(&mapRGB[selector.face][selector.row][selector.column], 
                &item_Colors[mapvalue[selector.face][selector.row][selector.column].value], 
                sizeof(item_Colors[mapvalue[selector.face][selector.row][selector.column].value]));
            //mapRGB[selector.face][selector.row][selector.column] = item_Colors[mapvalue[selector.face][selector.row][selector.column].value]; //Color to blank
        }

        // generate pattern to display
        for (size_t f = 0; f < FACES; f++)
            for (size_t i = 0; i < ROWS; i++)
                for (size_t j = 0; j < COLUMNS; j++)
                    for (size_t k = 0; k < WS2812B_COLOR_TOTAL; k++)
                        buffer.display[f][i][j][k] = mapRGB[i][f][j][k];

        *PIXELS_DDR  |=   1 << PIXELS_BIT;
        *PIXELS_PORT &= ~(1 << PIXELS_BIT);

        // The WS2812B data line needs to be held low for at least 50 us
        // on initialization to latch onto transmitted bit sequences.
        _delay_us(50);

        ws2812b_tx(PIXELS_PORT, PIXELS_BIT, buffer.ws2812b, PIXELS);
    }
}
