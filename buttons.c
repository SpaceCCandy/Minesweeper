#include "digital.h"

int main(){
    digital_pin_mode(2, INPUT);
    digital_pin_mode(3, INPUT);
    digital_pin_mode(4, INPUT);
    digital_pin_mode(5, INPUT);
    digital_pin_mode(6, INPUT);
    digital_pin_mode(7, INPUT);

    bool pin_state;

    while (1){


        if (digital_read(2, &pin_state)){
            pixel_move_pos(&selector, DIR_RIGHT);
        }
        else if (digital_read(3, &pin_state)){
            pixel_move_pos(&selector, DIR_LEFT);
        }
        else if (digital_read(4, &pin_state)){
            pixel_move_pos(&selector, DIR_UP);
        }
        else if (digital_read(5, &pin_state)){
            pixel_move_pos(&selector, DIR_DOWN);
        }
        else if(digital_read(6, &pin_state)){
            
        }
        else if (digital_read(6, &pin_state)){
            
        }
        
    }


}