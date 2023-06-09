#include "uart.h"

#define UART0DR *((volatile unsigned int* const)((unsigned int *)0x101f1000))

void Uart_Send_String(unsigned char *P_tx_String){
	while(*P_tx_String != '\0'){
		UART0DR = (unsigned int)(*P_tx_String);
		P_tx_String++;
	}
}
		