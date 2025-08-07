#include <stdint.h>
#define ERROR_COLOR 0x000000
#include <stddef.h>
typedef enum
{
  TYPE_SELECT, // White
  TYPE_BOMB,   // Red
  TYPE_ONE,    // Blue
  TYPE_TWO,    // Green
  TYPE_THREE,  // Yellow
  TYPE_FOUR,   // Pink
  TYPE_FIVE,   // Orange
  TYPE_SIX,    // Cyan
  TYPE_SEVEN,  // Purple
  TYPE_EIGHT,  // Brown
  TYPE_COUNT
} ItemType;

const uint32_t typeColors[] = {
    0xFFFFFF, // SELECT -> White
    0xFE0000, // BOMB -> Red
    0x4363D8, // ONE -> Blue
    0x3CB44B, // TWO -> Green
    0xFFCA00, // THREE -> Yellow
    0xF032E6, // FOUR -> Pink
    0xF58231, // FIVE -> Orange
    0x46F0F0, // SIX -> Cyan
    0x8800DD, // SEVEN -> Purple
    0x5F530F  // EIGHT -> Brown
};

typedef enum
{
  DIR_UP = 0,
  DIR_DOWN = 1,
  DIR_LEFT = 2,
  DIR_RIGHT = 3
} Direction;

uint32_t getTypeColor(ItemType type)
{
  if (type < TYPE_COUNT)
  {
    return typeColors[type];
  }
  return ERROR_COLOR;
}

const char *getTypeName(ItemType type)
{
  const char *names[] = {
      "SELECT", "BOMB", "ONE", "TWO", "THREE",
      "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT"};
  if (type < TYPE_COUNT)
  {
    return names[type];
  }
  return NULL;
}