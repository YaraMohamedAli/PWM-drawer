#ifndef MDIO_MDIO_INTERFACE_H_
#define MDIO_MDIO_INTERFACE_H_
#include "../../LIB/STD_Type.h"
#include "../../LIB/BIT_MATH.h"
/* Putting descriptive names for different objects*/

#define MDIO_PORTA 0
#define MDIO_PORTB 1
#define MDIO_PORTC 2
#define MDIO_PORTD 3

#define PORT_OUTPUT 255
#define PORT_INPUT 0

#define PORT_HIGH 255
#define PORT_LOW  0

#define PIN_OUTPUT 1
#define PIN_INPUT 0

#define PIN_HIGH 1
#define PIN_LOW 0

#define NULL 0

typedef enum
{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
}Pin_t;

/*Function Prototypes */

void MDIO_SetPortDirection(u8 Copy_u8PortNo , u8 Copy_u8PortDir );
void MDIO_SetPinDirection(u8 Copy_u8PinNo , u8 Copy_u8PortNo , u8 Copy_u8PortDir );
void MDIO_SetPortValue(u8 Copy_u8PortNo,u8 Copy_u8PortValue);
void MDIO_SetPinValue(u8 Copy_u8PinNo , u8 Copy_u8PortNo , u8 Copy_u8Pinvalue);
void MDIO_ReadPort(u8 Copy_u8PortNo, u8* P_u8PortReading);
void MDIO_ReadPin(u8 Copy_u8PinNo, u8 Copy_u8PortNo, u8* P_u8PortReading);
void MDIO_SetNibbleValue(u8 Copy_u8PinStart, u8 Copy_u8PortNumber, u8 Copy_u8Value);

#endif /* MDIO_MDIO_INTERFACE_H_ */
