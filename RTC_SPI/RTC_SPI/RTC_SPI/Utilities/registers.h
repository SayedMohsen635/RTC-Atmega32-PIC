/*
 * registers.h
 *
 * Created: 9/6/2022 11:09:17 PM
 *  Author: sayed
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_
#include "dataTypes.h"

/* Special Function I/O Register */
#define SFIOR *((volatile uint8_t*)0x50)	// 8-bit register

/************************************************************************/
/*						DIO Registers                                   */
/************************************************************************/

// PORTA Registers
#define PORTA *((volatile uint8_t*)0x3B)	// 8-bit register
#define DDRA  *((volatile uint8_t*)0x3A)	// 8-bit register
#define PINA  *((volatile uint8_t*)0x39)	// 8-bit register

// PORTB Registers
#define PORTB *((volatile uint8_t*)0x38)	// 8-bit register
#define DDRB  *((volatile uint8_t*)0x37)	// 8-bit register
#define PINB  *((volatile uint8_t*)0x36)	// 8-bit register

// PORTC Registers
#define PORTC *((volatile uint8_t*)0x35)	// 8-bit register
#define DDRC  *((volatile uint8_t*)0x34)	// 8-bit register
#define PINC  *((volatile uint8_t*)0x33)	// 8-bit register

// PORTD Registers
#define PORTD *((volatile uint8_t*)0x32)	// 8-bit register
#define DDRD  *((volatile uint8_t*)0x31)	// 8-bit register
#define PIND  *((volatile uint8_t*)0x30)	// 8-bit register

/************************************************************************/
/*						Timer0 Registers                                */
/************************************************************************/

#define TCCR0 *((volatile uint8_t*)0x53)	// 8-bit register
#define TCNT0 *((volatile uint8_t*)0x52)	// 8-bit register
#define TIFR  *((volatile uint8_t*)0x58)	// 8-bit register
#define TIMSK *((volatile uint8_t*)0x59)	// 8-bit register
#define OCR0  *((volatile uint8_t*)0x5C)	// 8-bit register

/************************************************************************/
/*				    External Interrupts Registers                       */
/************************************************************************/

#define MCUCR  *((volatile uint8_t*)0x55)	// 8-bit register
#define MCUCSR *((volatile uint8_t*)0x54)	// 8-bit register
#define GICR   *((volatile uint8_t*)0x5B)	// 8-bit register
#define GIFR   *((volatile uint8_t*)0x5A)	// 8-bit register

/************************************************************************/
/*                   ADC Registers                                      */
/************************************************************************/
#define ADMUX	*((volatile uint8_t*)0x27)	// 8-bit register
#define ADCSRA	*((volatile uint8_t*)0x26)	// 8-bit register
#define ADCH	*((volatile uint8_t*)0x25)	// 8-bit register
#define ADCL	*((volatile uint8_t*)0x24)	// 8-bit register

/************************************************************************/
/*                   I2C Registers                                      */
/************************************************************************/
#define TWBR	*((volatile uint8_t*)0x20)	// 8-bit register
#define TWSR	*((volatile uint8_t*)0x21)	// 8-bit register
#define TWAR	*((volatile uint8_t*)0x22)	// 8-bit register
#define TWDR	*((volatile uint8_t*)0x23)	// 8-bit register
#define TWCR	*((volatile uint8_t*)0x56)	// 8-bit register

/************************************************************************/
/*                   UART Registers                                      */
/************************************************************************/
#define UBRRH	*((volatile uint8_t*)0x40)	// 8-bit register
#define UBRRL	*((volatile uint8_t*)0x29)	// 8-bit register
#define UCSRB	*((volatile uint8_t*)0x2A)	// 8-bit register
#define USCRC	*((volatile uint8_t*)0x40)	// 8-bit register
#define UCSRA	*((volatile uint8_t*)0x2A)	// 8-bit register
#define UDR		*((volatile uint8_t*)0x2C)	// 8-bit register

#endif /* REGISTERS_H_ */

