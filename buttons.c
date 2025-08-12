#include "digital.h"

#define BTN_RIGHT 2
#define BTN_LEFT 3
#define BTN_UP 4
#define BTN_DOWN 5
#define BTN_MINE 6
#define BTN_FLAG 7

int main(){
    digital_pin_mode(2, INPUT);
    digital_pin_mode(3, INPUT);
    digital_pin_mode(4, INPUT);
    digital_pin_mode(5, INPUT);
    digital_pin_mode(6, INPUT);
    digital_pin_mode(7, INPUT);

    bool pin_state;

    while (1){


        if (digital_read(BTN_RIGHT, &pin_state)){
            pixel_move_pos(&selector, DIR_RIGHT);
        }
        else if (digital_read(BTN_LEFT, &pin_state)){
            pixel_move_pos(&selector, DIR_LEFT);
        }
        else if (digital_read(BTN_UP, &pin_state)){
            pixel_move_pos(&selector, DIR_UP);
        }
        else if (digital_read(BTN_DOWN, &pin_state)){
            pixel_move_pos(&selector, DIR_DOWN);
        }
        else if(digital_read(BTN_MINE, &pin_state)){
            mapRGB[selector->face][selector->row][selector->column][] = mapvalue[selector->face][selector->row][selector->column]
        }
        else if (digital_read(BTN_FLAG, &pin_state)){
            
        }
        
    }


}