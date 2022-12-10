/*
 * main.c
 *
 *  Created on: Dec 10, 2022
 *      Author: yara
 */
#include"LIB/STD_Type.h"
#include"LIB/BIT_MATH.h"
#include"MCAL/MDIO/MDIO_Interface.h"
#include<util\delay.h>
#include "HAL/HCLCD/HCLCD_Interface.h"
#include "HAL/HCLCD/HCLCD_Confag.h"
#include "HAL/HCLCD/HCLCD_Private.h"

#define TCCR1A        *((volatile u8*)0x4F)
#define TCCR1B        *((volatile u8*)0x4E)

#define ICR1          *((volatile u16*)0x46)
#define OCR1A         *((volatile u16*)0x4A)

#define MOTOR1_A1 3
#define MOTOR1_A2 4

#define MOTOR1_EN 5
u16 Speed=0 ;


/**
 *Calculation of the Timers
 * Tpreiod desired= 20 ms
 * Freq desired= 50hz
 *Sys_Freq= 16000000
 *Presacalar=64
 *TickTime=0.004 ms
 *to have 20 ms period ==> count till 5000 ==> ICR1
 *to have 10 ms on time ==> Put 2500 in OCR1A
 * thus we have 50% duty cylce
 */


void TIMER1_VidInit(void)
{
	/*Set Fast pwm mode with top-->ICR1*/
	CLR_BIT(TCCR1A,0);
	SET_BIT(TCCR1A,1);
	SET_BIT(TCCR1B,4);
	SET_BIT(TCCR1B,3);

	/*Set non-inverting Fast pwm channel A*/
	SET_BIT(TCCR1A,7);
	CLR_BIT(TCCR1A,6);

	/*Set Prescaler-->>64 Prescaler*/
	SET_BIT(TCCR1B,0);
	SET_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,2);
}

void TIMER1_SetTopValue(u16 Copy_u16TopValue)
{
	ICR1=Copy_u16TopValue;
}

void TIMER1_Set_OCR1A_Value(u16 Copy_u16CTCValue)
{
	OCR1A=Copy_u16CTCValue;
}

int main(void)
{
	u8 Copy_u8Counter=0;
	u8 Ton=2500;
	u8 Tpreiod=5000;
	float Duty_cycle ;
	float time ;
	/*Set Top value in ICR1*/
	TIMER1_SetTopValue(Tpreiod);

	/*Timer1 Initialization---> MODE(14)-->FAST PWM-->TOP -->ICR1 */
	TIMER1_VidInit();
	HCLCD_Init4Bit();
	MDIO_SetPinDirection(MOTOR1_A1,MDIO_PORTC,PIN_OUTPUT);
	MDIO_SetPinDirection(MOTOR1_A2,MDIO_PORTC,PIN_OUTPUT);
	MDIO_SetPinDirection(MOTOR1_EN,MDIO_PORTD,PIN_OUTPUT);
	u8 freq[7] = "Freq =";
	u8 Duty[7] = "D =";

	while(1)
	{
		//Set Forward Direction
		MDIO_SetPinValue(MOTOR1_A1,MDIO_PORTC,PIN_HIGH);
		MDIO_SetPinValue(MOTOR1_A2,MDIO_PORTC,PIN_LOW);
		TIMER1_Set_OCR1A_Value(Ton);// Ton
		float Duty_cycle = (float)Ton/Tpreiod;
		float time = 1.0/Duty_cycle;
		/*
		 *  then duty cycle = Ton/Tperiod
		 *  = 50%
		 */
		HCLCD_String_Write(freq);
		HCLCD_WritChar4Bit('5');
		HCLCD_WritChar4Bit('0');
		HCLCD_WritChar4Bit('h');
		HCLCD_WritChar4Bit('z');
		HCLCD_WritChar4Bit('/');
		HCLCD_String_Write(Duty);
		HCLCD_WritChar4Bit('5');
		HCLCD_WritChar4Bit('0');
		HCLCD_WritChar4Bit('%');
		HCLCD_SetCursorPosition4Bit(HCLCD_LINE1, 0);
		for(Copy_u8Counter=0;Copy_u8Counter<4;Copy_u8Counter++)
		{
			HCLCD_WritChar4Bit('-');
		}
		HCLCD_WritChar4Bit('|');
		for(Copy_u8Counter=0;Copy_u8Counter<4;Copy_u8Counter++)
		{
			HCLCD_WritChar4Bit('_');
		}
		HCLCD_WritChar4Bit('|');
		for(Copy_u8Counter=0;Copy_u8Counter<4;Copy_u8Counter++)
		{
			HCLCD_WritChar4Bit('-');
		}
		HCLCD_WritChar4Bit('|');
		HCLCD_WritChar4Bit('_');
	}
	return 0;
}

