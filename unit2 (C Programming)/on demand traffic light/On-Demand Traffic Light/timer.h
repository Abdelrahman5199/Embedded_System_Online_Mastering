#ifndef TIMER_H_
#define TIMER_H_

#include "registers.h"


void TIMER_init();//initialize Timer0
void TIMER_delay(uint16_t millisec); //delay of specific amount default uses 256


#endif /* TIMER_H_ */

