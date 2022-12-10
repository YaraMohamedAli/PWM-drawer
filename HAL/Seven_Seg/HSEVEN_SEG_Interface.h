#ifndef HAL_SEVEN_SEG_HSEVEN_SEG_INTERFACE_H_
#define HAL_SEVEN_SEG_HSEVEN_SEG_INTERFACE_H_
#include "../../LIB/STD_Type.h"
#include "../../LIB/BIT_MATH.h"

//define new data type for the seven segment

typedef struct
{
	u8 PinEnPort;
	u8 PinEn;

	u8 PinAPort;
	u8 PinA;

	u8 PinBPort;
	u8 PinB;

	u8 PinCPort;
	u8 PinC;

	u8 PinDPort;
	u8 PinD;

}SevenSeg_t;

#define SEVEN_SEG_ON  1
#define SEVEN_SEG_OFF 0

// Function Prototypes

void HSEVEN_SEG_Init(SevenSeg_t * Ptr_SevenSegObj);

void HSEVEN_SEG_SetMode(SevenSeg_t * Ptr_SevenSegObj, u8 Copy_u8SevenSegMode );

void HSEVEN_SEG_Display(SevenSeg_t * Ptr_SevenSegObj, u8 Copy_u8SevenSegValue);


#endif /* HAL_SEVEN_SEG_HSEVEN_SEG_INTERFACE_H_ */
