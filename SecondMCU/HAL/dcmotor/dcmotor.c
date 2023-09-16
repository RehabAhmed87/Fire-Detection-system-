/*
 * dcmotor.c
 *
 *  Created on: Sep 13, 2023
 *      Author: dell
 */



#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "dcmotor.h"
#include <avr/delay.h>

void DCMOTOR_Init(void)
{
	MDIO_vidSetPortDirection(DCMOTOR_PORT,0x0f);
}


void DCMOTOR_Stop(void)
{
	MDIO_vidSetPinValue(DCMOTOR_PORT,BLUE,LOW);
	MDIO_vidSetPinValue(DCMOTOR_PORT,PINK,LOW);
	MDIO_vidSetPinValue(DCMOTOR_PORT,YELLOW,LOW);
	MDIO_vidSetPinValue(DCMOTOR_PORT,ORANGE,LOW);
}

void DCMOTOR_CW(void)
{
	MDIO_vidSetPinValue(DCMOTOR_PORT,BLUE,HIGH);
	MDIO_vidSetPinValue(DCMOTOR_PORT,PINK,LOW);
	MDIO_vidSetPinValue(DCMOTOR_PORT,YELLOW,HIGH);
	MDIO_vidSetPinValue(DCMOTOR_PORT,ORANGE,LOW);

}
void DCMOTOR_CCW(void)
{
	MDIO_vidSetPinValue(DCMOTOR_PORT,BLUE,LOW);
	MDIO_vidSetPinValue(DCMOTOR_PORT,PINK,HIGH);
	MDIO_vidSetPinValue(DCMOTOR_PORT,YELLOW,LOW);
	MDIO_vidSetPinValue(DCMOTOR_PORT,ORANGE,HIGH);

}

