/*
 * EXT_Config.h
 *
 *  Created on: Jun 8, 2023
 *      Author: Abdelrahman Kotb
 */

#ifndef EXT_CONFIG_H_
#define EXT_CONFIG_H_

/************MCUCR********/
#define  ISC00    0
#define  ISC01    1
#define  ISC10    2
#define  ISC11    3
/************MCUCSR*******/
#define  ISC2     6
/************GICR********/
#define  INT0_ENABLE    6
#define  INT1_ENABLE    7
#define  INT2_ENABLE    5
/*************************/
/*************************/


/****MOOD OF INTERUPT****/
#define Falling_edge     0
#define Rising_edge      1
#define Low_level        2
#define Any_change       3
/***********************************/
#define    MOOD_INT0      Falling_edge
#define    MOOD_INT1      Falling_edge
#define    MOOD_INT2      Falling_edge
/***********************************/

#endif /* EXT_CONFIG_H_ */
