/*
 * RTC.h
 *
 * Created: 10/15/2022 11:25:24 PM
 *  Author: sayed
 */ 


#ifndef RTC_H_
#define RTC_H_
#define F_CPU 1000000UL
#include <util/delay.h>
#include "../../MCAL/I2C Driver/I2C.h"
#include "../../MCAL/UART Driver/uart.h"

void RTCInit(void);
void RTCSetTime(uint8_t hour , uint8_t minute , uint8_t second);
void RTCGetTime(uint8_t *hour , uint8_t *minute , uint8_t *second);
void sendPackedBCD(uint8_t data);

#endif /* RTC_H_ */