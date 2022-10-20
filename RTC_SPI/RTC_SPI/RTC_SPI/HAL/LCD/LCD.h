/*
 * LCD.h
 *
 * Created: 8/5/2022 3:52:05 PM
 *  Author: Sayed
 */ 

#ifndef LCD_H_
#define LCD_H_

#include "../../MCAL/DIO Driver/DIO.h"
#include "LCD_Config.h"
#define F_CPU 8000000UL
#include <util/delay.h>

#define dataPort 'A'
#define controlPort 'B'

/* LCD Commands */
#define clearScreen 0x01
#define cursorOn_displayOn 0x0E
#define cursorOff_displayOn 0x0C
#define returnHome 0x02
#define entryMode 0x06

#define EN 0
#define RW 1
#define RS 2

#if defined fourBitsMode
#define fourBits 0x28
#elif defined eightBitsMode
#define eightBits 0x38
#endif

void LCD_vInit(void);
static void sendRisingEdge();
void LCD_vSendChar(char data);
void LCD_vSendCmd(char cmd);
void LCD_vSendString(const char *data); /* Const because passing argument 1 of function from pointer to non-enclosed address space */
void LCD_clearScreen();
void LCD_moveCursor(char row , char col);

#endif /* LCD_H_ */