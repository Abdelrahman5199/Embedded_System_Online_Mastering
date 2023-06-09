/*
 * EXT_Prog.c
 *
 *  Created on: Jun 8, 2023
 *      Author: Abdelrahman Kotb
 */


#include"../LIB/STD_TYPES.h"
#include"../LIB/BIT_MATH.h"
#include"EXT_Priv.h"
#include"EXT_Config.h"
#include"EXT_Int.h"
#include"../Global Interrupt/GIE_Config.h"

/**GLOBAL POINTER TO FUNCTION**/
static void (*Gpfunc1)(void)=NULL;
static void (*Gpfunc2)(void)=NULL;
static void (*Gpfunc3)(void)=NULL;
/********CALL BACK FUNCTION*****/
void INT0_VidSetCallBack(void (*Lpfunc)(void))
{
	Gpfunc1=Lpfunc;
}
void INT1_VidSetCallBack(void (*Lpfunc)(void))
{
	Gpfunc2=Lpfunc;
}
void INT2_VidSetCallBack(void (*Lpfunc)(void))
{
	Gpfunc3=Lpfunc;
}

/*************ISR FOR EXTERNAL INTERRUPT**********/
ISR(__vector_1)
{
	if(Gpfunc1 != NULL)
	{
		Gpfunc1();
	}
}
ISR(__vector_2)
{
	if(Gpfunc2 != NULL)
	{
		Gpfunc2();
	}
}
ISR(__vector_3)
{
	if(Gpfunc3 != NULL)
	{
		Gpfunc3();
	}
}


void EXT0_ENABLE(void)
{
	/***INT0 ENABLE***/
	SET_BIT(GICR,INT0_ENABLE);

	/****INT0 MOOD*****/
	#if      MOOD_INT0==Falling_edge
	CLR_BIT(MCUCR,ISC00);
	SET_BIT(MCUCR,ISC01);
	#elif    MOOD_INT0==Rising_edge
	SET_BIT(MCUCR,ISC00);
	SET_BIT(MCUCR,ISC01);
	#elif    MOOD_INT0==Low_level
	CLR_BIT(MCUCR,ISC00);
	CLR_BIT(MCUCR,ISC01);
	#elif    MOOD_INT0==Any_change
	SET_BIT(MCUCR,ISC00);
	CLR_BIT(MCUCR,ISC01);
	#endif

}
void EXT1_ENABLE(void)
{
	/***INT1 ENABLE***/
   SET_BIT(GICR,INT1_ENABLE);

    /****INT1 MOOD*****/
    #if      MOOD_INT1==Falling_edge
    CLR_BIT(MCUCR,ISC10);
    SET_BIT(MCUCR,ISC11);
    #elif    MOOD_INT1==Rising_edge
    SET_BIT(MCUCR,ISC10);
    SET_BIT(MCUCR,ISC11);
    #elif    MOOD_INT1==Low_level
    CLR_BIT(MCUCR,ISC10);
    CLR_BIT(MCUCR,ISC11);
    #elif    MOOD_INT0==Any_change
    SET_BIT(MCUCR,ISC10);
    CLR_BIT(MCUCR,ISC11);
    #endif
}

void EXT2_ENABLE(void)
{

	/***INT2 ENABLE***/
   SET_BIT(GICR,INT2_ENABLE);

	/****INT2 MOOD*****/
	#if      MOOD_INT2==Falling_edge
	CLR_BIT(MCUCSR,ISC2);
	#elif    MOOD_INT1==Rising_edge
	SET_BIT(MCUCSR,ISC2);
	#endif
}
