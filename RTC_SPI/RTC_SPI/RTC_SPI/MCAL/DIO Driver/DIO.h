/*
 * DIO.h
 *
 * Created: 7/17/2022 7:04:28 PM
 *  Author: Sayed
 */ 


#ifndef DIO_H_
#define DIO_H_

/*
	Function Name        : DIO_vSetPinDir
	Function Returns     : void
	Function Arguments   : unsigned char , unsigned char , unsigned char 
	Function Description : Setting the direction of the pin in a particular register
*/
void DIO_vSetPinDir(unsigned char portName , unsigned char pinNumber , unsigned char Dir);

/*
	Function Name        : DIO_writePin
	Function Returns     : void
	Function Arguments   : unsigned char , unsigned char , unsigned char
	Function Description : Writing a value to a pin in a particular register
*/
void DIO_writePin(unsigned char portName , unsigned char pinNumber , unsigned char value);

/*
	Function Name        : DIO_u8readPin
	Function Returns     : unsigned char
	Function Arguments   : unsigned char , unsigned char
	Function Description : Reading a value of a pin from a particular register
*/
unsigned char DIO_u8readPin(unsigned char portName , unsigned char pinNumber);

/*
	Function Name        : DIO_togPin
	Function Returns     : void
	Function Arguments   : unsigned char , unsigned char
	Function Description : Toggling a pin in a particular register
*/
void DIO_togPin(unsigned char portName , unsigned char pinNumber);

/*
	Function Name        : DIO_setPortDir
	Function Returns     : void
	Function Arguments   : unsigned char , unsigned char
	Function Description : Setting the direction of a whole port register
*/
void DIO_setPortDir(unsigned char portName , unsigned char Dir);

/*
	Function Name        : DIO_writePort
	Function Returns     : void
	Function Arguments   : unsigned char , unsigned char
	Function Description : Writing a value to a whole port register
*/
void DIO_writePort(unsigned char portName , unsigned char value);

/*
	Function Name        : DIO_readPort
	Function Returns     : unsigned char
	Function Arguments   : unsigned char
	Function Description : Reading the value of a whole port register
*/
unsigned char DIO_readPort(unsigned char portName);

/*
	Function Name        : DIO_vPullUp
	Function Returns     : void
	Function Arguments   : unsigned char , unsigned char , unsigned char
	Function Description : Connecting the internal pull up resistor
*/
void DIO_vPullUp(unsigned char portName , unsigned char pinNumber , unsigned char connectValue);

/*
	Function Name        : DIO_writeLowNibble
	Function Returns     : void
	Function Arguments   : unsigned char , unsigned char
	Function Description : Writing the four low pins of the atmega32 of a specific port register
*/
void DIO_writeLowNibble(unsigned char portName , unsigned char value);

/*
	Function Name        : DIO_writeHighNibble
	Function Returns     : void
	Function Arguments   : unsigned char , unsigned char
	Function Description : Write the four high pins of the atmega32 of a specific port register
*/
void DIO_writeHighNibble(unsigned char portName , unsigned char value);

#endif /* DIO_H_ */