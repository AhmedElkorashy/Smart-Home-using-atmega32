/*
 * main.c
 *
 *  Created on: Apr 6, 2024
 *      Author: User
 */
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "ADC_Interface.h"
#include "LM35_Interface.h"
#include "SPI_Interface.h"
#include <util/delay.h>
#include "USART_Interface.h"
int main()
{
	LM35_voidInit();
	USART_voidInit();
	u8 Local_u8TempValue;
	u8 USART_RECIVER=0;
	SPI_VoidInit();
	while(1)
	{
		USART_u8RecevieData(&USART_RECIVER);
		if(USART_RECIVER==1)
		{
			Local_u8TempValue =LM35_u16GetTempReading(CHANNEL0);
			USART_u8SendData(Local_u8TempValue);
		}
		else if(USART_RECIVER==2)
		{
			Local_u8TempValue =LM35_u16GetTempReading(CHANNEL1);
			USART_u8SendData(Local_u8TempValue);
		}
		USART_RECIVER=0;
	}
	return 0;
}
