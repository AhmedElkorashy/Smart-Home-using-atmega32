/*
 * EEPROM_Interface.h
 *
 *  Created on: Apr 4, 2024
 *      Author: Ibrahim
 */

#ifndef HAL_EEPROM_EEPROM_INTERFACE_H_
#define HAL_EEPROM_EEPROM_INTERFACE_H_


/*********************************************************************************/
/*							FUNCTIONS PROTOTYPES								 */
/*********************************************************************************/
void EEPROM_voidInit(void);
void EEPROM_voidSendDataByte(u8 Copy_u8DataByte , u16 Copy_u16Address);
u8 EEPROM_u8ReadDataByte(u16 Copy_u16Adderss);



#endif /* HAL_EEPROM_EEPROM_INTERFACE_H_ */
