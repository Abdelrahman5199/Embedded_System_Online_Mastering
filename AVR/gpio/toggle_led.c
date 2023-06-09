/*
 * toggle_led.c
 *
 *  Created on: Jun 5, 2023
 *      Author: Abdelrahman Kotb
 */


typedef volatile unsigned char vuint8_t;
typedef unsigned int uint32_t;

//Gpio
#define GPIO_BASE    0x20

//Gpio reg
#define PORTA  *(vuint8_t *)(GPIO_BASE + 0x1B)
#define DDRA   *(vuint8_t *)(GPIO_BASE + 0x1A)
#define PINA   *(vuint8_t *)(GPIO_BASE + 0x19)

//GPIO POrtA pin
#define PA0   0
#define PA1   1
#define PA2   2
#define PA3   3
#define PA4   4
#define PA5   5
#define PA6   6
#define PA7   7

//Hardware Pins
#define LED0  PA0
#define LED1  PA1
#define LED2  PA2
#define LED3  PA3
#define LED4  PA4
#define LED5  PA5
#define LED6  PA6
#define LED7  PA7

//uti
#define SET_BIT(reg, bit)  (reg |= (1<<bit))
#define CLR_BIT(reg, bit)  (reg &= -(1 << (bit)))

//POrtotype
void delay(uint32_t count);

int main(void){
	// initaite port a pins as output
	DDRA = 0xff;

	uint32_t i;

	while(1){
		for(i=0;i<=7;i++){
			//turn on led
			SET_BIT(PORTA, i);

			delay(100);
		}
		for(i=7;i>=0;i--){
			CLR_BIT(PORTA, i);

			delay(100);
		}
	}
	return 0;
}
void delay(uint32_t count){
	vuint8_t i;
	while(count--)
	{
		for(i=0;i<255;i++);
	}



	}







