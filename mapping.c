#include <avr/io.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h> 

typedef struct block{
    uint8_t row;
    uint8_t column;
    uint8_t face;
    uint8_t value;
}block_t;


block_t mapRGB[5][3][3][3];     
block_t mapvalue[5][3][3];   



void generate_random_coords(void) {

    block_t b;

    b.face = rand() % 5;
    b.row = rand() % 3;
    b.column = rand() % 3;

    b.value = 10;
}

void main(void){
    srand(time(NULL));

    block_t bomb;

    uint8_t row;
    uint8_t col;
    uint8_t face;


    for(i = 0; i<8;i++){
        generate_random_coords(void);
        row = bomb.row;
        col = bomb.column;
        face = bomb.face;

        mapvalue[bomb.face][bomb.row][bomb.column] = bomb;

    }


}










