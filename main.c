#include "main.h"

void main(void)
{
    srand(time(NULL));

    //Bombs are mapped and saved.
    for(int i = 0; i < 8;i++)
    {   
        mapRGB[selector->face][selector->row][selector->column] = item_Colors[0]
        bombLocations[i] = generate_random_coords(-1); //C: Doesn't prevent 2 bombs being placed in the same location
        mapvalue[bombLocations[i].face][bombLocations[i].row][bombLocations[i].column] = bombLocations[i].val;
    }

    for (int i = 0; i < sizeof(bombLocations); i++)
    {
        void bomb_setn(bombLocations[i]);
    }
}
