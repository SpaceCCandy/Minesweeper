#pragma once
#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <util/twi.h>
#include <avr/interrupt.h>
#include <iostream>
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

uint8_t row;
uint8_t col;
uint8_t face;

void generate_random_coords(void);
bool pixel_move_pos(uint8_t row, uint8_t *const column, uint8_t *const face, uint8_t *const direction);
void dir_check(uint8_t direction, uint8_t up_block, uint8_t left_block, uint8_t right_block, uint8_t down_block);