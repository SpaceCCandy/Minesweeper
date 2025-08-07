#include <stdint.h>
#include <stddef.h>

#define ERROR_COLOR 0x000000
#define ITEM_TYPE_COUNT 10

typedef enum
{
  TYPE_SELECT = 0xFFFFFF, // White
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

typedef enum
{
  DIR_UP = 0,
  DIR_DOWN = 1,
  DIR_LEFT = 2,
  DIR_RIGHT = 3
} Direction;

uint32_t getTypeColor(ItemType type)
{
  return (uint32_t)type;
}

const char *getTypeName(ItemType type)
{
  switch (type)
  {
  case TYPE_SELECT:
    return "SELECT";
  case TYPE_BOMB:
    return "BOMB";
  case TYPE_ONE:
    return "ONE";
  case TYPE_TWO:
    return "TWO";
  case TYPE_THREE:
    return "THREE";
  case TYPE_FOUR:
    return "FOUR";
  case TYPE_FIVE:
    return "FIVE";
  case TYPE_SIX:
    return "SIX";
  case TYPE_SEVEN:
    return "SEVEN";
  case TYPE_EIGHT:
    return "EIGHT";
  default:
    return NULL;
  }
}
