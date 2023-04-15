#include "button.h"
void BUTTON_init(uint8_t buttonPort,uint8_t buttonPin){
    DIO_init(buttonPort,buttonPin,IN);
    // intilaize button
}

void BUTTON_read(uint8_t buttonPort,uint8_t buttonPin,uint8_t *value){
    DIO_read(buttonPort,buttonPin,value);
    //button redaing
}
