/*
 * I2C.h
 *
 * Created: 10/15/2022 11:52:35 PM
 *  Author: sayed
 */ 


#ifndef I2C_H_
#define I2C_H_
#define prescaler 1
#define F_CPU 1000000UL
#include "../../Utilities/dataTypes.h"
#include "../../Utilities/registers.h"
#include "../../Utilities/stdMacros.h"

/* TWCR */
#define TWINT   7
#define TWEA    6
#define TWSTA   5
#define TWSTO   4
#define TWWC    3
#define TWEN    2
/* bit 1 reserved */
#define TWIE    0

/* TWAR */
#define TWA6    7
#define TWA5    6
#define TWA4    5
#define TWA3    4
#define TWA2    3
#define TWA1    2
#define TWA0    1
#define TWGCE   0

/* TWSR */
#define TWS7    7
#define TWS6    6
#define TWS5    5
#define TWS4    4
#define TWS3    3
/* bit 2 reserved */
#define TWPS1   1
#define TWPS0   0

void I2CInit(uint32 SCL_Clock);
void I2CStart(void);
void I2CWrite(uint8_t data);
uint8_t I2CRead(uint8_t ack);
void I2C_stop(void);

#endif /* I2C_H_ */