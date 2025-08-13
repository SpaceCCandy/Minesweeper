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
#include <string.h>

#define ERROR_COLOR 0x000000
#define ITEM_TYPE_COUNT 10

typedef enum
{
  TYPE_SELECT, // White
  TYPE_BLANK, // Black
  TYPE_ONE,    // Blue
  TYPE_TWO,    // Green
  TYPE_THREE,  // Yellow
  TYPE_FOUR,   // Pink
  TYPE_FIVE,   // Orange
  TYPE_SIX,    // Cyan
  TYPE_SEVEN,  // Purple
  TYPE_EIGHT,   // Brown
  TYPE_BOMB,   // Red
} ItemType;

extern const uint8_t item_Colors[11][3];

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
  uint8_t status
} block_t;

block_t bombLocations[8];
block_t selector; //Current "cursor" position

uint8_t mapRGB[5][3][3][3];
block_t mapvalue[5][3][3];

uint8_t row;
uint8_t col;
uint8_t face;


extern uint16_t FRACT_MAX;
extern uint16_t TOTAL_MILLIS;

extern unsigned long millisec;
extern unsigned long extra_us;



block_t generate_random_coords(uint8_t value);
bool pixel_move_pos(block_t *pos, uint8_t direction);
void dir_check(block_t *pos,uint8_t direction, uint8_t up_block, uint8_t left_block, uint8_t right_block, uint8_t down_block);
void bomb_setn(block_t bomb);
uint32_t clockCyclesToUS(uint32_t cycle, uint8_t pre_scale);
unsigned long millis();

