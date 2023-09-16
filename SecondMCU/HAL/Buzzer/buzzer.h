/*
 * buzzer.h
 *
 *  Created on: Sep 10, 2023
 *      Author: dell
 */

#ifndef MCU2_HAL_BUZZER_BUZZER_H_
#define MCU2_HAL_BUZZER_BUZZER_H_

typedef struct buzzer{
	u8 st_u8PortNumber;
	u8 st_u8PinNumber;
	u8 st_u8OnValue;
} ST_BUZZER_t;


void HBUZZER_vidInit(ST_BUZZER_t * add_pstbuzzer);
void HBUZZER_vidTurnOn(ST_BUZZER_t * add_pstbuzzer);
void HBUZZER_vidTurnOff(ST_BUZZER_t * add_pstbuzzer);
void HBUZZER_vidToggle(ST_BUZZER_t * add_pstbuzzer);

#endif /* MCU2_HAL_BUZZER_BUZZER_H_ */
