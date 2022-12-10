#include "../../LIB/STD_Type.h"
#include "../../LIB/BIT_MATH.h"
#include "MADC_Private.h"
#include "MADC_Config.h"

/*Init:
 * 1-Select Vreference
 * 2- Set prescaler
 * 3- Select left/righ adjust
 * 4- enable ADC
 * Start Converstion:
 * 1- set Channel
 * 2- Start Converstion
 * 3- Poll on ADIF
 * 4- Return ADC value
 * */

void MADC_Init(void)
{
	//Set Vreference
#if MADC_SET_VREF == VREF_AREF_PIN
	CLR_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);
#elif MADC_SET_VREF == VREF_AVCC_PIN
	SET_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);
#elif MADC_SET_VREF == VREF_2_56v_INTERNAL
	SET_BIT(ADMUX,6);
	SET_BIT(ADMUX,7);
#else
#error "wrong V referance chosen"
#endif

	//Set Rescaler

#if MADC_SET_RESCALER == PRESCALER_DIVIDER_BY_2
	SET_BIT(ADCSRA,0);
	CLR_BIT(ADCSRA,1);
	CLR_BIT(ADCSRA,2);
#elif MADC_SET_RESCALER == PRESCALER_DIVIDER_BY_4
	CLR_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	CLR_BIT(ADCSRA,2);
#elif MADC_SET_RESCALER == PRESCALER_DIVIDER_BY_8
	SET_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	CLR_BIT(ADCSRA,2);
#elif MADC_SET_RESCALER == PRESCALER_DIVIDER_BY_16
	CLR_BIT(ADCSRA,0);
	CLR_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
#elif MADC_SET_RESCALER == PRESCALER_DIVIDER_BY_32
	SET_BIT(ADCSRA,0);
	CLR_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
#elif MADC_SET_RESCALER == PRESCALER_DIVIDER_BY_64
	CLR_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
#elif MADC_SET_RESCALER == PRESCALER_DIVIDER_BY_128
	SET_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
#else
#error "wrong prescaler chosen"
#endif
	// Left/right adjust
#if MDCA_SET_ADJUST_LEVEL == MADC_RIGHT_ADJUST
	CLR_BIT(ADMUX,5);
#elif MDCA_SET_ADJUST_LEVEL == MADC_LEFT_ADJUST
	SET_BIT(ADMUS,5);
#endif

}

u16 MADC_StartConversion(u8 Copy_u8ADC_Channel)
{
	// Set Channel
	u8 Loc_u8ADC_Channel = Copy_u8ADC_Channel & MADC_CHANNEL_INPUT_MUSK ;
	ADMUX &= MADC_ADMUX_REG_MUSK ;
	ADMUX |= Loc_u8ADC_Channel ;
	// Start Conversion
	SET_BIT(ADCSRA,6);
	//Poll on the flag
	while (GET_BIT(ADCSRA,4)==0)
	{
		//Convesrion processing
	}
	// Conversion finished
	return ADC;
}
