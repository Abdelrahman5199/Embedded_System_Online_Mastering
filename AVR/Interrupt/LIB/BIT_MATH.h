/*
 * BIT_MATH.h
 *
 *  Created on: Jun 8, 2023
 *      Author: Abdelrahman Kotb
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define CLR_BIT(var,bit_num)      var=var&(~(1<<bit_num))
#define SET_BIT(var,bit_num)      var=var|(1<<bit_num)
#define TOG_BIT(var,bit_num)	  var^=(1<<bit_num)
#define GET_BIT(var,bit_num)      (var>>bit_num)&1

#endif /* BIT_MATH_H_ */
