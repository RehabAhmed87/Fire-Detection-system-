/*
 * UART.c
 *
 *  Created on: Aug 29, 2023
 *      Author: WIN 10 PRO
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "UART_init.h"
#include <avr/io.h>
#include <avr/delay.h>

void UART_init(void)
{
 //cntrol ucsrc
	UCSRC=0b10000110;
	UBRRL=51;
// enable teasmit
	SET_BIT(UCSRB,TXEN);
	//enable recive
	SET_BIT(UCSRB,RXEN);
}
void UART_sendchar(u8 data)
{
	while(GET_BIT(UCSRA,UDRE)==0);
	UDR=data;
}

void UART_sendstring(u8 *data)
{    u8 i=0;
	while(data[i])
	{
		UART_sendchar(data[i]);
				i++;
	}
}
u8 UART_recievechar(void)
{
	while(GET_BIT(UCSRA,RXC)==0);
	return UDR;
}
