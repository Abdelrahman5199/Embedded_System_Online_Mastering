//"############# uart.c ##############"
#define F_CPU 8000000UL
#include <util/delay.h>
#include<avr/io.h>
#include "std_macros.h"
#include "uart.h"

void DIO_init(uint8_t pinNumber, uint8_t port, uint8_t direction) {
    SYNC = 0;    // Asynchronous
    SPEN = 1;    // Enable serial port pins
    //_____Asynchronous serial port enabled_______/
    TXEN = 1;    // enable transmission
    CREN = 1;    // enable reception
    //__UART module up and ready for transmission and reception__// 
    TX9 = 0;    // 8-bit reception selected
    RX9 = 0;    // 8-bit reception mode selecte
}
void DIO_write(uint8_t pinNumber, uint8_t port, uint8_t value) {
	TRISC6 = 0; // TX Pin set as output
	TRISC7 = 1; // RX Pin set as input
	SPBRG = ((_XTAL_FREQ / 16) / Baud_rate) - 1;
	BRGH = 1;  // for high baud_rate

}
void UART_vInit(unsigned long baud) {
    unsigned short UBRR;
    UBRR = (F_CPU / (16 * baud)) - 1;
    UBRRH(unsigned char)(UBRR >> 8);
    UBRRL(unsigned char)UBRR;
    SET_BIT(UCSRB, TXEN);
    SET_BIT(UCSRB, RXEN);
    UCSRC = (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);
}
void SWUART_send(uint8_t data) {
    while (1) //Infinite loop

    {

        get_value = UART_get_char();



        if (get_value == '1') //If the user sends "1"

        {

            RB3 = 1; //Turn on LED

            UART_send_string("RED LED -> ON"); //Send notification to the computer 

            UART_send_char(10);//ASCII value 10 is used for carriage return (to print in new line)

        }



        if (get_value == '0') //If the user sends "0"

        {

            RB3 = 0; //Turn off LED

            UART_send_string("RED -> OFF"); //Send notification to the computer      

            UART_send_char(10);//ASCII value 10 is used for carriage return (to print in new line)

        }
    }
}
void SWUART_recieve(uint8_t* data) {
    if (OERR) // check for Error 

    {

        CREN = 0; //If error -> Reset 

        CREN = 1; //If error -> Reset 

    }



    while (!RCIF) { // hold the program till RX buffer is free



        return RCREG; //receive the value and send it to main function

    }
}


