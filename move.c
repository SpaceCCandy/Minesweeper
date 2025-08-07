#include "main.h"

void dir_check(uint8_t direction, uint8_t up_block, uint8_t left_block, uint8_t right_block, uint8_t down_block) {
    if (direction == LEFT) {
        *column = 3;
        *face = left_block;
    }
    else if (direction == UP) {
        *row = 3;
        *face = up_block;
    }
    else if (direction == RIGHT) {
        *column = 1;
        *face = right_block;
    }
    else {
        *row = 1;
        *face = down_block;
    }

}

bool pixel_move_pos(uint8_t row, uint8_t *const column, uint8_t *const face, uint8_t *const direction)
{
    switch (*face) { // Dereference the pointer to get the integer value
        case 1:
            dir_check(direction, 5, 2, 4);
            return true;

        case 2:
            dir_check(direction, 5, 3, 1);
            return true;

        case 3:
            dir_check(direction, 5, 4, 2);
            return true;

        case 4:
            dir_check(direction, 5, 1, 3);
            return true;

        case 5:
            dir_check(direction, 2, 1, 3, 4);
            return true;

        default:
            return false;
    }
}