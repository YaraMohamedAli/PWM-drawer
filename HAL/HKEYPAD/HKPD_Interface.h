#ifndef HAL_HKEYPAD_HKPD_INTERFACE_H_
#define HAL_HKEYPAD_HKPD_INTERFACE_H_
#include "../../MCAL/MDIO/MDIO_Interface.h"
#include"../../LIB/BIT_MATH.h"
#include"../../LIB/STD_Type.h"



#define HKPD_COLUMN_PORT   MDIO_PORTD
#define HKPD_ROW_PORT      MDIO_PORTC

#define HKPD_NOT_PRESSED 255 // 'law 3ayza ash8lha adelha 0'

#define HKPD_COL_START   0
#define HKPD_COL_END 4    /*Add one to the real pin Number*/

#define HKPD_ROW_START  4
#define HKPD_ROW_END 8 /*Add one to the real pin number */


typedef enum
{
	HKPD_COLUMN_0_PIN,
	HKPD_COLUMN_1_PIN,
	HKPD_COLUMN_2_PIN,
	HKPD_COLUMN_3_PIN,

	HKPD_ROW_0_PIN,
	HKPD_ROW_1_PIN,
	HKPD_ROW_2_PIN,
	HKPD_ROW_3_PIN
}Key_pad;


void HKPD_Init();

u8 HKPD_GetPressedButton();



#endif /* HAL_HKEYPAD_HKPD_INTERFACE_H_ */
