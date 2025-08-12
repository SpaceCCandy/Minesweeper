#pragma once
#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <util/twi.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <time.h>

#define ERROR_COLOR 0x000000
#define ITEM_TYPE_COUNT 10

typedef enum
{
  TYPE_SELECT, // White
  TYPE_BLANK, // Black
  TYPE_BOMB,   // Red
  TYPE_ONE,    // Blue
  TYPE_TWO,    // Green
  TYPE_THREE,  // Yellow
  TYPE_FOUR,   // Pink
  TYPE_FIVE,   // Orange
  TYPE_SIX,    // Cyan
  TYPE_SEVEN,  // Purple
  TYPE_EIGHT,   // Brown
} ItemType;

const uint8_t item_Colors[11][3] = {
    {255, 255, 255}, // TYPE_SELECT
    {0, 0, 0}, //TYPE_BLANK
    {99, 67, 216},   // TYPE_ONE
    {180, 60, 75},   // TYPE_TWO
    {202, 255, 0},   // TYPE_THREE
    {50, 240, 230},  // TYPE_FOUR
    {130, 245, 49},  // TYPE_FIVE
    {240, 70, 240},  // TYPE_SIX
    {83, 95, 15},    // TYPE_SEVEN
    {83, 95, 15},     // TYPE_EIGHT
    {0, 254, 0},     // TYPE_BOMB
};

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
} block_t;

block_t bombLocations[8];
block_t selector; //Current "cursor" position

block_t mapRGB[5][3][3][3];
block_t mapvalue[5][3][3];

uint8_t row;
uint8_t col;
uint8_t face;

block_t generate_random_coords(uint8_t value);
bool pixel_move_pos(block_t *pos, uint8_t direction);
void dir_check(block_t *pos,uint8_t direction, uint8_t up_block, uint8_t left_block, uint8_t right_block, uint8_t down_block);
void bomb_setn(block_t bomb);