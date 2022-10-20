/*
 * DIO.c
 *
 * Created: 7/17/2022 7:04:13 PM
 *  Author: Sayed
 */

#include "../../Utilities/registers.h"
#include "DIO.h"
#include "../../Utilities/stdMacros.h"

/* This method is used to set the direction of the pin in a particular register */
void DIO_vSetPinDir(unsigned char portName , unsigned char pinNumber , unsigned char Dir){		// 'v' refers to return type void
	switch(portName){
		case 'A':
			if(Dir == 1){
				SET_BIT(DDRA , pinNumber);
			}else{
				CLR_BIT(DDRA , pinNumber);
			}
			break;
		case 'B':
			if(Dir == 1){
				SET_BIT(DDRB , pinNumber);
			}else{
				CLR_BIT(DDRB , pinNumber);
			}
			break;
		case 'C':
			if(Dir == 1){
				SET_BIT(DDRC , pinNumber);
			}else{
				CLR_BIT(DDRC , pinNumber);
			}
			break;
		case 'D':
			if(Dir == 1){
				SET_BIT(DDRD , pinNumber);
			}else{
				CLR_BIT(DDRD , pinNumber);
			}
			break;
		default:
			break;
	}
}

/* This method is used to write a value to a pin in a particular register */
void DIO_writePin(unsigned char portName , unsigned char pinNumber , unsigned char value){
	switch(portName){
		case 'A':
			if(value == 1){
				SET_BIT(PORTA , pinNumber);
			}else{
				CLR_BIT(PORTA , pinNumber);
			}
			break;
		case 'B':
			if(value == 1){
				SET_BIT(PORTB , pinNumber);
			}else{
				CLR_BIT(PORTB , pinNumber);
			}
			break;
		case 'C':
			if(value == 1){
				SET_BIT(PORTC , pinNumber);
			}else{
				CLR_BIT(PORTC , pinNumber);
			}
			break;
		case 'D':
			if(value == 1){
				SET_BIT(PORTD , pinNumber);
			}else{
				CLR_BIT(PORTD , pinNumber);
			}
			break;
		default:
			break;
	}
}

/* This method is used to read a value of a pin from a particular register */
unsigned char DIO_u8readPin(unsigned char portName , unsigned char pinNumber){		// u8 refers to return type unsigned char (8 bit)
	unsigned char result = 0;
	switch(portName){
		case 'A':
			result = READ_BIT(PINA , pinNumber);
			break;
		case 'B':
			result = READ_BIT(PINB , pinNumber);
			break;
		case 'C':
			result = READ_BIT(PINC , pinNumber);
			break;
		case 'D':
			result = READ_BIT(PIND , pinNumber);
			break;
		default:
			break;
	}
	return result;
}

/* This method is used to toggle a pin in a particular register */
void DIO_togPin(unsigned char portName , unsigned char pinNumber){
	switch(portName){
		case 'A':
			TOG_BIT(PORTA , pinNumber);
			break;
		case 'B':
			TOG_BIT(PORTB , pinNumber);
			break;
		case 'C':
			TOG_BIT(PORTC , pinNumber);
			break;
		case 'D':
			TOG_BIT(PORTD , pinNumber);
			break;
		default:
			break;
	}
}

/* This method is used to set the direction of a whole port register */
void DIO_setPortDir(unsigned char portName , unsigned char Dir){
	switch(portName){
		case 'A':
			if(Dir == 1){
				DDRA = 0xff;
			}else{
				DDRA = 0x00;
			}
			break;
		case 'B':
			if(Dir == 1){
				DDRB = 0xff;
			}else{
				DDRB = 0x00;
			}
			break;
		case 'C':
			if(Dir == 1){
				DDRC = 0xff;
			}else{
				DDRC = 0x00;
			}
			break;
		case 'D':
			if(Dir == 1){
				DDRD = 0xff;
			}else{
				DDRD = 0x00;
			}
			break;
		default:
			break;
	}
}

/* This method is used to write a value to a whole port register */
void DIO_writePort(unsigned char portName , unsigned char value){
	switch(portName){
		case 'A':
			PORTA = value;
			break;
		case 'B':
			PORTB = value;
			break;
		case 'C':
			PORTC = value;
			break;
		case 'D':
			PORTD = value;
			break;
		default:
			break;
	}
}

/* This method is used to read the value of a whole port register */
unsigned char DIO_readPort(unsigned char portName){
	unsigned char result = 0;
	switch(portName){
		case 'A':
			result = PINA;
			break;
		case 'B':
			result = PINB;
			break;
		case 'C':
			result = PINC;
			break;
		case 'D':
			result = PIND;
			break;
		default:
			break;
	}
	return result;
}

/* This method is used to connect the internal pull up resistor */
void DIO_vPullUp(unsigned char portName , unsigned char pinNumber , unsigned char connectValue){
	switch(portName){
		case 'A':
			if(connectValue == 1){
				SET_BIT(PORTA , pinNumber);
			}else{
				CLR_BIT(PORTA , pinNumber);
			}
			break;
		case 'B':
			if(connectValue == 1){
				SET_BIT(PORTB , pinNumber);
				}else{
				CLR_BIT(PORTB , pinNumber);
			}
			break;
		case 'C':
			if(connectValue == 1){
				SET_BIT(PORTC , pinNumber);
				}else{
				CLR_BIT(PORTC , pinNumber);
			}
			break;
		case 'D':
			if(connectValue == 1){
				SET_BIT(PORTD , pinNumber);
				}else{
				CLR_BIT(PORTD , pinNumber);
			}
			break;
		default:
			break;
	}
}

/* This method is used to write the four low pins of the atmega32 of a specific port register */
void DIO_writeLowNibble(unsigned char portName , unsigned char value){
	value &= 0x0F;
	switch(portName){
		case 'A':
			PORTA &= 0xF0;
			PORTA |= value;
			break;
		case 'B':
			PORTB &= 0xF0;
			PORTB |= value;
			break;
		case 'C':
			PORTC &= 0xF0;
			PORTC |= value;
			break;
		case 'D':
			PORTD &= 0xF0;
			PORTD |= value;
			break;
	}
}

/* This method is used to write the four high pins of the atmega32 of a specific port register */
void DIO_writeHighNibble(unsigned char portName , unsigned char value){
	value <<= 4;
	switch(portName){
		case 'A':
			PORTA &= 0x0F;
			PORTA |= value;
			break;
		case 'B':
			PORTB &= 0x0F;
			PORTB |= value;
			break;
		case 'C':
			PORTC &= 0x0F;
			PORTC |= value;
			break;
		case 'D':
			PORTD &= 0x0F;
			PORTD |= value;
			break;
	}
}