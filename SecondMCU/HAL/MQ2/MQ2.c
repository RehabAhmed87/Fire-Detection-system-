/*
 * MQ2.c
 *
 *  Created on: Sep 14, 2023
 *      Author: Rehab
 */

#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "MQ2.h"

u16 isThereSmoke (void){

	MDIO_vidSetPinDirection(PORT_MQ2,PIN_MQ2,INPUT);
	u16 smoke = MDIO_vidGetPinValue(PORT_D,PIN_2);
	return smoke;

}
