#include "main.h"

block_t generate_random_coords(uint8_t val) 
{

    block_t b;
    
    b.face = rand() % 5;
    b.row = rand() % 3;
    b.column = rand() % 3;

    b.value = val;

    return b;
}

void 