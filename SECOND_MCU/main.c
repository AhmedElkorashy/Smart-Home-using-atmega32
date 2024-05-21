
/********************************************************************************/
/*								FILES INCLUSIONS								*/
/********************************************************************************/
/******************LIB*******************/
#include "STD_Types.h"
#include "BIT_MATH.h"
#include <util/delay.h>
/*****************MCAL*******************/
#include "GIE_Interface.h"
#include "ADC_Interface.h"
#include "DIO_Interface.h"
#include "TIMERS_Interface.h"
#include "USART_Interface.h"
#include "EXTI_Interface.h"
#include "SPI_Interface.h"
/*****************HAL*******************/
#include "LCD_Interface.h"
#include "FAN_Interface.h"
/********************************************************************************/
/***********Global Variables************/

/*************GLOBAL MACROS*************/
u8 EXTI_FLAG_ROOM_1=0;
u8 EXTI_FLAG_ROOM_2=0;
u8 ROOM_1FLAG=1;
u8 ROOM_2FLAG=1;

/**************Handlers*****************/
void ROOM_1()
{
	EXTI_FLAG_ROOM_1=1;
	ROOM_1FLAG=0;

}
void ROOM_2()
{
	EXTI_FLAG_ROOM_2=2;
	ROOM_2FLAG=0;
}

/********************************************************************************/
/*								ENTRY POINT <main>								*/
/********************************************************************************/

