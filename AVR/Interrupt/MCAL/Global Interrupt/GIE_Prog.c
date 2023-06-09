/*
 * GIE_Prog.c
 *
 *  Created on: Jun 8, 2023
 *      Author: Abdelrahman Kotb
 */


#include"../LIB/STD_TYPES.h"
#include"../LIB/BIT_MATH.h"
#include"GIE_Priv.h"
#include"GIE_Config.h"
#include"GIE_Int.h"


void GIE_VidDISABLE(void)
{
  CLR_BIT(SREG,GIE_ENABLE);
}

void GIE_VidENABLE(void)
{
  SET_BIT(SREG,GIE_ENABLE);
}
