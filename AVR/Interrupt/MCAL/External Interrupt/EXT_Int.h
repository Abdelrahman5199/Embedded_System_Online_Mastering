/*
 * EXT_Int.h
 *
 *  Created on: Jun 8, 2023
 *      Author: Abdelrahman Kotb
 */

#ifndef EXT_INT_H_
#define EXT_INT_H_

void EXT0_ENABLE(void);
void EXT1_ENABLE(void);
void EXT2_ENABLE(void);
void INT0_VidSetCallBack(void (*Lpfunc)(void));
void INT1_VidSetCallBack(void (*Lpfunc)(void));
void INT2_VidSetCallBack(void (*Lpfunc)(void));


#endif /* EXT_INT_H_ */
