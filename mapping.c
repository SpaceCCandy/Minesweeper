#include "main.h"

block_t generate_random_coords(uint8_t value) 
{

    block_t b;
    b.face = rand() % 5;
    b.row = rand() % 3;
    b.column = rand() % 3;

    uint8_t val;
    b.value = val;

    return b;
}