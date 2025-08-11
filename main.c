#include "main.h"
#include "ws2812b.h"

void main(void)
{
    srand(time(NULL));

    block_t selector; //Current "cursor" position

    //Bombs are mapped and saved.
    for(int i = 0; i < 8;i++)
    {
        bombLocations[i] = generate_random_coords(10); //C: Doesn't prevent 2 bombs being placed in the same location
        mapvalue[bombLocations[i].face][bombLocations[i].row][bombLocations[i].column] = bombLocations[i].val;
    }

    for (int i = 0; i < sizeof(bombLocations); i++)
    {
        void bomb_setn(bombLocations[i]);
    }

    while(True) {
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
