/*
 * UART_int.h
 *
 *  Created on: Sep 25, 2022
 *      Author: Abdelrahman
 */

#ifndef UART_UART_INT_H_
#define UART_UART_INT_H_

void M_UART_void_Init(void);
void M_UART_void_sendByte(u8 copy_u8Data);
void M_UART_void_receiveByte(u8 * ptr_data);
void M_UART_void_sendString(u8* str);

#endif /* UART_UART_INT_H_ */
