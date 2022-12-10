#ifndef HAL_HCLCD_HCLCD_INTERFACE_H_
#define HAL_HCLCD_HCLCD_INTERFACE_H_
#include "../../MCAL/MDIO/MDIO_Interface.h"


#define RS  1
#define RW  2
#define E   3

#define HCLCD_PIN_START 4

// MACROS FOR USERS
#define HCLCD_LINE0 0
#define HCLCD_LINE1 1

#define CONTROL_PORT MDIO_PORTB
#define DATA_PORT MDIO_PORTA // from 4 - 7

void HCLCD_Init4Bit();

void HCLCD_WriteCommand4Bit(u8 Copy_u8Comman);

void HCLCD_WritChar4Bit(u8 Copy_u8Data);

void HCLCD_SetCursorPosition4Bit(u8 LineNumber , u8 PositionNumber);

void HCLCD_String_Write (u8 *str);

void HCLCD_String_Write_Position (u8 *str , u8 LineNumber , u8 PositionNumber);

#endif /* HAL_HCLCD_HCLCD_INTERFACE_H_ */
