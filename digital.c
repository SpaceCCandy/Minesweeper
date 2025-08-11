#include "digital.h"


volatile uint8_t *digital_pin_to_port(uint8_t pin){
    
    if (pin <= 7){
        return &PORTD;
    } 
    else if (pin <= 13){
        return &PORTB;
    }
    else if (pin <= 19){
        return &PORTC;
    }
    else {
        return NULL;
    }

}


volatile uint8_t *digital_port_offset(volatile uint8_t * const port, digital_register_type_t type){
    return port + type;
}

int digital_pin_to_bit(uint8_t pin){
    if (pin <= 7){
        return pin;
    } 
    else if (pin <= 13){
        return pin - 8;
    }
    else if (pin <= 19){
        return pin - 14;
    }
    else {
        return -1;
    }
}



bool digital_pin_mode(uint8_t pin, digital_mode_t mode){
    volatile uint8_t *port = digital_pin_to_port(pin);
    volatile uint8_t *ddr = digital_port_offset(port, -1);
    volatile uint8_t *portreg = digital_port_offset(port, 0);
    uint8_t const BIT = digital_pin_to_bit(pin);
    uint8_t const MASK = (1 << BIT);

    if (mode == INPUT){
        *ddr &= ~MASK;
    }
    else if (mode == OUTPUT){
        *ddr |= MASK;
    }
    else if (mode == INPUT_PULLUP){
        *ddr  &= ~MASK;
        *portreg |= MASK;
    }
    return true;
}

bool digital_write(uint8_t pin, bool high){
    volatile uint8_t *port = digital_pin_to_port(pin);
    volatile uint8_t *portreg = digital_port_offset(port, 0);
    uint8_t const BIT = digital_pin_to_bit(pin);
    uint8_t const MASK = (1 << BIT);



    if (high){
        *portreg |= MASK;
    }
    else {
        *portreg &= (~MASK);
    }

    return true;
    

}

bool digital_read(uint8_t pin, bool * const pin_state){
    volatile uint8_t *port = digital_pin_to_port(pin);
    volatile uint8_t *pinreg = digital_port_offset(port, -2);
    uint8_t const BIT = digital_pin_to_bit(pin);
    uint8_t MASK = (1<< BIT);

    *pin_state = *pinreg & MASK;             
    return true;
    
}