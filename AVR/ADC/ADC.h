/*
 * ADC_register.h
 *
 *  Created on: Jun 5, 2023
 *      Author: Abdelrahman Kotb
 */

#ifndef ADC_H_
#define ADC_H_

#include "ATmega_Registers.h"
#include "BIT_MATH.h"
#include "ADC_Cfg.h"

#define		ADC_VRREF_AVCC			0

#define		ADC_CHANNEL_1			1

#define		ADC_AUTO_TRIGGER		0

#define		ADC_RIGHT_ADJUST		0

#define		ADC_PRESC_128			0

#define		ADC_INTERRUPT_ENABLE	0

#define		ADC_INTERRUPT_DISABLE	1



void ADC_Init(void);

void ADC_Read(uint16* value);



#endif /* ADC_H_ */
