/*
 * RTC.c
 *
 * Created: 10/15/2022 11:25:16 PM
 *  Author: sayed
 */ 

#include "RTC.h"
#include "../LCD/LCD.h"
#include "../LCD/LCD_Config.h"

void RTCInit(void){
	I2CInit(100000);
	I2CStart();
	I2CWrite(0xD0);			// Address of DS1307 Chip
	I2CWrite(0x07);			// Command Register Address
	I2CWrite(0x00);			// Select First Address
	I2C_stop();
}

void RTCSetTime(uint8_t hour , uint8_t minute , uint8_t second){
	I2CStart();
	I2CWrite(0xD0);			// Address of DS1307 Chip
	I2CWrite(0x00);			// First address of register will be selected
	I2CWrite(second);		// 
	I2CWrite(minute);		// 
	I2CWrite(hour);			// 
	I2C_stop();
}

void RTCGetTime(uint8_t *hour , uint8_t *minute , uint8_t *second){
	I2CStart();
	I2CWrite(0xD0);			// Address of DS1307 Chip
	I2CWrite(0x00);			// First address of register will be selected
	I2C_stop();				// We stop here to be able to read after assigning the address
	
	I2CStart();				// Now we are in read mode
	I2CWrite(0xD1);
	*second = I2CRead(1);
	*minute = I2CRead(1);
	*hour = I2CRead(0);		// We didn't need to return ACK because we don't need to read bytes anymore
	I2C_stop();
}

void sendPackedBCD(uint8_t data){
	LCD_vSendChar(0x30 + (data >> 4));
	_delay_ms(1);
	LCD_vSendChar(0x30 + (data & 0x0F));
}