/*
 * buzzer.c
 *
 *  Created on: Sep 10, 2023
 *      Author: dell
 */

#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_int.h"
#include"buzzer.h"
#include <avr/delay.h>


void HBUZZER_vidInit(ST_BUZZER_t * add_pstbuzzer)
{
	MDIO_vidSetPinDirection(add_pstbuzzer -> st_u8PortNumber,add_pstbuzzer -> st_u8PinNumber,OUTPUT);
		add_pstbuzzer -> st_u8OnValue =LOW;


}

void HBUZZER_vidTurnOn(ST_BUZZER_t * add_pstbuzzer){
	MDIO_vidSetPinValue(add_pstbuzzer -> st_u8PortNumber,add_pstbuzzer ->st_u8PinNumber,!(add_pstbuzzer -> st_u8OnValue));
}
void HBUZZER_vidTurnOff(ST_BUZZER_t * add_pstbuzzer){
	MDIO_vidSetPinValue(add_pstbuzzer -> st_u8PortNumber,add_pstbuzzer ->st_u8PinNumber,add_pstbuzzer -> st_u8OnValue);
}
void HBUZZER_vidToggle(ST_BUZZER_t * add_pstbuzzer){
	MDIO_vidSetPinValue(add_pstbuzzer -> st_u8PortNumber,add_pstbuzzer ->st_u8PinNumber,add_pstbuzzer -> st_u8OnValue);
	_delay_ms(150);
	MDIO_vidSetPinValue(add_pstbuzzer -> st_u8PortNumber,add_pstbuzzer -> st_u8PinNumber,!(add_pstbuzzer -> st_u8OnValue));
	_delay_ms(10);
}
