/*
 * TIMERS_Private.h
 *
 *  Created on: Mar 27, 2024
 *      Author: Ibrahim
 */

#ifndef MCAL_TIMERS_TIMERS_PRIVATE_H_
#define MCAL_TIMERS_TIMERS_PRIVATE_H_

/************************REGISTERS*********************************/
#define SREG            *((volatile u8 *)0x5F)
	#define TIMSK			*((volatile u8*)0X59)
	#define TIFR			*((volatile u8*)0X58)

	/*Timer0*/
	#define TCCR0			*((volatile u8*)0X53)
	#define TCNT0			*((volatile u8*)0X52)
	#define OCR0			*((volatile u8*)0X5C)

	/*Timer1*/
	#define TCCR1A			*((volatile u8*)0X4F)
	#define TCCR1B			*((volatile u8*)0X4E)
	#define TCNT1H          *((volatile u8 *)(0x4D))
	#define TCNT1L          *((volatile u8 *)(0x4C))
	#define TCNT1			*((volatile u16*)0X4C)    /* u16 for HIGH & LOW */
	#define OCR1AL          *((volatile u8 *)(0x4A))
	#define OCR1AH          *((volatile u8 *)(0x4B))
	#define OCR1A			*((volatile u16*)0X4A)
	#define OCR1BL          *((volatile u8 *)(0x48))
	#define OCR1BH          *((volatile u8 *)(0x49))
	#define OCR1B			*((volatile u16*)0X48)
	#define ICR1H           *((volatile u8 *)(0x47))
	#define ICR1L           *((volatile u8 *)(0x46))
	#define ICR1			*((volatile u16*)0X46)

	/*Timer2*/

	#define TCCR2			*((volatile u8*)0X45)
	#define TCNT2			*((volatile u8*)0X44)
	#define TCNT2			*((volatile u8*)0X44)
	#define OCR2			*((volatile u8*)0X43)

	#define WDTCR        *((volatile u8 *)(0x41))

/**********************REGISTERS BITS*****************************/
#define TIMSK_TOIE0		0
	#define TIMSK_OCIE0		1
	#define TIMSK_TOIE1		2
	#define TIMSK_OCIE1B	3
	#define TIMSK_OCIE1A	4
	#define TIMSK_TICIE1	5
	#define TIMSK_TOIE2		6
	#define TIMSK_OCIE2		7

	#define TIFR_TOV0		0
	#define TIFR_OCF0		1
	#define TIFR_TOV1		2
	#define TIFR_OCF1B		3
	#define TIFR_OCF1A		4
	#define TIFR_ICF1		5
	#define TIFR_TOV2		6
	#define TIFR_OCV2		7

	/*Timer0*/
	#define TCCR0_FOC0      7
	#define TCCR0_WGM00		6
	#define TCCR0_COM01		5
	#define TCCR0_COM00		4
	#define TCCR0_WGM01		3
	#define TCCR0_CS02      2
	#define TCCR0_CS01		1
	#define TCCR0_CS00		0


	/*Timer1*/

	#define TCCR1A_COM1A1		7
	#define TCCR1A_COM1A0		6
	#define TCCR1A_COM1B1		5
	#define TCCR1A_COM1B0		4
	#define TCCR1A_WGM11		1
	#define TCCR1A_WGM10		0

	#define TCCR1B_ICNC1		7
	#define TCCR1B_ICES1		6
	#define TCCR1B_WGM13		4
	#define TCCR1B_WGM12		3


	/*Timer2*/

	#define TCCR2_WGM20		6
	#define TCCR2_COM21		5
	#define TCCR2_COM20		4
	#define TCCR2_WGM21		3


/***************************************************************************************/
	#define DISABLE						                    0
	#define ENABLE						                    1

	#define FALLING_EDGE				                    0
	#define RISING_EDGE					                    1

	#define TIMER_NO_CLOCK_SOURCE	 	                    0
	#define TIMER_NO_PRESCALER_FACTOR 	                    1
	#define TIMER_DIVISION_FACTOR_8	 	                    2
	#define TIMER_DIVISION_FACTOR_64	                    3
	#define TIMER_DIVISION_FACTOR_256	                    4
	#define TIMER_DIVISION_FACTOR_1024	                    5
	#define TIMER_T0_EXTERNAL_CLOCK_SOURCE_FALLING	        6
	#define TIMER_T0_EXTERNAL_CLOCK_SOURCE_RISING	        7

	#define TIMER_PRESCALER_MASK					        0b11111000 /* This Value also could use for bit masking */

	#define TIMER_NORMAL_MODE						        1
	#define TIMER_PWM_MODE							        2
	#define TIMER_CTC_MODE							        3
	#define TIMER_FAST_PWM_MODE						        4

	#define TIMER_OC_DISCONNECTED					        0
	#define TIMER_OC_TOGGEL							        1
	#define TIMER_OC_LOW							        2
	#define TIMER_OC_HIGH							        3

	#define TIMER_OC_DISCONNECTED					        0
	#define TIMER_CLR_ON_CTC_SET_ON_TOP				        2
	#define TIMER_SET_ON_CTC_CLR_ON_TOP				        3

	#define TIMER1_NORMAL_MODE								0
	#define TIMER1_PWM_8_BIT_MODE							1
	#define TIMER1_PWM_9_BIT_MODE							2
	#define TIMER1_PWM_10_BIT_MODE							3
	#define TIMER1_CTC_OCR1A_MODE							4
	#define TIMER1_FAST_PWM_8_BIT_MODE						5
	#define TIMER1_FAST_PWM_9_BIT_MODE 						6
	#define TIMER1_FAST_PWM_10_BIT_MODE						7
	#define TIMER1_PWM_PHASE_AND_FREQ_CORRECT_ICR1_MODE		8
	#define TIMER1_PWM_PHASE_AND_FREQ_CORRECT_OCR1A_MODE	9
	#define TIMER1_PWM_PHASE_CORRECT_ICR1_MODE				10
	#define TIMER1_PWM_PHASE_CORRECT_OCR1A_MODE				11
	#define TIMER1_CTC_ICR1_MODE							12
	#define TIMER1_FAST_PWM_ICR1_MODE						14
	#define TIMER1_FAST_PWM_OCR1A_MODE						15


	#define TIMER_u8_ICP_FALLING_EDGE                   0
	#define TIMER_u8_ICP_RAISING_EDGE                   1


	/* WDTCR Bits */
	#define		WDTCR_WDTOE 			4
	#define		WDTCR_WDE				3
	#define		WDTCR_WDP2				2
	#define		WDTCR_WDP1				1
	#define		WDTCR_WDP0				0

	/* WDT Prescaler select  */
	#define		WDT_PS_MASKING				0b11111000
	#define		WDT_PS_16_3_MS				0
	#define		WDT_PS_32_5_MS	    		1
	#define		WDT_PS_65_MS	    		2
	#define		WDT_PS_0_13_S				3
	#define		WDT_PS_0_26_S				4
	#define		WDT_PS_0_52_S				5
	#define		WDT_PS_1_0_S				6
	#define		WDT_PS_2_1_S				7


#endif /* MCAL_TIMERS_TIMERS_PRIVATE_H_ */
