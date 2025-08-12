#include "digital.h"

#define BTN_RIGHT 2
#define BTN_LEFT 3
#define BTN_UP 4
#define BTN_DOWN 5
#define BTN_MINE 6
#define BTN_FLAG 7

int main(){
    digital_pin_mode(BTN_RIGHT, INPUT);
    digital_pin_mode(BTN_LEFT, INPUT);
    digital_pin_mode(BTN_UP, INPUT);
    digital_pin_mode(BTN_DOWN, INPUT);
    digital_pin_mode(BTN_MINE, INPUT);
    digital_pin_mode(BTN_FLAG, INPUT);

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
        else if (digital_read(BTN_MINE, &pin_state)) {
            uint8_t val = mapvalue[selector.face][selector.row][selector.column].value;
        
            for (int c = 0; c < 3; c++) {
                mapRGB[selector.face][selector.row][selector.column][c].value =
                    item_Colors[val][c];
            }

            if (val == TYPE_BOMB) {
                
                return 1; 
            }
        }
        else if (digital_read(BTN_FLAG, &pin_state)) {
            for (int c = 0; c < 3; c++) {
                mapRGB[selector.face][selector.row][selector.column][c].value =
                    item_Colors[TYPE_SELECT][c];
            }
        }
    }
}