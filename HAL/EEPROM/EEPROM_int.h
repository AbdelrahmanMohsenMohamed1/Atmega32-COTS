/*
 * EEPROM_int.h
 *
 *  Created on: Sep 28, 2022
 *      Author: Abdelrahman
 */

#ifndef EEPROM_EEPROM_INT_H_
#define EEPROM_EEPROM_INT_H_

void H_EEPROM_void_Init(void);
u8 H_EEPROM_u8_writeByte(u16  copy_u16add,u8 copy_u8data);
u8 H_EEPROM_u8_readByte(u16  copy_u16add,u8 * ptr_data);
#endif /* EEPROM_EEPROM_INT_H_ */
