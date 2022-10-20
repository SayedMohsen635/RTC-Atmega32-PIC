/*
 * uart.h
 *
 * Created: 10/19/2022 12:06:21 PM
 *  Author: sayed
 */ 

#ifndef USART_H_
#define USART_H_

#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "../../Utilities/dataTypes.h"
#include "../../Utilities/stdMacros.h"

void UART_vInit(uint32 baud);
void UART_vSendData(char data);
char UART_u8ReceiveData(void);
void UART_vSendstring(char *ptr);
#endif /* USART_H_ */
