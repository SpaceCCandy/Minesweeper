#include "main.h"

void generate_random_coords(void) {

    block_t b;

    b.face = rand() % 5;
    b.row = rand() % 3;
    b.column = rand() % 3;

    b.value = 10;
}