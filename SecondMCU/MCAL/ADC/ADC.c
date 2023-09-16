/*
 * ADC.c
 *
 *  Created on: Aug 23, 2023
 *      Author: WIN 10 PRO
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../DIO/DIO_int.h"
#include "../GLOBAL_INIT/GLOBAL_int.h"
#include "ADC_int.h"
#include<avr/io.h>
#include<stdlib.h>
#include<math.h>
#include <avr/delay.h>

void (*ADC_CALLBACK)(void)=  NULL;



void ADC_Init (u8 volt_ref,u8 prescaller)
{
	//volt ref.
	switch (volt_ref) {
	case ERFF:
		CLEAR_BIT(ADMUX,ADMUX_REFS0);
		CLEAR_BIT(ADMUX,ADMUX_REFS1);

		break;
	case AVCC:
		SET_BIT(ADMUX,ADMUX_REFS0);
		CLEAR_BIT(ADMUX,ADMUX_REFS1);

		break;
	case internal:
	    SET_BIT(ADMUX,ADMUX_REFS0);
	     SET_BIT(ADMUX,ADMUX_REFS1);

	break;

	default:
		break;
	}
	//data direction
     CLEAR_BIT(ADMUX,ADLAR);

	//prescaller
      switch(prescaller)
      {
      case prescaller2:
    	  CLEAR_BIT(ADCSRA,ADCSRA_ADPS0);
    	  CLEAR_BIT(ADCSRA,ADCSRA_ADPS1);
    	  CLEAR_BIT(ADCSRA,ADCSRA_ADPS2);
    	  break;
      case prescaller4:
          	  CLEAR_BIT(ADCSRA,ADCSRA_ADPS0);
          	  SET_BIT(ADCSRA,ADCSRA_ADPS1);
          	  CLEAR_BIT(ADCSRA,ADCSRA_ADPS2);
          	  break;
      case prescaller8:
    	  SET_BIT(ADCSRA,ADCSRA_ADPS0);
          SET_BIT(ADCSRA,ADCSRA_ADPS1);
          CLEAR_BIT(ADCSRA,ADCSRA_ADPS2);
          break;
      case prescaller128:
         	  SET_BIT(ADCSRA,ADCSRA_ADPS0);
              SET_BIT(ADCSRA,ADCSRA_ADPS1);
              SET_BIT(ADCSRA,ADCSRA_ADPS2);
              break;

      }

	//adc enable
      SET_BIT(ADCSRA, ADCSRA_ADEN);
}

u16 ADC_Read(u8 cpy_u8channel)//00000010
{
	//SELECT CHANNEL
		ADMUX=ADMUX&0b11100000;
		ADMUX=ADMUX|cpy_u8channel;   //11100000|00000001=11100001

		// START CON.
		 SET_BIT(ADCSRA,ADCSRA_ADSC);
		//WAITE
		 while(!GET_BIT(ADCSRA,ADCSRA_ADIF));
		 //clear flag
		   SET_BIT(ADCSRA,ADCSRA_ADIF);
		//RETURN
		   return ADC_REG;

}



f32 ADC_VOLT(u8 cpy_u8channel)  //v/vref = adc/1024>> v=(adc*vref)/1024
{
   f32 num;
   f32  volt;
   num= ADC_Read(cpy_u8channel);
   volt= (num*(f32)5)/(f32)1024;
   return volt;

}

f32 ADC_TEMP(u8 cpy_u8channel)
{   f32 num;
f32  temp;
    num=ADC_VOLT(cpy_u8channel);   //volt*1000/10>>>>>volt *100
    temp= (num*100);

    return  temp;
}



void ADC_SETCALL_BACK(void(*ptr)(void))
{
	ADC_CALLBACK=ptr;
}

void __vector_16 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_16 (void){
	ADC_CALLBACK();
}
