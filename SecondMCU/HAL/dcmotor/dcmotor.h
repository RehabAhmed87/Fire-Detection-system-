/*
 * dcmotor.h
 *
 *  Created on: Sep 13, 2023
 *      Author: dell
 */

#ifndef HAL_DCMOTOR_DCMOTOR_H_
#define HAL_DCMOTOR_DCMOTOR_H_
#define DCMOTOR_PORT PORT_C
#define BLUE      PIN_0
#define PINK      PIN_1
#define YELLOW    PIN_2
#define ORANGE    PIN_3






void DCMOTOR_Init(void);


void DCMOTOR_Stop(void);

void DCMOTOR_CW(void);

void DCMOTOR_CCW(void);


#endif /* HAL_DCMOTOR_DCMOTOR_H_ */
