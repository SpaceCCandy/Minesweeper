#include <avr/io.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h> 

typedef struct block{
    uint8_t *row;
    uint8_t *column;
    uint8_t *face;
    uint8_t value;
}block_t;


block_t mapRGB[5][3][3][3];     
block_t mapvalue[5][3][3];   



void generate_random_coords(block_t *b, uint8_t *r, uint8_t *c, uint8_t *f) {
    *f = rand() % 5;
    *r = rand() % 3;
    *c = rand() % 3;

    b->row = r;
    b->column = c;
    b->face = f;
    b->value = 10;
}

void main(void){
    srand(time(NULL));

    block_t bomb;

    uint8_t row, col, face;


    for(i = 0; i<8;i++){
        generate_random_coords(&bomb, &row, &col, &face);


        uint8_t r = *bomb.row;
        uint8_t c = *bomb.column;
        uint8_t f = *bomb.face;

        mapvalue[face][row][col] = bomb;

    }


}










