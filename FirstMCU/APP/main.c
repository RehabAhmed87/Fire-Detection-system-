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

#include "../MCAL/GLOBAL_INIT/GLOBAL_int.h"
#include "../MCAL/EXTI/EXTI_int.h"
#include "../MCAL/UART/UART_init.h"
#include "../HAL/keybad/keybad_int.h"
#include "../HAL/lcd/LCD_int.h"

#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>


int main(){

    // Initialize the keypad
    keybad_inti();

    // Initialize UART communication
    UART_init();

    // Initialize a variable v
    u8 v=0;

    // Initialize the LCD
    HCLCD_vidInit();

    // Send the initial value of v to the LCD
    HCLCD_vidSendData(v);

    while(1){
        // Receive a character from UART
        v=UART_recievechar();

        // Check if the received character is NULL
        if (v == NULL)
        {
            // Clear the LCD and display "Idle ..."
            HCLCD_vidClear();
            HCLCD_vidSendString("Idle ...");
        }

        // Check if the received character is 'A'
        if(v== 'A'){
            // Clear the LCD and display "Alarm ..."
            HCLCD_vidClear();
            HCLCD_vidSendString("Alert ...");
        }

        // Check if the received character is 'F'
        if(v== 'F'){
            // Enter a loop while 'F' is received
            while(v== 'F'){
                u8 key;
                // Get a key press from the keypad
                key = keybad_PressKey();
                // Clear the LCD and display instructions
                HCLCD_vidClear();
                HCLCD_vidSendString("Choose action: ");
                _delay_ms(20);
                HCLCD_vidClear();
                HCLCD_vidSendString("1-Open doors");
                HCLCD_vidGoTo(1,0);
                _delay_ms(20);
                HCLCD_vidSendString("2-Ventilation system");
                _delay_ms(20);

                // Get another key press
                key = keybad_PressKey();

                // Check if a key is pressed
                if (key!=NO_KEY)
                {
                    // Send a corresponding character via UART
                    if(key=='1'){
                        UART_sendchar('m');
                    }
                    else if(key=='2'){
                        UART_sendchar('d');
                    }
                    else if(key=='n'){
                        UART_sendchar('c');
                      }
                }
            }
        }
    }

    return 0;
}
