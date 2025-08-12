#pragma once
#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <util/twi.h>
#include <avr/interrupt.h>
#include <iostream>
#include <time.h> 

#define ERROR_COLOR 0x000000
#define ITEM_TYPE_COUNT 10

typedef enum
{
  TYPE_SELECT, // White
  TYPE_BOMB = 0xFE0000,   // Red
  TYPE_ONE = 0x4363D8,    // Blue
  TYPE_TWO = 0x3CB44B,    // Green
  TYPE_THREE = 0xFFCA00,  // Yellow
  TYPE_FOUR = 0xF032E6,   // Pink
  TYPE_FIVE = 0xF58231,   // Orange
  TYPE_SIX = 0x46F0F0,    // Cyan
  TYPE_SEVEN = 0x5F530F,  // Purple
  TYPE_EIGHT = 0x5F530F   // Brown
} ItemType;

const uint8_t [10][3] = { //GRB
  {255,255,255},
  { , , },
  { , , }
}

typedef enum
{
  DIR_UP = 0,
  DIR_LEFT = 1,
  DIR_DOWN = 2,
  DIR_RIGHT = 3
} Direction;

typedef struct block
{
    uint8_t row;
    uint8_t column;
    uint8_t face;
    uint8_t value;
}block_t;

block_t selector; //Current "cursor" position

block_t bombLocations[7];

block_t mapRGB[5][3][3][3];     
block_t mapvalue[5][3][3];

uint8_t row;
uint8_t col;
uint8_t face;

void generate_random_coords(void);
bool pixel_move_pos(uint8_t row, uint8_t *const column, uint8_t *const face, uint8_t *const direction);
void dir_check(uint8_t direction, uint8_t up_block, uint8_t left_block, uint8_t right_block, uint8_t down_block);
void bomb_setn(block_t bomb); 