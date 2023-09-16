/*
 * ADC_int.h
 *
 *  Created on: Aug 23, 2023
 *      Author: WIN 10 PRO
 */

#ifndef MCAL_ADC_ADC_INT_H_
#define MCAL_ADC_ADC_INT_H_


#define ADMUX (*(volatile u8*)0x27)
#define ADMUX_REFS1  7
#define ADMUX_REFS0  6
#define ADLAR         5
#define ADMUX_MUX4    4
#define ADMUX_MUX3    3
#define ADMUX_MUX2     2
#define ADMUX_MUX1     1
#define ADMUX_MUX0      0
#define ADCSRA (*(volatile u8*)0x26)
#define ADCSRA_ADEN  7
#define ADCSRA_ADSC  6
#define ADCSRA_ADATE  5
#define ADCSRA_ADIF  4
#define ADCSRA_ADIE  3
#define ADCSRA_ADPS2  2
#define ADCSRA_ADPS1  1
#define ADCSRA_ADPS0  0
//#define ADCH (*(volatile)u8*)0x25)
//#define ADCL (*(volatile)u8*)0x24)
#define ADC_REG  (*(volatile u16*)0x24)
#define SFIOR (*(volatile u8*)0x50)
#define SFIOR_ADTS2   7
#define SFIOR_ADTS1   6
#define SFIOR_ADTS0   5


#define Channel_A0  0
#define Channel_A1  1
#define Channel_A2  2
#define Channel_A3  3
#define Channel_A4  4
#define Channel_A5  5
#define Channel_A6  6
#define Channel_A7  7


#define ACME 3
#define PUD 2
#define PSR2 1
#define PSR10 0


#define ERFF  0
#define AVCC   1
#define internal 3

#define prescaller2 0
#define prescaller4 1
#define prescaller8 2
#define prescaller16 3
#define prescaller32 4
#define prescaller128 5

void ADC_Init (u8 volt_ref,u8 prescaller);// ADC Initialization And Enable
u16 ADC_Read (u8 cpy_u8channel); // Read From The ADC Channel
f32 ADC_VOLT(u8 cpy_u8channel);
f32 ADC_TEMP(u8 cpy_u8channel);


void ADC_SETCALL_BACK(void(*ptr)(void));

#endif /* MCAL_ADC_ADC_INT_H_ */
