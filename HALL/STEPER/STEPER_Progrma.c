/*
 * STEPER_Progrma.c
 *
 *  Created on: Mar 21, 2024
 *      Author: User
 */

#include "STD_TYPES.h"
#include "STEPER_Iterface.h"
#include "DIO_Interface.h"
#include <util/delay.h>


void STEPPER_voidInit(void)
{
	DIO_u8SetPinDirection(STEPPER_PORT,STEPPER_BLUE_PIN,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(STEPPER_PORT,STEPPER_PINK_PIN,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(STEPPER_PORT,STEPPER_YELLOW_PIN,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(STEPPER_PORT,STEPPER_ORANGE_PIN,DIO_PIN_OUTPUT);

}
void STEPPER_voidRotate(u8 Copy_u8Direction)
{
	switch(Copy_u8Direction)
	{
	case NORTH:
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_BLUE_PIN,DIO_PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PINK_PIN,DIO_PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_YELLOW_PIN,DIO_PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_ORANGE_PIN,DIO_PIN_HIGH);

		break;
	case EASTERN_NORTH:
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_BLUE_PIN,DIO_PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_PINK_PIN,DIO_PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_YELLOW_PIN,DIO_PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_PORT,STEPPER_ORANGE_PIN,DIO_PIN_HIGH);
		break;
	case EAST:
		break;
	case EASTERN_SOUTH:
		break;
	case SOUTH:
		break;
	case WESTERN_SOUTH:
		break;
	case WEST:
		break;
	case WESTERN_NORTH:
		break;

	default:
		break;
	}
}
