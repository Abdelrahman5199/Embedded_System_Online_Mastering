\\"############# uart.h ##############"
#define IN 0
#define OUT 1
#define LOW 0
#define HIGH 1
#ifndef USART_H
#define USART_H
void UART_vInit(unsigned long baud);
void UART_vSendData(char data);
char UART_u8ReceiveData(void);
void UART_vSendstring(char* ptr);
void DIO_write(uint8_t pinNumber, uint8_t port, uint8_t value);
void DIO_init(uint8_t pinNumber, uint8_t port, uint8_t direction);
void DIO_read(uint8_t pinNumber, uint8_t port, uint8_t* value);
void SWUART_init(uint32_t baudrate);
void SWUART_send(uint8_t data);
void SWUART_recieve(uint8_t* data);
#endif 
