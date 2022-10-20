
_main:

;Solution.c,37 :: 		void main(){
;Solution.c,38 :: 		Lcd_Init();
	CALL       _Lcd_Init+0
;Solution.c,39 :: 		Lcd_Cmd(_LCD_CURSOR_OFF);
	MOVLW      12
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;Solution.c,40 :: 		Lcd_Out(1 , 1 , "Time");
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr1_Solution+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;Solution.c,41 :: 		UART1_Init(9600); // Initialize UART module at 9600bps
	MOVLW      6
	MOVWF      SPBRG+0
	BSF        TXSTA+0, 2
	CALL       _UART1_Init+0
;Solution.c,42 :: 		Delay_ms(300); // Wait for UART module to stabilize
	MOVLW      98
	MOVWF      R12+0
	MOVLW      101
	MOVWF      R13+0
L_main0:
	DECFSZ     R13+0, 1
	GOTO       L_main0
	DECFSZ     R12+0, 1
	GOTO       L_main0
	NOP
	NOP
;Solution.c,43 :: 		while(1){
L_main1:
;Solution.c,45 :: 		if(UART1_Data_Ready() == 1){
	CALL       _UART1_Data_Ready+0
	MOVF       R0+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_main3
;Solution.c,46 :: 		arr[0] = UART1_Read();
	CALL       _UART1_Read+0
	MOVF       R0+0, 0
	MOVWF      _arr+0
;Solution.c,47 :: 		}
L_main3:
;Solution.c,48 :: 		Lcd_Chr(2 , 1 , arr[0]);
	MOVLW      2
	MOVWF      FARG_Lcd_Chr_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Chr_column+0
	MOVF       _arr+0, 0
	MOVWF      FARG_Lcd_Chr_out_char+0
	CALL       _Lcd_Chr+0
;Solution.c,49 :: 		if(UART1_Data_Ready() == 1){
	CALL       _UART1_Data_Ready+0
	MOVF       R0+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_main4
;Solution.c,50 :: 		arr[1] = UART1_Read();
	CALL       _UART1_Read+0
	MOVF       R0+0, 0
	MOVWF      _arr+1
;Solution.c,51 :: 		}
L_main4:
;Solution.c,52 :: 		Lcd_Chr(2 , 2 , arr[1]);
	MOVLW      2
	MOVWF      FARG_Lcd_Chr_row+0
	MOVLW      2
	MOVWF      FARG_Lcd_Chr_column+0
	MOVF       _arr+1, 0
	MOVWF      FARG_Lcd_Chr_out_char+0
	CALL       _Lcd_Chr+0
;Solution.c,54 :: 		Lcd_Chr(2 , 3 , ':');
	MOVLW      2
	MOVWF      FARG_Lcd_Chr_row+0
	MOVLW      3
	MOVWF      FARG_Lcd_Chr_column+0
	MOVLW      58
	MOVWF      FARG_Lcd_Chr_out_char+0
	CALL       _Lcd_Chr+0
;Solution.c,57 :: 		if(UART1_Data_Ready() == 1){
	CALL       _UART1_Data_Ready+0
	MOVF       R0+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_main5
;Solution.c,58 :: 		arr[2] = UART1_Read();
	CALL       _UART1_Read+0
	MOVF       R0+0, 0
	MOVWF      _arr+2
;Solution.c,59 :: 		}
L_main5:
;Solution.c,60 :: 		Lcd_Chr(2 , 4 , arr[2]);
	MOVLW      2
	MOVWF      FARG_Lcd_Chr_row+0
	MOVLW      4
	MOVWF      FARG_Lcd_Chr_column+0
	MOVF       _arr+2, 0
	MOVWF      FARG_Lcd_Chr_out_char+0
	CALL       _Lcd_Chr+0
;Solution.c,61 :: 		if(UART1_Data_Ready() == 1){
	CALL       _UART1_Data_Ready+0
	MOVF       R0+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_main6
;Solution.c,62 :: 		arr[3] = UART1_Read();
	CALL       _UART1_Read+0
	MOVF       R0+0, 0
	MOVWF      _arr+3
;Solution.c,63 :: 		}
L_main6:
;Solution.c,64 :: 		Lcd_Chr(2 , 5 , arr[3]);
	MOVLW      2
	MOVWF      FARG_Lcd_Chr_row+0
	MOVLW      5
	MOVWF      FARG_Lcd_Chr_column+0
	MOVF       _arr+3, 0
	MOVWF      FARG_Lcd_Chr_out_char+0
	CALL       _Lcd_Chr+0
;Solution.c,66 :: 		Lcd_Chr(2 , 6 , ':');
	MOVLW      2
	MOVWF      FARG_Lcd_Chr_row+0
	MOVLW      6
	MOVWF      FARG_Lcd_Chr_column+0
	MOVLW      58
	MOVWF      FARG_Lcd_Chr_out_char+0
	CALL       _Lcd_Chr+0
;Solution.c,69 :: 		if(UART1_Data_Ready() == 1){
	CALL       _UART1_Data_Ready+0
	MOVF       R0+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_main7
;Solution.c,70 :: 		arr[4] = UART1_Read();
	CALL       _UART1_Read+0
	MOVF       R0+0, 0
	MOVWF      _arr+4
;Solution.c,71 :: 		}
L_main7:
;Solution.c,72 :: 		Lcd_Chr(2 , 7 , arr[4]);
	MOVLW      2
	MOVWF      FARG_Lcd_Chr_row+0
	MOVLW      7
	MOVWF      FARG_Lcd_Chr_column+0
	MOVF       _arr+4, 0
	MOVWF      FARG_Lcd_Chr_out_char+0
	CALL       _Lcd_Chr+0
;Solution.c,73 :: 		if(UART1_Data_Ready() == 1){
	CALL       _UART1_Data_Ready+0
	MOVF       R0+0, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L_main8
;Solution.c,74 :: 		arr[5] = UART1_Read();
	CALL       _UART1_Read+0
	MOVF       R0+0, 0
	MOVWF      _arr+5
;Solution.c,75 :: 		}
L_main8:
;Solution.c,76 :: 		Lcd_Chr(2 , 8 , arr[5]);
	MOVLW      2
	MOVWF      FARG_Lcd_Chr_row+0
	MOVLW      8
	MOVWF      FARG_Lcd_Chr_column+0
	MOVF       _arr+5, 0
	MOVWF      FARG_Lcd_Chr_out_char+0
	CALL       _Lcd_Chr+0
;Solution.c,77 :: 		}
	GOTO       L_main1
;Solution.c,78 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
