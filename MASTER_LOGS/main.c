
/********************************************************************************/
/*								FILES INCLUSIONS								*/
/********************************************************************************/
/******************LIB*******************/
#include "STD_Types.h"
//#include "BIT_MATH.h"
#include <util/delay.h>

/*****************MCAL*******************/
#include "DIO_Interface.h"
#include "SPI_Interface.h"
/*****************HAL*******************/
//#include "USART_Interface.h"
#include "EEPROM_Interface.h"
#include "LCD_Interface.h"
#include "KPD_Interface.h"

/********************************************************************************/
/***********Global Variables************/
#define MAX_SIZE	5
#define FALSE		1
#define TRUE		0
u8 password[MAX_SIZE];
u8 temp_pass[MAX_SIZE];
u8 counter=0;
u8 spi_send=0;
u8 customChar[] = {
		0x00,
		0x1B,
		0x15,
		0x11,
		0x0A,
		0x0E,
		0x04,
		0x00
};
/********************************************************************************/
/*							 ENTRY POINT <main>								*/
/********************************************************************************/
u8 areArraysEqual(u8 arr1[], u8 arr2[], u8 size) ;
int main(void)
{
	/*Initialize spi master*/
	DIO_u8SetPinDirection(DIO_PORTB, DIO_PIN4, DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTB, DIO_PIN5, DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTB, DIO_PIN6, DIO_PIN_INPUT);
	DIO_u8SetPinDirection(DIO_PORTB, DIO_PIN7, DIO_PIN_OUTPUT);

	DIO_u8SetPinValue(DIO_PORTB, DIO_PIN4,DIO_PIN_LOW);
	DIO_u8SetPinValue(DIO_PORTB, DIO_PIN5,DIO_PIN_LOW);
	DIO_u8SetPinValue(DIO_PORTB, DIO_PIN7,DIO_PIN_LOW);

	SPI_VoidInit();
	LCD_voidInit();
	KPD_Init();
	u8 Key;
	LCD_voidSendString((u8*)"Welcome ");
	EEPROM_voidInit();
	_delay_ms(200);
	u16 read_eeprom=EEPROM_u8ReadDataByte(0);
	_delay_ms(50);
	u8 var;
	u16 first=0;
	u8 cursor=7;
	u8 flag=0;
	u8 number_of=1;
	while(1)
	{
		if(counter<3)
		{
			if(read_eeprom == 0xFF)
			{
				LCD_voidSetPosition(0,0);
				LCD_voidSendString((u8 *)"CREATE PASSWORD");
				LCD_voidSetPosition(1,0);
				LCD_voidSendString((u8*)"PASS :");
				Key=KPD_u8GetPressed();
				if(Key!=NOTPRESSED)
				{
					if(Key!='?')
					{
						LCD_voidSetPosition(1,cursor);
						LCD_voidSendData('*');
						EEPROM_voidSendDataByte(Key,first);
						_delay_ms(20);
						cursor++;
						first++;
					}
					if(Key=='?')
					{
						LCD_voidClearScreen();
						LCD_voidSendString((u8*)"welcome to smart.");
						LCD_voidSetPosition(1,0);
						LCD_voidSendString((u8*)"Pass Saved");
						counter=3;
					}
				}
			}
			else
			{
				LCD_voidSetPosition(0,0);
				LCD_voidSendString((u8 *)"Enter the pass");
				LCD_voidSetPosition(1,0);
				LCD_voidSendString((u8*)"PASS :");
				Key=KPD_u8GetPressed();
				if(Key!=NOTPRESSED)
				{
					if(Key!='?')
					{
						var=EEPROM_u8ReadDataByte(first);
						_delay_ms(20);
						temp_pass[first]=var;
						password[first]=Key;
						first++;
						number_of++;
					}
					if(Key=='?')
					{
						first=0;
						if(areArraysEqual(temp_pass,password,5)==0 && number_of==5)
						{
							counter=4;
						}
						if(areArraysEqual(temp_pass,password,5)==1 ||number_of!=5)
						{
							counter++;
							LCD_voidClearScreen();
							LCD_voidSendString((u8*)"wrong pass");
							cursor=5;
							number_of=1;
							_delay_ms(50);
							if(counter==3)
							{
								flag=1;
								spi_send=1;
							}
						}
					}
					LCD_voidSetPosition(1,cursor);
					LCD_voidSendData('*');
					cursor++;
					if(counter==4)
					{
						u8 sender=3;
						LCD_voidClearScreen();
						LCD_voidSendString((u8*)"welcome Home ");
						LCD_voidSendCustomCharacter(customChar,0,0,12);
						LCD_voidSetPosition(1,0);
						LCD_voidSendString((u8*)"Door opened");
						SPI_u8Tranceive(sender,&spi_send);
					}
					if(flag)
					{
						LCD_voidClearScreen();
						LCD_voidSendString((u8*)"wrong pass");
						SPI_u8Tranceive(spi_send,&spi_send);
						LCD_voidSetPosition(1,0);
						LCD_voidSendString((u8 *)"Game over");
					}
				}
			}
		}
	}
}

u8 areArraysEqual(u8 arr1[], u8 arr2[], u8 size) {
	for (u8 i = 0; i < size; i++) {
		if (arr1[i] != arr2[i]) {
			return FALSE;
		}
	}
	return TRUE;
}
