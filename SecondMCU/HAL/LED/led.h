/*
 * led.h
 *
 *  Created on: Aug 20, 2023
 *      Author: dell
 */

#ifndef LED_H_
#define LED_H_
typedef struct led{
	u8 st_u8PortNumber;
	u8 st_u8PinNumber;
	u8 st_u8ConnectionType;
	u8 st_u8OnValue;
} ST_LED_t;
#define SRC   (u8)1
#define SINK  (u8)0


void HLED_vidInit(ST_LED_t * add_pstLed);
void HLED_vidTurnOn(ST_LED_t * add_pstLed);
void HLED_vidTurnOff(ST_LED_t * add_pstLed);
void HLED_vidToggle(ST_LED_t * add_pstLed);
#endif /* LED_H_ */
