/*
 * Timer0_Interface.h
 *
 *  Created on: Jun 8, 2023
 *      Author: Abdelrahman Kotb
 */

#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

#include "STD_TYPES.h"

/************************************************************************************/
/*							 FUNCTIONS PROTOTYPES								    */
/************************************************************************************/

/************************************************************************************/
/* Description: initializes timer0's peripheral	  								    */
/* Inputs: nothing													 	 		    */
/* Output: error checking								  						    */
/************************************************************************************/
extern u8 Timer0_U8Init(void);
/************************************************************************************/

/************************************************************************************/
/* Description: set a value to start counting from								    */
/* Inputs: value to count from													 	*/
/* Output: error checking								  						    */
/************************************************************************************/
extern u8 Timer0_U8Preload(const u8 LOC_U8Value);
/************************************************************************************/

/************************************************************************************/
/* Description: set a value to compare with in non-normal modes					    */
/* Inputs: value to compare with									 	 		    */
/* Output: error checking								  						    */
/************************************************************************************/
extern u8 Timer0_U8SetCTCValue(const u8 LOC_U8Value);
/************************************************************************************/

/************************************************************************************/
/* Description: returns the value in timer0's counter. Counts are in the range of   */
/* 0 - 255.					    													*/
/* Inputs: pointer to a variable to receive the value in			 	 		    */
/* Output: error checking								  						    */
/************************************************************************************/
extern u8 Timer0_U8GetCounterValue(u8* const LOC_U8Value);
/************************************************************************************/

/************************************************************************************/
/* Description: enables overflow interrupt										    */
/* Inputs: nothing													 	 		    */
/* Output: error checking								  						    */
/************************************************************************************/
extern u8 Timer0_U8EnableOVFInterrupt(void);
/************************************************************************************/

/************************************************************************************/
/* Description: disables overflow interrupt										    */
/* Inputs: nothing													 	 		    */
/* Output: error checking								  						    */
/************************************************************************************/
extern u8 Timer0_U8DisableOVFInterrupt(void);
/************************************************************************************/

/************************************************************************************/
/* Description: enables On Compare Match interrupt								    */
/* Inputs: nothing													 	 		    */
/* Output: error checking								  						    */
/************************************************************************************/
extern u8 Timer0_U8EnableOCMInterrupt(void);
/************************************************************************************/

/************************************************************************************/
/* Description: disables On Compare Match interrupt								    */
/* Inputs: nothing													 	 		    */
/* Output: error checking								  						    */
/************************************************************************************/
extern u8 Timer0_U8DisableOCMInterrupt(void);
/************************************************************************************/

/************************************************************************************/
/* Description: takes a pointer to a function that is to be executed on		  	    */
/* triggering the overflow interrupt.  								 			    */
/* Inputs: pointer to a function that takes no arguments and returns no value	    */
/* Output: error checking								  						    */
/************************************************************************************/
extern u8 Timer0_U8OVFSetCallBack( void (*ptrToFun)(void) );
/***********************************************************************************/

/***********************************************************************************/
/* Description: takes a pointer to a function that is to be executed on		  	   */
/* triggering the On Compare Match interrupt.						 			   */
/* Inputs: pointer to a function that takes no arguments and returns no value	   */
/* Output: error checking								  						   */
/***********************************************************************************/
extern u8 Timer0_U8OCMSetCallBack( void (*ptrToFun)(void) );
/************************************************************************************/

/***********************************************************************************/
/* Description: polls on timer0 overflow's flag						 			   */
/* Inputs: nothing					   											   */
/* Output: error checking								  						   */
/***********************************************************************************/
extern u8 Timer0_U8OVFPollingOnFlag(void);
/***********************************************************************************/

/***********************************************************************************/
/* Description: polls on timer0 on compare match's flag				 			   */
/* Inputs: nothing					   											   */
/* Output: error checking								  						   */
/***********************************************************************************/
extern u8 Timer0_U8OCMPollingOnFlag(void);
/***********************************************************************************/


/***********************************************************************************/
/* Description: sends a PWM signal with the received duty cycle (0% - 100%) on OC0 */
/* pin. 	   																	   */
/* Inputs: analog voltage			   											   */
/* Output: error checking								  						   */
/***********************************************************************************/
extern u8 Timer0_U8SetDutyCycle(const f32 LOC_F32DutyCycle);
/***********************************************************************************/


/***********************************************************************************/
/* Description: restarts timer0's prescaler. Note that this	affects both timer0	   */
/* and timer1						 			   			   					   */
/* Inputs: nothing					   											   */
/* Output: error checking								  						   */
/***********************************************************************************/
extern u8 Timer0_U8ResetPrescaler(void);
/***********************************************************************************/

#endif /* TIMER0_INTERFACE_H_ */
