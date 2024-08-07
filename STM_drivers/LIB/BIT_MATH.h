/**
  ******************************************************************************
  * @file    : BIT_MATH.h
  * @author  : Abdelrahman Elsayed Ahmed
  * @date	 : 9 / 5 / 2024
  * @version : V1.0
  ******************************************************************************
*/

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG,BIT) 		(REG |= (1<<BIT))
#define CLR_BIT(REG,BIT) 		(REG &= (~(1<<BIT)))
#define TOG_BIT(REG,BIT) 		(REG ^= (1<<BIT))
#define GET_BIT(REG,BIT) 		((REG >> BIT) & 0X01)
#define BIT_IS_SET(REG,BIT) 	(REG & (1 << BIT))
#define BIT_IS_CLR(REG,BIT) 	(!(REG & (1 << BIT)))

#endif /* BIT_MATH_H_ */