u8 Global_Value=0;
u8 speed=0;
/***************Handlers****************/
int main(void)
{
	DIO_u8SetPinDirection(DIO_PORTD,DIO_PIN5,DIO_PIN_OUTPUT);
	GIE_voidEnable();
	TIMER1_voidInit();
	LCD_voidInit();
	/*door*/
	Timer_voidSetICR(20000);
	/**fan**/
	TIMER0_voidInit();
	TIMER2_voidInit();
	FAN_1_voidInit();
	FAN_2_voidInit();
	//-------------------------------------------------------
	/**slave**/
	DIO_u8SetPinDirection(DIO_PORTB, DIO_PIN4, DIO_PIN_INPUT);
	DIO_u8SetPinDirection(DIO_PORTB, DIO_PIN5, DIO_PIN_INPUT);
	DIO_u8SetPinDirection(DIO_PORTB, DIO_PIN6, DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTB, DIO_PIN7, DIO_PIN_INPUT);
	SPI_VoidInit();
	EXTI_voidInit();
	/*Initialize USART*/
	USART_voidInit();
	/*LEDS*/
	DIO_u8SetPinDirection(DIO_PORTD,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTB,DIO_PIN0,DIO_PIN_OUTPUT);
	/*EXTI CALL BACK*/
	u8 Local_u8TempValue=0;
	EXTI_u8Int2SetCallBack(ROOM_2);
	EXTI_u8Int1SetCallBack(ROOM_1);
	while(1)
	{
		SPI_u8Tranceive(NULL,&Global_Value);
		if(Global_Value==1)
		{
			for(int i=0;i<20;i++)
			{
				DIO_u8SetPinValue(DIO_PORTD,DIO_PIN2,DIO_PIN_HIGH);
				DIO_u8SetPinValue(DIO_PORTB,DIO_PIN0,DIO_PIN_HIGH);
				_delay_ms(100);
				DIO_u8SetPinValue(DIO_PORTD,DIO_PIN2,DIO_PIN_LOW);
				DIO_u8SetPinValue(DIO_PORTB,DIO_PIN0,DIO_PIN_LOW);
				_delay_ms(100);
			}
			Global_Value=2;
		}
		else if(Global_Value==3)
		{
			Timer_voidSet_CHANNELACOMPMATCH(2500);
			/*************************rooom 1**********************************/
			if(EXTI_FLAG_ROOM_1==1 && ROOM_1FLAG==0)
			{

				USART_u8SendData(EXTI_FLAG_ROOM_1);
				LCD_voidClearScreen();
				LCD_voidSendString((u8*)"Welcome to Room1");
				LCD_voidSetPosition(1,0);
				LCD_voidSendString((u8*)"Temperature: ");

				USART_u8RecevieData(&Local_u8TempValue);
				if(Local_u8TempValue<10)
				{
					FAN_1_voidRotate(0);
					LCD_voidSetPosition(1,12);
					LCD_voidSendString((u8*)" ");
					LCD_voidSendNumber(Local_u8TempValue);
					_delay_ms(500);
					LCD_voidClearScreen();
					LCD_voidSendString((u8*)"No Speed!");
				}
				else if(Local_u8TempValue>=10 && Local_u8TempValue<=20)
				{
					FAN_1_voidRotate(64);
					LCD_voidSetPosition(1,12);
					LCD_voidSendNumber(Local_u8TempValue);
					_delay_ms(500);
					LCD_voidClearScreen();
					LCD_voidSendString((u8*)"Low Speed!");

				}
				else if(Local_u8TempValue>20 &&Local_u8TempValue<30)
				{
					FAN_1_voidRotate(128);
					LCD_voidSetPosition(1,12);
					LCD_voidSendNumber(Local_u8TempValue);
					_delay_ms(500);
					LCD_voidClearScreen();

					LCD_voidSendString((u8*)"Medium Speed!");
				}
				else if(Local_u8TempValue>=30)
				{
					FAN_1_voidRotate(255);
					LCD_voidSetPosition(1,12);
					LCD_voidSendNumber(Local_u8TempValue);
					_delay_ms(500);

					LCD_voidClearScreen();

					LCD_voidSendString((u8*)"High Speed!");
				}
				ROOM_1FLAG=1;
				EXTI_FLAG_ROOM_1=0;
			}
			/*************************rooom 2**********************************/
			if(EXTI_FLAG_ROOM_2==2 && ROOM_2FLAG==0)
			{
				USART_u8SendData(EXTI_FLAG_ROOM_2);
				LCD_voidClearScreen();
				LCD_voidSendString((u8*)"Welcome to Room2");
				LCD_voidSetPosition(1,0);
				LCD_voidSendString((u8*)"Temperature: ");
				//_delay_ms(100);
				USART_u8RecevieData(&Local_u8TempValue);
				if(Local_u8TempValue<10)
				{
					FAN_2_voidRotate(0);
					LCD_voidSetPosition(1,12);
					LCD_voidSendString((u8*)" ");
					LCD_voidSendNumber(Local_u8TempValue);
					_delay_ms(500);

					LCD_voidClearScreen();
					LCD_voidSendString((u8*)"No Speed!");
				}
				else if(Local_u8TempValue>=10 && Local_u8TempValue<=20)
				{
					FAN_2_voidRotate(64);
					LCD_voidSetPosition(1,12);
					LCD_voidSendNumber(Local_u8TempValue);
					_delay_ms(500);

					LCD_voidClearScreen();
					LCD_voidSendString((u8*)"Low Speed!");
				}
				else if(Local_u8TempValue>20 &&Local_u8TempValue<30)
				{
					FAN_2_voidRotate(128);
					LCD_voidSetPosition(1,12);
					LCD_voidSendNumber(Local_u8TempValue);
					_delay_ms(500);

					LCD_voidClearScreen();
					LCD_voidSendString((u8*)"Medium Speed!");
				}
				else if(Local_u8TempValue>=30)
				{
					FAN_2_voidRotate(255);
					LCD_voidSetPosition(1,12);
					LCD_voidSendNumber(Local_u8TempValue);
					_delay_ms(500);

					LCD_voidClearScreen();
					LCD_voidSendString((u8*)"High Speed!");
				}
				ROOM_2FLAG=1;
				EXTI_FLAG_ROOM_2=0;
			}

		}
	}
	return 0;
}

