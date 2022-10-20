/*
 * I2C.c
 *
 * Created: 10/15/2022 11:52:26 PM
 *  Author: sayed
 */ 

#include "I2C.h"

void I2CInit(uint32 SCL_Clock){
	TWBR = (uint8_t)(((F_CPU / SCL_Clock) - 16) / (2 * prescaler));
	if(prescaler == 1){
		TWSR = 0;
	}
	else if(prescaler == 4){
		TWSR = 1;
	}
	else if(prescaler == 16){
		TWSR = 2;
	}
	else if(prescaler == 64){
		TWSR = 3;
	}
}

void I2CStart(void){
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTA);
	while((TWCR & (1 << TWINT)) == 0);		// Wait to finish
}

void I2CWrite(uint8_t data){
	TWDR = data;
	TWCR = (1 << TWINT) | (1 << TWEN);
	while((TWCR & (1 << TWINT)) == 0);		// Wait to finish
}

uint8_t I2CRead(uint8_t ack){
	TWCR = (1 << TWINT) | (1 << TWEN) | (ack << TWEA);
	while((TWCR & (1 << TWINT)) == 0);
	return TWDR;
}

void I2C_stop(void){
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
	for(int i = 0; i < 100; i++);
}