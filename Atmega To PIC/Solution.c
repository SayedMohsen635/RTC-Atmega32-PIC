/* Array Of Receiving Data */
unsigned char arr[6];
// LCD module connections
sbit LCD_RS at RB4_bit;
sbit LCD_EN at RB5_bit;
sbit LCD_D4 at RB0_bit;
sbit LCD_D5 at RB1_bit;
sbit LCD_D6 at RB2_bit;
sbit LCD_D7 at RB3_bit;

sbit LCD_RS_Direction at TRISB4_bit;
sbit LCD_EN_Direction at TRISB5_bit;
sbit LCD_D4_Direction at TRISB0_bit;
sbit LCD_D5_Direction at TRISB1_bit;
sbit LCD_D6_Direction at TRISB2_bit;
sbit LCD_D7_Direction at TRISB3_bit;
// End LCD module connections

// [ PIC16F877A ] Configuration Bit Settings
// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

// CONFIG
#pragma config FOSC = XT  // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOREN = ON // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF  // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit
                          // (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF  // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF  // Flash Program Memory Write Enable bits
                          // (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF   // Flash Program Memory Code Protection bit (Code protection off)

void main(){
  Lcd_Init();
  Lcd_Cmd(_LCD_CURSOR_OFF);
  Lcd_Out(1 , 1 , "Time");
  UART1_Init(9600); // Initialize UART module at 9600bps
  Delay_ms(300); // Wait for UART module to stabilize
  while(1){
       /* Receiving Hours And Displaying On LCD */
       if(UART1_Data_Ready() == 1){
          arr[0] = UART1_Read();
       }
       Lcd_Chr(2 , 1 , arr[0]);
       if(UART1_Data_Ready() == 1){
          arr[1] = UART1_Read();
       }
       Lcd_Chr(2 , 2 , arr[1]);
       /* ----------------------------------------- */
       Lcd_Chr(2 , 3 , ':');
       /* ----------------------------------------- */
       /* Receiving Minutes And Displaying On LCD */
       if(UART1_Data_Ready() == 1){
          arr[2] = UART1_Read();
       }
       Lcd_Chr(2 , 4 , arr[2]);
       if(UART1_Data_Ready() == 1){
          arr[3] = UART1_Read();
       }
       Lcd_Chr(2 , 5 , arr[3]);
       /* ----------------------------------------- */
       Lcd_Chr(2 , 6 , ':');
       /* ----------------------------------------- */
       /* Receiving Seconds And Displaying On LCD */
       if(UART1_Data_Ready() == 1){
          arr[4] = UART1_Read();
       }
       Lcd_Chr(2 , 7 , arr[4]);
       if(UART1_Data_Ready() == 1){
          arr[5] = UART1_Read();
       }
       Lcd_Chr(2 , 8 , arr[5]);
  }
}