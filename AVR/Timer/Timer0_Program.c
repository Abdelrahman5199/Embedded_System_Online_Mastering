/*
 * Timer0_Program.c
 *
 *  Created on: Jun 8, 2023
 *      Author: Abdelrahman Kotb
 */

/* LIB LAYER */
#include "BIT_MATH.h"
#include "COMMON_MACROS.h"
#include "STD_TYPES.h"
/* MCAL LAYER */
#include "Timer0_Configure.h"
#include "Timer0_Private.h"

/* Global Pointers to Functions for Calling Back */
void (*GLOB_VidTimer0OVFPtrCallBack) (void) = NULL;
void (*GLOB_VidTimer0OCMPtrCallBack) (void) = NULL;

/************************************************************************************/
/*						PUBLIC FUNCTIONS IMPLEMENTATION								*/
/************************************************************************************/

u8 Timer0_U8Init(void)
{
#if MODE == NORMAL
	CLR_BIT(TCCR0_REGISTER, WGM01);
	CLR_BIT(TCCR0_REGISTER, WGM00);
#elif MODE == PHASE_CORRECT
	CLR_BIT(TCCR0_REGISTER, WGM01);
	SET_BIT(TCCR0_REGISTER, WGM00);
	/* For ensuring compatibility with future devices */
	CLR_BIT(TCCR0_REGISTER, FOC0);
#if OC0_PHASE_CORRECT == DISCONNECT_OC0
	CLR_BIT(TCCR0_REGISTER, COM01);
	CLR_BIT(TCCR0_REGISTER, COM00);
#elif OC0_PHASE_CORRECT == NON_INVERTING_OC0
	SET_BIT(TCCR0_REGISTER, COM01);
	CLR_BIT(TCCR0_REGISTER, COM00);
#elif OC0_PHASE_CORRECT == INVERTING_OC0
	SET_BIT(TCCR0_REGISTER, COM01);
	SET_BIT(TCCR0_REGISTER, COM00);
#else
#error "Incorrect output compare pin (OC0) behavior in case of phase correct mode"
#endif
#elif MODE == CTC
	SET_BIT(TCCR0_REGISTER, WGM01);
	CLR_BIT(TCCR0_REGISTER, WGM00);
#if OC0_NON_PWM == DISCONNECT_OC0
	CLR_BIT(TCCR0_REGISTER, COM01);
	CLR_BIT(TCCR0_REGISTER, COM00);
#elif OC0_NON_PWM == TOGGLE_OC0
	CLR_BIT(TCCR0_REGISTER, COM01);
	SET_BIT(TCCR0_REGISTER, COM00);
#elif OC0_NON_PWM == CLEAR_OC0
	SET_BIT(TCCR0_REGISTER, COM01);
	CLR_BIT(TCCR0_REGISTER, COM00);
#elif OC0_NON_PWM == SET_OC0
	SET_BIT(TCCR0_REGISTER, COM01);
	SET_BIT(TCCR0_REGISTER, COM00);
#else
#error "Incorrect output compare pin (OC0) behaviour in case of non-PWM mode"
#endif
#elif MODE == FAST_PWM
	SET_BIT(TCCR0_REGISTER, WGM01);
	SET_BIT(TCCR0_REGISTER, WGM00);
	/* For ensuring compatibility with future devices */
	CLR_BIT(TCCR0_REGISTER, FOC0);
#if OC0_FAST_PWM == DISCONNECT_OC0
	CLR_BIT(TCCR0_REGISTER, COM01);
	CLR_BIT(TCCR0_REGISTER, COM00);
#elif OC0_FAST_PWM == NON_INVERTING_OC0
	SET_BIT(TCCR0_REGISTER, COM01);
	CLR_BIT(TCCR0_REGISTER, COM00);
#elif OC0_FAST_PWM == INVERTING_OC0
	SET_BIT(TCCR0_REGISTER, COM01);
	SET_BIT(TCCR0_REGISTER, COM00);
#else
#error "Incorrect output compare pin (OC0) behaviour in case of fast PWM mode"
#endif
#else
#error "Incorrect timer0 mode"
#endif
#if CLOCK_SELECT == NO_CLOCK_SOURCE
	CLR_BIT(TCCR0_REGISTER, CS02);
	CLR_BIT(TCCR0_REGISTER, CS01);
	CLR_BIT(TCCR0_REGISTER, CS00);
#elif CLOCK_SELECT == NO_PRESCALER
	CLR_BIT(TCCR0_REGISTER, CS02);
	CLR_BIT(TCCR0_REGISTER, CS01);
	SET_BIT(TCCR0_REGISTER, CS00);
#elif CLOCK_SELECT == PRESCALER_8
	CLR_BIT(TCCR0_REGISTER, CS02);
	SET_BIT(TCCR0_REGISTER, CS01);
	CLR_BIT(TCCR0_REGISTER, CS00);
#elif CLOCK_SELECT == PRESCALER_64
	CLR_BIT(TCCR0_REGISTER, CS02);
	SET_BIT(TCCR0_REGISTER, CS01);
	SET_BIT(TCCR0_REGISTER, CS00);
#elif CLOCK_SELECT == PRESCALER_256
	SET_BIT(TCCR0_REGISTER, CS02);
	CLR_BIT(TCCR0_REGISTER, CS01);
	CLR_BIT(TCCR0_REGISTER, CS00);
#elif CLOCK_SELECT == PRESCALER_1024
	SET_BIT(TCCR0_REGISTER, CS02);
	CLR_BIT(TCCR0_REGISTER, CS01);
	SET_BIT(TCCR0_REGISTER, CS00);
#elif CLOCK_SELECT == EXTERNAL_T0_FALLING_EDGE
	SET_BIT(TCCR0_REGISTER, CS02);
	SET_BIT(TCCR0_REGISTER, CS01);
	CLR_BIT(TCCR0_REGISTER, CS00);
#elif CLOCK_SELECT == EXTERNAL_T0_RISING_EDGE
	SET_BIT(TCCR0_REGISTER, CS02);
	SET_BIT(TCCR0_REGISTER, CS01);
	SET_BIT(TCCR0_REGISTER, CS00);
#else
#error "Incorrect clock selection"
#endif
	return NO_ERROR;
}

