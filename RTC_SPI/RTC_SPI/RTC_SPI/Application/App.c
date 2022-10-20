/*
 * App.c
 *
 * Created: 10/15/2022 11:24:26 PM
 *  Author: sayed
 */ 

#include "App.h"
uint8_t arr[3];
uint8_t result[6];

void appInit(void){
	LCD_vInit();
	LCD_vSendCmd(0x0C);		// To hide cursor
	LCD_vSendString("Welcome To RTC");
	_delay_ms(1000);
	LCD_vSendCmd(clearScreen);
	LCD_vSendString("Time");
	RTCInit();
	RTCSetTime(0x21 , 0x15 , 0x00);
	UART_vInit(9600);
	_delay_ms(300);
}

void appStart(void){
	LCD_moveCursor(2 , 1);
	RTCGetTime(&arr[0] , &arr[1] , &arr[2]);
	
	/* Display data on Atmega32 LCD */
	sendPackedBCD(arr[0]);
	LCD_vSendChar(':');
	sendPackedBCD(arr[1]);
	LCD_vSendChar(':');
	sendPackedBCD(arr[2]);
	
	/* Converting Hours Into ASCII */
	result[0] = 0x30 + (arr[0] >> 4);
	result[1] = 0x30 + (arr[0] & 0x0F);
	/* Converting Minutes Into ASCII */
	result[2] = 0x30 + (arr[1] >> 4);
	result[3] = 0x30 + (arr[1] & 0x0F);
	/* Converting Seconds Into ASCII */
	result[4] = 0x30 + (arr[2] >> 4);
	result[5] = 0x30 + (arr[2] & 0x0F);
	
	/* Sending data to PIC16F877A using UART Protocol */
	/* Sending Hours */
	UART_vSendData(result[0]);
	UART_vSendData(result[1]);
	/* Sending Minutes */
	UART_vSendData(result[2]);
	UART_vSendData(result[3]);
	/* Sending Seconds */
	UART_vSendData(result[4]);
	UART_vSendData(result[5]);
}