#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Type.h"
#include "../../MCAL/MDIO/MDIO_Interface.h"
#include "HKPD_Interface.h"
#include <util/delay.h>
#include "HKPD_Confag.h"
#include "HKPD_Private.h"
#include "../../MCAL/MDIO/MDIO_Private.h"
#include "../../HAL/HCLCD/HCLCD_Interface.h"
#include "../../HAL/HCLCD/HCLCD_Private.h"
//#include "../../HAL/HCLCD/HCLCD_Private.h"

u8 Cursor_Postion_LCD = 0;

void HKPD_Init()
{
	/*Set pins directions*/

	// Set columns pin to be output
	MDIO_SetPinDirection(PIN0, HKPD_COLUMN_PORT, PIN_OUTPUT);
	MDIO_SetPinDirection(PIN1, HKPD_COLUMN_PORT, PIN_OUTPUT);
	MDIO_SetPinDirection(PIN4, HKPD_COLUMN_PORT, PIN_OUTPUT);
	MDIO_SetPinDirection(PIN5, HKPD_COLUMN_PORT, PIN_OUTPUT);

	// Set rows pin to be output
	MDIO_SetPinDirection(PIN3, HKPD_ROW_PORT, PIN_INPUT);
	MDIO_SetPinDirection(PIN4, HKPD_ROW_PORT, PIN_INPUT);
	MDIO_SetPinDirection(PIN5, HKPD_ROW_PORT, PIN_INPUT);
	MDIO_SetPinDirection(PIN6, HKPD_ROW_PORT, PIN_INPUT);

	/*Activate Pull up Resistor */
	MDIO_SetPinValue(PIN3,HKPD_ROW_PORT,PIN_HIGH);
	MDIO_SetPinValue(PIN4,HKPD_ROW_PORT,PIN_HIGH);
	MDIO_SetPinValue(PIN5,HKPD_ROW_PORT,PIN_HIGH);
	MDIO_SetPinValue(PIN6,HKPD_ROW_PORT,PIN_HIGH);

	/*Deactivate Columns */
	MDIO_SetPinValue(PIN0,HKPD_COLUMN_PORT,PIN_HIGH);
	MDIO_SetPinValue(PIN1,HKPD_COLUMN_PORT,PIN_HIGH);
	MDIO_SetPinValue(PIN4,HKPD_COLUMN_PORT,PIN_HIGH);
	MDIO_SetPinValue(PIN5,HKPD_COLUMN_PORT,PIN_HIGH);

}

u8 HKPD_GetPressedButton()
{
	if (Cursor_Postion_LCD==16)
	{
		HCLCD_SetCursorPosition4Bit(HCLCD_LINE1, 0);
	}

	if (Cursor_Postion_LCD==33)
	{
		HCLCD_WriteCommand4Bit(DISPLAY_CLEAR);
		Cursor_Postion_LCD =0;
		HCLCD_SetCursorPosition4Bit(HCLCD_LINE0, 0);
	}
	u8 Loc_u8ColumnCounter=0;
	u8 Loc_u8RowCounter=0;

	u8 Loc_u8ReturnValue=HKPD_NOT_PRESSED;

	u8 Loc_u8PinState=0;

	u8 Loc_u8PinArray [8] = { PIN0,PIN1,PIN4,PIN5,PIN3,PIN4,PIN5,PIN6};

	for (Loc_u8ColumnCounter=HKPD_COL_START;Loc_u8ColumnCounter<HKPD_COL_END;Loc_u8ColumnCounter++)
	{
	//Activate the column
		MDIO_SetPinValue(Loc_u8PinArray[Loc_u8ColumnCounter],HKPD_COLUMN_PORT,PIN_LOW);

		for(Loc_u8RowCounter=HKPD_ROW_START;Loc_u8RowCounter<HKPD_ROW_END;Loc_u8RowCounter++)
		{
			MDIO_ReadPin(Loc_u8PinArray[Loc_u8RowCounter],HKPD_ROW_PORT,&Loc_u8PinState);

			if(Loc_u8PinState==0)
			{
				// Retrieve the Key Value
				Loc_u8ReturnValue=HKPD_SwitchValues[Loc_u8ColumnCounter-HKPD_COL_START][Loc_u8RowCounter-HKPD_ROW_START];
				Cursor_Postion_LCD++;

				while(Loc_u8PinState==0)
				{
					MDIO_ReadPin(Loc_u8PinArray[Loc_u8RowCounter],HKPD_ROW_PORT,&Loc_u8PinState);
				}
				_delay_ms(10);
			}
			else
			{
				//Do Nothing
			}

		}

		//Deactivate Column
		MDIO_SetPinValue(Loc_u8PinArray[Loc_u8ColumnCounter],HKPD_COLUMN_PORT,PIN_HIGH);
	}
	return Loc_u8ReturnValue;
}





