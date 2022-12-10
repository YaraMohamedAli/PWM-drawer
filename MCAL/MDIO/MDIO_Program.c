#include "../../LIB/STD_Type.h"
#include "../../LIB/BIT_MATH.h"
#include "MDIO_Interface.h"
#include "MDIO_Private.h"

void MDIO_SetPortDirection(u8 Copy_u8PortNo , u8 Copy_u8PortDir )
{
	if ((Copy_u8PortDir==PORT_OUTPUT) || (Copy_u8PortDir == PORT_INPUT))
	{ /*Valid port direction given*/
		switch (Copy_u8PortNo)
		{
		case MDIO_PORTA:
			DDRA = Copy_u8PortDir;
			break;
		case MDIO_PORTB:
			DDRB = Copy_u8PortDir;
			break;
		case MDIO_PORTC:
			DDRC = Copy_u8PortDir;
			break;
		case MDIO_PORTD:
			DDRD = Copy_u8PortDir;
			break;
		default :
			/*wrong port number passed*/
			break;
		}
	}
	else
	{
		/*Valid port direction given*/
	}
}
void MDIO_SetPinDirection(u8 Copy_u8PinNo , u8 Copy_u8PortNo , u8 Copy_u8PinDir )
{
	if((Copy_u8PinNo>=0)&&(Copy_u8PinNo<8))
	{
		switch (Copy_u8PortNo)
		{
		case MDIO_PORTA:
			if (Copy_u8PinDir==PIN_OUTPUT)
			{
				SET_BIT(DDRA,Copy_u8PinNo);
			}
			else if (Copy_u8PinDir==PIN_INPUT)
			{
				CLR_BIT(DDRA,Copy_u8PinNo);
			}
			else
			{
				/*wrong pin direction*/
			}
			break;
		case MDIO_PORTB:
			if (Copy_u8PinDir==PIN_OUTPUT)
			{
				SET_BIT(DDRB,Copy_u8PinNo);
			}
			else if (Copy_u8PinDir==PIN_INPUT)
			{
				CLR_BIT(DDRB,Copy_u8PinNo);
			}
			else
			{
				/*wrong pin direction*/
			}
			break;
		case MDIO_PORTC:
			if (Copy_u8PinDir==PIN_OUTPUT)
			{
				SET_BIT(DDRC,Copy_u8PinNo);
			}
			else if (Copy_u8PinDir==PIN_INPUT)
			{
				CLR_BIT(DDRC,Copy_u8PinNo);
			}
			else
			{
				/*wrong pin direction*/
			}
			break;
		case MDIO_PORTD:
			if (Copy_u8PinDir==PIN_OUTPUT)
			{
				SET_BIT(DDRD,Copy_u8PinNo);
			}
			else if (Copy_u8PinDir==PIN_INPUT)
			{
				CLR_BIT(DDRD,Copy_u8PinNo);
			}
			else
			{
				/*wrong pin direction*/
			}
			break;
		default :
			/*wrong port chosen*/
			break;
		}
	}
	else
	{
		/*Wrong Pin number*/
	}

}
void MDIO_SetPortValue(u8 Copy_u8PortNo,u8 Copy_u8PortValue)
{
	if((Copy_u8PortValue==PORT_HIGH)||(Copy_u8PortValue==PORT_LOW))
	{
		switch (Copy_u8PortNo)
		{
		/*Valid port direction given */
		case MDIO_PORTA:
			PORTA = Copy_u8PortValue;
			break;
		case MDIO_PORTB:
			PORTB = Copy_u8PortValue;
			break;
		case MDIO_PORTC:
			PORTC = Copy_u8PortValue;
			break;
		case MDIO_PORTD:
			PORTC = Copy_u8PortValue;
			break;
		default :
			/*wrong port number passed*/
			break;
		}
	}
	else
	{
		/*Invalid port value given*/
	}
}
void MDIO_SetPinValue(u8 Copy_u8PinNo , u8 Copy_u8PortNo , u8 Copy_u8Pinvalue)
{

	if((Copy_u8PinNo>=0)&&(Copy_u8PinNo<8))
	{
		switch (Copy_u8PortNo)
		{
		case MDIO_PORTA:
			if (Copy_u8Pinvalue==PIN_HIGH)
			{
				SET_BIT(PORTA,Copy_u8PinNo);
			}
			else if (Copy_u8Pinvalue==PIN_LOW)
			{
				CLR_BIT(PORTA,Copy_u8PinNo);
			}
			else
			{
				/*wrong pin VALUE*/
			}
			break;
		case MDIO_PORTB:
			if (Copy_u8Pinvalue==PIN_HIGH)
			{
				SET_BIT(PORTB,Copy_u8PinNo);
			}
			else if (Copy_u8Pinvalue==PIN_LOW)
			{
				CLR_BIT(PORTB,Copy_u8PinNo);
			}
			else
			{
				/*wrong pin VALUE*/
			}
			break;
		case MDIO_PORTC:
			if (Copy_u8Pinvalue==PIN_HIGH)
			{
				SET_BIT(PORTC,Copy_u8PinNo);
			}
			else if (Copy_u8Pinvalue==PIN_LOW)
			{
				CLR_BIT(PORTC,Copy_u8PinNo);
			}
			else
			{
				/*wrong pin VALUE*/
			}
			break;
		case MDIO_PORTD:
			if (Copy_u8Pinvalue==PIN_HIGH)
			{
				SET_BIT(PORTD,Copy_u8PinNo);
			}
			else if (Copy_u8Pinvalue==PIN_LOW)
			{
				CLR_BIT(PORTD,Copy_u8PinNo);
			}
			else
			{
				/*wrong pin VALUE*/
			}
			break;
		default :
			/*wrong port chosen*/
			break;
		}
	}
	else
	{
		/*Wrong Pin number*/
	}

}
void MDIO_ReadPort(u8 Copy_u8PortNo, u8* P_u8PortReading)
{
	if (P_u8PortReading!=NULL)
	{
		switch(Copy_u8PortNo)
		{
		case MDIO_PORTA:
			*P_u8PortReading = PINA;
			break;
		case MDIO_PORTB:
			*P_u8PortReading = PINB;
			break;
		case MDIO_PORTC:
			*P_u8PortReading = PINC;
			break;
		case MDIO_PORTD:
			*P_u8PortReading = PIND;
			break;
		default:
			/*invalid port reading*/
			break;
		}
	}
	else
	{
		/*NULL pointer*/
	}
}
void MDIO_ReadPin(u8 Copy_u8PinNo, u8 Copy_u8PortNo, u8* P_u8PortReading)
{
	if((Copy_u8PinNo>=0)&&(Copy_u8PinNo<8))
	{
		switch (Copy_u8PortNo)
		{
		case MDIO_PORTA:
			* P_u8PortReading = GET_BIT(PINA,Copy_u8PinNo);
			break;
		case MDIO_PORTB:
			* P_u8PortReading = GET_BIT(PINB,Copy_u8PinNo);
			break;
		case MDIO_PORTC:
			* P_u8PortReading = GET_BIT(PINC,Copy_u8PinNo);
			break;
		case MDIO_PORTD:
			* P_u8PortReading = GET_BIT(PIND,Copy_u8PinNo);
			break;
		default :
			/*wrong PORT chosen*/
			break;
		}
	}
	else
	{
		/*Wrong Pin number*/
	}

}
void MDIO_TogglePin(u8 Copy_u8PinNo, u8 Copy_u8PortNo)
{
	if((Copy_u8PinNo>=0)&&(Copy_u8PinNo<8))
	{
		switch (Copy_u8PortNo)
		{
		case MDIO_PORTA:
			TOGGLE_BIT(PORTA,Copy_u8PinNo);
			break;
		case MDIO_PORTB:
			TOGGLE_BIT(PORTB,Copy_u8PinNo);
			break;
		case MDIO_PORTC:
			TOGGLE_BIT(PORTC,Copy_u8PinNo);
			break;
		case MDIO_PORTD:
			TOGGLE_BIT(PORTD,Copy_u8PinNo);
			break;
		default :
			/*wrong PORT chosen*/
			break;
		}
	}
	else
	{
		/*Wrong Pin number*/
	}
}
void MDIO_SetNibbleValue(u8 Copy_u8PinStart, u8 Copy_u8PortNumber, u8 Copy_u8Value)
{
	u8 Loc_u8Value = 0;
	Loc_u8Value = Copy_u8Value;

	// Handling of the Value
	Loc_u8Value = ((Loc_u8Value & (0x0F)) << Copy_u8PinStart);

	if((Copy_u8PinStart<=4) && (Copy_u8PinStart>=0))
	{
		switch (Copy_u8PortNumber)
		{
		case MDIO_PORTA :
			// Mask Port A
			PORTA &= (~((0X0F)<<Copy_u8PinStart));
			PORTA |= Loc_u8Value ;
			break;
		case MDIO_PORTB :
			// Mask Port B
			PORTB &= (~((0X0F)<<Copy_u8PinStart));
			PORTB |= Loc_u8Value ;
			break;
		case MDIO_PORTC :
			// Mask Port C
			PORTC &= (~((0X0F)<<Copy_u8PinStart));
			PORTC |= Loc_u8Value ;
			break;
		case MDIO_PORTD :
			// Mask Port D
			PORTD &= (~((0X0F)<<Copy_u8PinStart));
			PORTD |= Loc_u8Value ;
			break;
		default:
			//Wrong port
			break;
		}
	}
	else
	{
		//wrong pin start
	}
}
