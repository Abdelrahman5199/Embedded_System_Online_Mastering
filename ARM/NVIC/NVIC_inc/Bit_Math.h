/*
 * Bit_Math.h
 *
 *  Created on: Apr 15, 2022
 *      Author: Ahmed
 */

#ifndef LIB_BIT_MATH_H_
#define LIB_BIT_MATH_H_

#define SET_BIT(REG,BIT) (REG) |= (1<<(BIT))
#define CLR_BIT(REG,BIT) (REG) &= ~(1<<(BIT))
#define TGL_BIT(REG,BIT) (REG) ^= (1<<(BIT))
#define GET_BIT(REG,BIT) (1 & (REG>>BIT))



#endif /* LIB_BIT_MATH_H_ */