u8 Timer0_U8Preload(const u8 LOC_U8Value)
{
	TCNT0_REGISTER = LOC_U8Value;
	return NO_ERROR;
}

u8 Timer0_U8SetCTCValue(const u8 LOC_U8Value)
{
	OCR0_REGISTER = LOC_U8Value;
	return NO_ERROR;
}

u8 Timer0_U8GetCounterValue(u8* const LOC_U8Value)
{
	if (LOC_U8Value != NULL)
	{
		*LOC_U8Value = TCNT0_REGISTER;
		return NO_ERROR;
	}
	else
	{
		return ERROR;
	}
}

u8 Timer0_U8EnableOVFInterrupt(void)
{
	SET_BIT(TIMSK_REGISTER, TOIE0);
	return NO_ERROR;
}

u8 Timer0_U8DisableOVFInterrupt(void)
{
	CLR_BIT(TIMSK_REGISTER, TOIE0);
	return NO_ERROR;
}

u8 Timer0_U8EnableOCMInterrupt(void)
{
	SET_BIT(TIMSK_REGISTER, OCIE0);
	return NO_ERROR;
}

u8 Timer0_U8DisableOCMInterrupt(void)
{
	CLR_BIT(TIMSK_REGISTER, OCIE0);
	return NO_ERROR;
}

u8 Timer0_U8OVFSetCallBack( void (*ptrToFun)(void) )
{
	if (ptrToFun != NULL)
	{
		GLOB_VidTimer0OVFPtrCallBack = ptrToFun;
		return NO_ERROR;
	}
	else
	{
		return ERROR;
	}
}

u8 Timer0_U8OCMSetCallBack( void (*ptrToFun)(void) )
{
	if (ptrToFun != NULL)
	{
		GLOB_VidTimer0OCMPtrCallBack = ptrToFun;
		return NO_ERROR;
	}
	else
	{
		return ERROR;
	}
}

u8 Timer0_U8OVFPollingOnFlag(void)
{
	/* Wait until flag is fired */
	while ( !GET_BIT(TIFR_REGISTER, TOV0) );
	/* Clear flag */
	SET_BIT(TIFR_REGISTER, TOV0);
	return NO_ERROR;
}

u8 Timer0_U8OCMPollingOnFlag(void)
{
	/* Wait until flag is fired */
	while ( !GET_BIT(TIFR_REGISTER, OCF0) );
	/* Clear flag */
	SET_BIT(TIFR_REGISTER, OCF0);
	return NO_ERROR;
}

u8 Timer0_U8SetDutyCycle(const f32 LOC_F32DutyCycle)
{
	if (LOC_F32DutyCycle >= MINIMUM_DUTYCYCLE && LOC_F32DutyCycle <= MAXIMUM_DUTYCYCLE)
	{
		Timer0_U8SetCTCValue( ( LOC_F32DutyCycle / 100 ) * ( RESOLUTION - 1 ) );
		return NO_ERROR;
	}
	else
	{
		return ERROR;
	}
}

u8 Timer0_U8ResetPrescaler(void)
{
	SET_BIT(SFIOR_REGISTER, PSR10);
	return NO_ERROR;
}

/************************************************************************************/
/*						PRIVATE FUNCTIONS IMPLEMENTATION							*/
/************************************************************************************/

void __vector_10(void)
{
	if (GLOB_VidTimer0OCMPtrCallBack != NULL)
	{
		(*GLOB_VidTimer0OCMPtrCallBack)();
	}
}

void __vector_11(void)
{
	if (GLOB_VidTimer0OVFPtrCallBack != NULL)
	{
		(*GLOB_VidTimer0OVFPtrCallBack)();
	}
}
