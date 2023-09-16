/*
 * led.c
 *
 *  Created on: Aug 20, 2023
 *      Author: dell
 */
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_int.h"
#include"led.h"
#include <avr/delay.h>

void HLED_vidInit(ST_LED_t * add_pstLed)
{//check the type of connection
if(add_pstLed -> st_u8ConnectionType ==SRC){
	add_pstLed -> st_u8OnValue =HIGH;
}
else if(add_pstLed -> st_u8ConnectionType ==SINK){
	add_pstLed -> st_u8OnValue =LOW;
}
MDIO_vidSetPinDirection(add_pstLed -> st_u8PortNumber,add_pstLed -> st_u8PinNumber,OUTPUT);
}

void HLED_vidTurnOn(ST_LED_t * add_pstLed){
	MDIO_vidSetPinValue(add_pstLed -> st_u8PortNumber,add_pstLed ->st_u8PinNumber,add_pstLed -> st_u8OnValue);
}
void HLED_vidTurnOff(ST_LED_t * add_pstLed){
	MDIO_vidSetPinValue(add_pstLed -> st_u8PortNumber,add_pstLed -> st_u8PinNumber,!(add_pstLed -> st_u8OnValue));
}

void HLED_vidToggle(ST_LED_t * add_pstLed){
	MDIO_vidSetPinValue( add_pstLed -> st_u8PortNumber, add_pstLed ->st_u8PinNumber, add_pstLed -> st_u8OnValue);
	_delay_ms(200);
	MDIO_vidSetPinValue( add_pstLed -> st_u8PortNumber, add_pstLed -> st_u8PinNumber,!( add_pstLed -> st_u8OnValue));
	_delay_ms(10);
}

