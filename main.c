#include "main.h"
#include "ws2812b.h"

void main(void)
{
    srand(time(NULL));

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

    while(true) {
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
