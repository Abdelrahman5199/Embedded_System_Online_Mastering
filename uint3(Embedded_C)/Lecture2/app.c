#include "uart.h"

unsigned char string_buffer[100] = "Abdelrahman Kotb ";
void main(void)
{
	Uart_Send_string(string_buffer);
}