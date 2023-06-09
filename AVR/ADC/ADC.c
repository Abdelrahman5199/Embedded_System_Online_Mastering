/*
 * ADC_program.c
 *
 *  Created on: Jun 5, 2023
 *      Author: Abdelrahman Kotb
 */


#include "ADC.h"


void ADC_Init(void)
{


	#if  ADC_VOLTAGE_REFERENCE	==	ADC_VRREF_AVCC

	SET_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);

	#elif ADC_VOLTAGE_REFERENCE	==	ADC_VRREF_AREF

	CLR_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);

	#elif ADC_VOLTAGE_REFERENCE	==	ADC_VRREF_INTERNAL

	SET_BIT(ADMUX,6);
	SET_BIT(ADMUX,7);

	#endif




	#if  ADC_ADJUST				==	ADC_RIGHT_ADJUST

	CLR_BIT(ADMUX , 5);

	#elif ADC_ADJUST			==	ADC_LEFT_ADJUST

	SET_BIT(ADMUX , 5);

	#endif

//selecting channel

	ADC_CHANNEL_SELECTION(ADC_CHANNEL);






	#if	 ADC_CONVERSION_TRIGGER	==	ADC_AUTO_TRIGGER

		SET_BIT(SFIOR,5);

	#elif ADC_CONVERSION_TRIGGER==	ADC_FREE_RUNNING

		CLR_BIT(SFIOR , 5);
		CLR_BIT(SFIOR , 6);
		CLR_BIT(SFIOR , 7);

	#elif ADC_CONVERSION_TRIGGER==	ADC_EXTERNAL_TRIG

		CLR_BIT(SFIOR , 5);
		SET_BIT(SFIOR , 6);
		CLR_BIT(SFIOR , 7);

	#endif




	#if	 ADC_PRESCALER			==	ADC_PRESC_128

	SET_BIT(ADCSRA , 0);
	SET_BIT(ADCSRA , 1);
	SET_BIT(ADCSRA , 2);

	#elif ADC_PRESCALER			==	ADC_PRESC_64

	SET_BIT(ADCSRA , 0);
	SET_BIT(ADCSRA , 1);
	CLR_BIT(ADCSRA , 2);

	#endif



	#if	 ADC_INTERRUPT_SATATE	==	ADC_INTERRUPT_ENABLE

	SET_BIT(ADCSRA , 3);

	#elif ADC_INTERRUPT_SATATE	==	ADC_INTERRUPT_DISABLE

	CLR_BIT(ADCSRA , 3);

	#endif


}

void ADC_Read(uint16* value)
{

	#if  ADC_ADJUST				==	ADC_RIGHT_ADJUST

	*value = ADC_DATAreg;

	#elif ADC_ADJUST			==	ADC_LEFT_ADJUST

	*value = (ADCH<<2) | (ADCL>>6);

	#endif

}

void ADC_StartConversion(void)
{
	//ADC ENABLE
	SET_BIT(ADCSRA,7);

	//start conversion
	SET_BIT(ADCSRA,6);

}

void ADC_CHANNEL_SELECTION(uint8 Channel)
{
	ADMUX |=((7<<4)|Channel);
}
