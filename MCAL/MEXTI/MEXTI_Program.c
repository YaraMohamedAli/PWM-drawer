#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Type.h"
#include "../../MCAL/MDIO/MDIO_Interface.h"
#include "MEXTI_Config.h"
//#include <util/delay.h>

/*Global Pointer to function to not violate the layered arch*/


void (*Global_Pointer)(void)=NULL;

void MEXTI_Callback(void(*Loc_PtrToFunc)(void))
{
	if (Loc_PtrToFunc!=NULL)
	{
		Global_Pointer=Loc_PtrToFunc;
	}
}

// ISR for INT0 ==> 1-1 = 0 from table
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	if (Global_Pointer!=NULL)
	{
		Global_Pointer();
	}
}


/*
 * 1- Set Sense Control
 * 2- Enable PIE
 */
void MEXTI0_Init()
{
	// Selective macros defines Prebuild configuration , conditional compilation
#if MEXTI_SENSE_CONTROL_STATE == MEXTI_LOW_LEVEL
	CLR_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);
#elif EXTI_SENSE_CONTROL_STATE == MEXTI_ANY_LOGICAL_CHANGE
	SET_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);
#elif EXTI_SENSE_CONTROL_STATE == MEXTI_RISING_EDGE
	CLR_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);
#elif EXTI_SENSE_CONTROL_STATE == MEXTI_FALLING_EDGE
	SET_BIT(MCUCR,1);
	SET_BIT(MCUCR,1);
#endif

	/*Enable Interrupt On INT0 ==> PIE of interrupt Zero */
	SET_BIT(GICR,6);
}
void MEXTI1_Init()
{
	// Selective macros defines Prebuild configuration , conditional compilation
#if MEXTI_SENSE_CONTROL_STATE == MEXTI_LOW_LEVEL
	CLR_BIT(MCUCR,2);
	CLR_BIT(MCUCR,3);
#elif EXTI_SENSE_CONTROL_STATE == MEXTI_ANY_LOGICAL_CHANGE
	SET_BIT(MCUCR,2);
	CLR_BIT(MCUCR,3);
#elif EXTI_SENSE_CONTROL_STATE == MEXTI_RISING_EDGE
	CLR_BIT(MCUCR,2);
	SET_BIT(MCUCR,3);
#elif EXTI_SENSE_CONTROL_STATE == MEXTI_FALLING_EDGE
	SET_BIT(MCUCR,2);
	SET_BIT(MCUCR,3);
#endif

}
void MEXTI2_Init()
{


}

void MEXTI_SetSenseControl(u8 Copy_u8Interrupt_ID, u8 Copy_u8mode)
{

}
