/*
 * LCD.c
 *
 * Created: 8/5/2022 3:51:53 PM
 *  Author: Sayed
 */ 

#include "LCD.h"

/* This method initializes the LCD */
void LCD_vInit(void){
	_delay_ms(200);
	#if defined eightBitsMode
	DIO_setPortDir(dataPort , 1);
	DIO_vSetPinDir(controlPort , EN , 1);
	DIO_vSetPinDir(controlPort , RW , 1);
	DIO_vSetPinDir(controlPort , RS , 1);
	DIO_writePin(controlPort , RW , 0);
	LCD_vSendCmd(eightBits);
	_delay_ms(1);
	LCD_vSendCmd(cursorOn_displayOn);
	_delay_ms(1);
	LCD_vSendCmd(clearScreen);
	_delay_ms(10);
	LCD_vSendCmd(entryMode);
	_delay_ms(1);
	#elif defined fourBitsMode
	for(int i = 4; i < 8; i++){
		DIO_vSetPinDir(dataPort , i , 1);
	}
	DIO_vSetPinDir(controlPort , EN , 1);
	DIO_vSetPinDir(controlPort , RW , 1);
	DIO_vSetPinDir(controlPort , RS , 1);
	DIO_writePin(controlPort , RW , 0);
	LCD_vSendCmd(returnHome);
	_delay_ms(10);
	LCD_vSendCmd(fourBits);
	_delay_ms(1);
	LCD_vSendCmd(cursorOn_displayOn);
	_delay_ms(1);
	LCD_vSendCmd(clearScreen);
	_delay_ms(10);
	LCD_vSendCmd(entryMode);
	_delay_ms(1);
	#endif
}

/* To give a rising edge for enable, it's static not to call it outside the file */
static void sendRisingEdge(){
	DIO_writePin(controlPort , EN , 1);
	_delay_ms(2);
	DIO_writePin(controlPort , EN , 0);
	_delay_ms(2);
}

/* This method sends a character to the LCD */
void LCD_vSendChar(char data){
	#if defined eightBitsMode
	DIO_writePort(dataPort , data);
	DIO_writePin(controlPort , RS , 1);
	sendRisingEdge();
	#elif defined fourBitsMode
	DIO_writeHighNibble(dataPort , data >> 4);
	DIO_writePin(controlPort , RS , 1);
	sendRisingEdge();
	DIO_writeHighNibble(dataPort , data);
	DIO_writePin(controlPort , RS , 1);
	sendRisingEdge();
	#endif
	_delay_ms(1);
}

/* This method sends a command to the LCD */
void LCD_vSendCmd(char cmd){
	#if defined eightBitsMode
	DIO_writePort(dataPort , cmd);
	DIO_writePin(controlPort , RS , 0);
	sendRisingEdge();
	#elif defined fourBitsMode
	DIO_writeHighNibble(dataPort , cmd >> 4);
	DIO_writePin(controlPort , RS , 0);
	sendRisingEdge();
	DIO_writeHighNibble(dataPort , cmd);
	DIO_writePin(dataPort , RS , 0);
	sendRisingEdge();
	#endif
	_delay_ms(1);
}

/* This method sends string to the LCD and prints it */
void LCD_vSendString(const char *data){
	while((*data) != '\0'){
		LCD_vSendChar(*data);
		data++;
	}
}

/* This method clears the LCD screen */
void LCD_clearScreen(){
	LCD_vSendCmd(clearScreen);
	_delay_ms(10);
}

/* This method is used to move the cursor in a specific row and column */
void LCD_moveCursor(char row , char col){
	char data = 0;
	if(row > 2 || row < 1 || col > 16 || col < 1){
		data = 0x80;
	}else if(row == 1){
		data = 0x80 + col - 1;
	}else if(row == 2){
		data = 0xC0 + col - 1;
	}
	LCD_vSendCmd(data);
	_delay_ms(1);
}