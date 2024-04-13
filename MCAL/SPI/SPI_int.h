/*
 * SPI_int.h
 *
 *  Created on: Sep 26, 2022
 *      Author: Abdelrahman
 */

#ifndef SPI_SPI_INT_H_
#define SPI_SPI_INT_H_


void M_SPI_void_masterInit(void);
void M_SPI_void_slaveInit(void);
u8 M_SPI_u8_transfereByte(u8 copy_u8data);
#endif /* SPI_SPI_INT_H_ */
