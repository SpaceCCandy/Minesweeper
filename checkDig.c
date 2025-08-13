#include "main.h"

void bomb_setn(block_t bomb) 
{   
    pixel_move_pos(&bomb, DIR_RIGHT);

    for(uint8_t i = 0; i < 4; i++) //Happens 4 times (0, 1, 2, 3)
    {
        pixel_move_pos(&bomb, i); // Move (0)
        bomb.value++;

        if (i == 3) // On the last turn do up
        {
            pixel_move_pos(&bomb, DIR_UP);
            bomb.value++;
        }

        else 
        {
            pixel_move_pos(&bomb, i+1); // Move (0 + 1)
            bomb.value++;
        }
    }        
} //Up, left, Left, Down, Down, Right, Right, Up

// DIR_UP = 0,
// DIR_LEFT = 1,
// DIR_DOWN = 2,
// DIR_RIGHT = 3

//logic*
//  [→][→][↓]
//  [↑][↑][↓]
//  [↑][←][←]