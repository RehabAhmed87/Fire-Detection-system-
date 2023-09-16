/*
 * main.c
 *
 * Created on: Sep 10, 2023
 * Author: Rehab
 */

// Include necessary header files
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/ADC/ADC_int.h"
#include "../HAL/LED/led.h"
#include "../HAL/Buzzer/buzzer.h"
#include "../HAL/motor/motor_int.h"
#include "../HAL/dcmotor/dcmotor.h"
#include "../MCAL/UART/UART_init.h"
#include "../HAL/MQ2/mq2.h"

#include<avr/io.h>
#include<stdlib.h>
#include <avr/interrupt.h>
#include<math.h>
#include <avr/delay.h>

int main(void){

    // Initialize Red LED and Buzzer
	ST_LED_t redLed={PORT_B,PIN_1,SRC,LOW};
	ST_BUZZER_t buzzer={PORT_B,PIN_0,LOW};

    // Initialize LED and Buzzer
	HLED_vidInit(&redLed);
	HBUZZER_vidInit(&buzzer);

    // Initialize Motors and UART
	MOTOR_Init();
	DCMOTOR_Init();
	UART_init();
	ADC_Init(AVCC,prescaller128);

    while(1){
        // Declare variables for temperature and smoke values
        u32 readHeat;
        u16 readSmoke;
        u8 d;

        // Read smoke sensor
        readSmoke = isThereSmoke();

        // Read temperature sensor
        readHeat = ADC_TEMP(Channel_A5);

        // Check if temperature is less than or equal to 40 degrees Celsius
        if(readHeat <= 40){
            HLED_vidTurnOff(&redLed);
            HBUZZER_vidTurnOff(&buzzer);
            MOTOR_CWQU();
            DCMOTOR_Stop();
            UART_sendchar(NULL);
        }

        // Check if temperature is between 40 and 45 degrees Celsius
        if((readHeat > 40) && (readHeat <= 45)){
            UART_sendchar('A');
            HLED_vidToggle(&redLed);
            HBUZZER_vidToggle(&buzzer);
            MOTOR_CWQU();
            DCMOTOR_Stop();
        }

        // Check if temperature is between 45 and 50 degrees Celsius and there is smoke
        if ((readHeat > 45) && (readHeat < 50) && (readSmoke != 0)){
            HBUZZER_vidTurnOn(&buzzer);
            HLED_vidTurnOn(&redLed);
            MOTOR_CWQU();
            DCMOTOR_Stop();
        }

        // Check if temperature is greater than or equal to 50 degrees Celsius
        if(readHeat >= 50){
            UART_sendchar('F');

            // Receive a character from UART
            d = UART_recievechar();

            if(d == 'm'){
                MOTOR_CCWQU();
            }

            else if(d == 'd'){
                DCMOTOR_CW();
            }
            else if(d == 'c'){
                HLED_vidTurnOff(&redLed);
                HBUZZER_vidTurnOff(&buzzer);
            }
        }
    }

    return 0;
}




