#line 1 "D:/4th Computer Engineering/Labs/Communication Protocols/Atmega To PIC/Solution.c"

unsigned char arr[6];

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
#pragma config FOSC = XT
#pragma config WDTE = OFF
#pragma config PWRTE = ON
#pragma config BOREN = ON
#pragma config LVP = OFF
#pragma config CPD = OFF
#pragma config WRT = OFF
#pragma config CP = OFF
#line 37 "D:/4th Computer Engineering/Labs/Communication Protocols/Atmega To PIC/Solution.c"
void main(){
 Lcd_Init();
 Lcd_Cmd(_LCD_CURSOR_OFF);
 Lcd_Out(1 , 1 , "Time");
 UART1_Init(9600);
 Delay_ms(300);
 while(1){

 if(UART1_Data_Ready() == 1){
 arr[0] = UART1_Read();
 }
 Lcd_Chr(2 , 1 , arr[0]);
 if(UART1_Data_Ready() == 1){
 arr[1] = UART1_Read();
 }
 Lcd_Chr(2 , 2 , arr[1]);

 Lcd_Chr(2 , 3 , ':');


 if(UART1_Data_Ready() == 1){
 arr[2] = UART1_Read();
 }
 Lcd_Chr(2 , 4 , arr[2]);
 if(UART1_Data_Ready() == 1){
 arr[3] = UART1_Read();
 }
 Lcd_Chr(2 , 5 , arr[3]);

 Lcd_Chr(2 , 6 , ':');


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
