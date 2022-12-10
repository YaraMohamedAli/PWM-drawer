#ifndef MCAL_MADC_MADC_PRIVATE_H_
#define MCAL_MADC_MADC_PRIVATE_H_

/*Registers*/
#define ADMUX       *((volatile u8*)0x27)
#define ADCSRA      *((volatile u8*)0x26)
#define ADC         *((volatile u16*)0x24)
#define SFIOR       *((volatile u8*)0x50)

/*Options for Vref.*/
#define  VREF_AREF_PIN  0
#define  VREF_AVCC_PIN  1
#define  VREF_2_56v_INTERNAL 3

/*Options for prescaler*/
#define PRESCALER_DIVIDER_BY_2      1
#define PRESCALER_DIVIDER_BY_4		2
#define PRESCALER_DIVIDER_BY_8		3
#define PRESCALER_DIVIDER_BY_16		4
#define PRESCALER_DIVIDER_BY_32		5
#define PRESCALER_DIVIDER_BY_64		6
#define PRESCALER_DIVIDER_BY_128	7

/*Options for left/right adjust*/
#define MADC_RIGHT_ADJUST 	0
#define MADC_LEFT_ADJUST	1

/*Musking for the signal and Reg*/
#define MADC_CHANNEL_INPUT_MUSK  0x1f // 0b00011111
#define MADC_ADMUX_REG_MUSK      0xE0 // 0b11100000



#endif /* MCAL_MADC_MADC_PRIVATE_H_ */
