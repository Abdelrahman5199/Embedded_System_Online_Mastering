#ifndef DIO_H_
#define DIO_H_

#include "registers.h"
#include "bit_manipu.h"
//all internal driver typedefs
//all driver macros
//all driver function prototypes

#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

//Direction defines
#define IN 0
#define OUT 1

//Value defines
#define LOW 0
#define HIGH 1


void DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction);// Initialize dio direction
void DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value); //write data to dio
void DIO_toggle(uint8_t portNumber, uint8_t pinNumber); //toggle dio
void DIO_read(uint8_t portNumber, uint8_t pinNumber, uint8_t* value); //read dio


#endif /* DIO_H_ */

