/*
 *
 *      Author: Abdelrahman Kotb
 *
 */

#ifndef STM32_RCC_H_
#define STM32_RCC_H_

//includes
#include "STM32F103x8.h"



#define  HSE_Clock			(uint32_t)16000000
#define  HSI_RC_Clk			(uint32_t)8000000


uint32_t MCAL_RCC_GetSYS_CLCKFreq(void);
uint32_t MCAL_RCC_GetHCLKFreq(void);
uint32_t MCAL_RCC_GetPCLK1Freq(void);
uint32_t MCAL_RCC_GetPCLK2Freq(void);





#endif /* STM32_RCC_H_ */
