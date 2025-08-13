#include "main.h"

void dir_check(block_t *pos, uint8_t direction, uint8_t up_block, uint8_t left_block, uint8_t right_block, uint8_t down_block) 
{
    if (direction == DIR_LEFT) 
    {
        pos->column = 2;
        pos->face = left_block;
    }

    else if (direction == DIR_UP) 
    {
        pos->row = 2;
        pos->face = up_block;
    }

    else if (direction == DIR_RIGHT) 
    {
        pos->column = 0;
        pos->face = right_block;
    }

    else if (direction == DIR_DOWN) 
    {
        pos->row = 0;
        pos->face = down_block;
    }
    
}

bool pixel_move_pos(block_t *pos, uint8_t direction)
{   
    if ((direction == DIR_UP) && (pos->row != 0)) 
    {
        pos->row = (pos->row) - 1;
        return false;
    }

    else if ((direction == DIR_DOWN) && (pos->row != 2)) 
    {
<<<<<<< HEAD
        pos->row = (pos->row) + 1;
=======
        pos->row = (pos->row)++;
>>>>>>> 91aef4bd21819d2a6725362b5a5ef99f1cc95c6c
        return false;
    }

    else if ((direction == DIR_LEFT) && (pos->column != 0)) 
    {
        pos->column = (pos->column) - 1;
        return false;
    }

    else if ((direction == DIR_RIGHT) && (pos->column != 2)) 
    {
        pos->column = (pos->column) + 1;
        return false;
    }

    else
    {
        switch (pos->face) 
        {
            case 1: 
                dir_check(pos, direction, 5, 2, 4, 0); 
                return true;

            case 2: 
                dir_check(pos, direction, 5, 3, 1, 0); 
                return true;

            case 3: 
                dir_check(pos, direction, 5, 4, 2, 0); 
                return true;

            case 4: 
                dir_check(pos, direction, 5, 1, 3, 0); 
                return true;

            case 5: 
                dir_check(&pos, direction, 2, 1, 3, 4); 
                return true;

            default: 
                return false;
                
        }
    }
}
