#include "main.h"

void bomb_setn(block_t bomb) 
{   
    pixel_move_pos(bomb, DIR_RIGHT);

    for(uint8 i = 0; i < 4; i++)
    {
        pixel_move_pos(bomb, i);
        bomb->value++;

        if (i == 3)
        {
            pixel_move_pos(bomb, DIR_UP);
            bomb->value++;
        }

        else 
        {
        pixel_move_pos(bomb, i+1);
        bomb->value++;
        }
    }        
}
//logic*
//  [→][→][↓]
//  [↑][↑][↓]
//  [↑][←][←]