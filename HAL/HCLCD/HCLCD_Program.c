#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Type.h"
#include "../../MCAL/MDIO/MDIO_Interface.h"
#include "HCLCD_Interface.h"
#include <util/delay.h>
#include "HCLCD_Confag.h"
#include "HCLCD_Private.h"
void HCLCD_WriteCommand4Bit(u8 Copy_u8Comman)
{
	// Set RW to Zero
	MDIO_SetPinValue(RW,CONTROL_PORT, PIN_LOW);

	// Set RS to Zero ==> to indicate a command
	MDIO_SetPinValue(RS,CONTROL_PORT, PIN_LOW);

	//Set High Nibble Value if the Command
	MDIO_SetNibbleValue(HCLCD_PIN_START,DATA_PORT , Copy_u8Comman>>4 );

	// Send the Falling Edge
	MDIO_SetPinValue(E, CONTROL_PORT, PIN_HIGH);
	_delay_ms(2);
	MDIO_SetPinValue(E, CONTROL_PORT, PIN_LOW);

	//Set low Nibble Value if the Command
	MDIO_SetNibbleValue(HCLCD_PIN_START,DATA_PORT , Copy_u8Comman );

	// Send the Falling Edge
	MDIO_SetPinValue(E, CONTROL_PORT, PIN_HIGH);
	_delay_ms(2);
	MDIO_SetPinValue(E, CONTROL_PORT, PIN_LOW);
}

void HCLCD_Init4Bit()
{
	_delay_ms(35);
	u8 Loc_u8Counter=0;
	// Set Direction of the used pins
	for(Loc_u8Counter = HCLCD_PIN_START;Loc_u8Counter<(HCLCD_PIN_START+4);Loc_u8Counter++)
	{
		MDIO_SetPinDirection(Loc_u8Counter, DATA_PORT, PIN_OUTPUT);
	}
	// Set Direction of the Control pins
	MDIO_SetPinDirection(RS, CONTROL_PORT, PIN_OUTPUT);
	MDIO_SetPinDirection(RW, CONTROL_PORT, PIN_OUTPUT);
	MDIO_SetPinDirection(E, CONTROL_PORT, PIN_OUTPUT);


	MDIO_SetNibbleValue(HCLCD_PIN_START, DATA_PORT, FUNCTION_SET_MODE >> 4);
	// Send the Falling Edge
	MDIO_SetPinValue(E, CONTROL_PORT, PIN_HIGH);
	_delay_ms(2);
	MDIO_SetPinValue(E, CONTROL_PORT, PIN_LOW);

	//Start of the initialization sequence
	// Send Function Set Command
	_delay_ms(1);
	HCLCD_WriteCommand4Bit(FUNCTION_SET_MODE);
	// Set Function Display ON/OFF
	_delay_ms(1);
	HCLCD_WriteCommand4Bit(DISPLAY_COMMAND);
	// Set Function Display clear
	_delay_ms(1);
	HCLCD_WriteCommand4Bit(DISPLAY_CLEAR);
	// Entry mode
	_delay_ms(2);
	HCLCD_WriteCommand4Bit(ENTRY_MODE_COMMAND);
}

void HCLCD_WritChar4Bit(u8 Copy_u8Data)
{
	// Set RW to Zero
	MDIO_SetPinValue(RW,CONTROL_PORT, PIN_LOW);

	// Set RS to Zero ==> to indicate a command
	MDIO_SetPinValue(RS,CONTROL_PORT, PIN_HIGH);

	//Set High Nibble Value if the Command
	MDIO_SetNibbleValue(HCLCD_PIN_START,DATA_PORT , Copy_u8Data>>4 );

	// Send the Falling Edge
	MDIO_SetPinValue(E, CONTROL_PORT, PIN_HIGH);
	_delay_ms(2);
	MDIO_SetPinValue(E, CONTROL_PORT, PIN_LOW);

	//Set low Nibble Value if the Command
	MDIO_SetNibbleValue(HCLCD_PIN_START,DATA_PORT , Copy_u8Data );

	// Send the Falling Edge
	MDIO_SetPinValue(E, CONTROL_PORT, PIN_HIGH);
	_delay_ms(2);
	MDIO_SetPinValue(E, CONTROL_PORT, PIN_LOW);
}


void HCLCD_SetCursorPosition4Bit(u8 LineNumber , u8 PositionNumber)
{
	if((LineNumber == HCLCD_LINE0)||(LineNumber == HCLCD_LINE1))
	{
		if (PositionNumber<16)
		{
			if(LineNumber==HCLCD_LINE0)
			{
				// line 1
				HCLCD_WriteCommand4Bit(PositionNumber+HCLCD_LINE1_OFFSET);
			}
			else
			{
				HCLCD_WriteCommand4Bit(PositionNumber+HCLCD_LINE2_OFFSET);
			}
		}
		else
		{
			//wrong Position
		}
	}
	else
	{
		//wrong line chosen
	}

}

void HCLCD_String_Write (u8 *str)
{
	u8 Counter=0;
	for(Counter=0;str[Counter]!=0;Counter++)  /* send each char of string till the NULL */
	{
		HCLCD_WritChar4Bit(str[Counter]);  /* call LCD data write */
	}
}

void HCLCD_String_Write_Position (u8 *str , u8 LineNumber , u8 PositionNumber)
{
	HCLCD_SetCursorPosition4Bit( LineNumber ,  PositionNumber);
	u8 Counter=0;
		for(Counter=0;str[Counter]!=0;Counter++)  /* send each char of string till the NULL */
		{
			HCLCD_WritChar4Bit(str[Counter]);  /* call LCD data write */
		}

}

void HCLCD_WriteDigits4Bit(u8 Copy_u8Number)
{
	u8 Copy_u8Digit = 0;
	u8 Copy_u8Answer = 0;
	u8 Copy_u8Module = 0;
	while(Copy_u8Number > 0)
	{
		Copy_u8Module = Copy_u8Number % 10;

		Copy_u8Answer = Copy_u8Answer * 10 + Copy_u8Module;

		Copy_u8Number = Copy_u8Number / 10;
	}

	while(Copy_u8Number > 0)
	{
		Copy_u8Digit = Copy_u8Number % 10;
		HCLCD_WritChar4Bit(Copy_u8Digit);
		Copy_u8Number = Copy_u8Number / 10;
	}
}


