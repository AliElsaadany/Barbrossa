
_main:

;GPIO_PIC.c,24 :: 		void main()
;GPIO_PIC.c,26 :: 		Port_Direction(C,output);
	MOVLW      7
	MOVWF      FARG_Port_Direction_base+0
	CLRF       FARG_Port_Direction_state+0
	CALL       _Port_Direction+0
;GPIO_PIC.c,27 :: 		Port_Direction(B,input);
	MOVLW      6
	MOVWF      FARG_Port_Direction_base+0
	MOVLW      1
	MOVWF      FARG_Port_Direction_state+0
	CALL       _Port_Direction+0
;GPIO_PIC.c,28 :: 		while(1)
L_main0:
;GPIO_PIC.c,30 :: 		if(Pin_Read(B,3))
	MOVLW      6
	MOVWF      FARG_Pin_Read_base+0
	MOVLW      3
	MOVWF      FARG_Pin_Read_pin+0
	CALL       _Pin_Read+0
	MOVF       R0+0, 0
	BTFSC      STATUS+0, 2
	GOTO       L_main2
;GPIO_PIC.c,31 :: 		Pin_Reset(C,4);
	MOVLW      7
	MOVWF      FARG_Pin_Reset_base+0
	MOVLW      4
	MOVWF      FARG_Pin_Reset_pin+0
	CALL       _Pin_Reset+0
	GOTO       L_main3
L_main2:
;GPIO_PIC.c,33 :: 		Pin_Set(C,4);
	MOVLW      7
	MOVWF      FARG_Pin_Set_base+0
	MOVLW      4
	MOVWF      FARG_Pin_Set_pin+0
	CALL       _Pin_Set+0
L_main3:
;GPIO_PIC.c,36 :: 		}
	GOTO       L_main0
;GPIO_PIC.c,38 :: 		}
L_end_main:
	GOTO       $+0
; end of _main

_Port_Direction:

;GPIO_PIC.c,41 :: 		void Port_Direction(char base, char state)
;GPIO_PIC.c,43 :: 		if(state==output)
	MOVF       FARG_Port_Direction_state+0, 0
	XORLW      0
	BTFSS      STATUS+0, 2
	GOTO       L_Port_Direction4
;GPIO_PIC.c,44 :: 		(*(volatile unsigned char*)(base|0x80))=0x00;// TRISA=0X00
	MOVLW      128
	IORWF      FARG_Port_Direction_base+0, 0
	MOVWF      FSR
	CLRF       INDF+0
	GOTO       L_Port_Direction5
L_Port_Direction4:
;GPIO_PIC.c,46 :: 		(*(volatile unsigned char*)(base|0x80))=0xff;
	MOVLW      128
	IORWF      FARG_Port_Direction_base+0, 0
	MOVWF      FSR
	MOVLW      255
	MOVWF      INDF+0
L_Port_Direction5:
;GPIO_PIC.c,47 :: 		}
L_end_Port_Direction:
	RETURN
; end of _Port_Direction

_Pin_Direction:

;GPIO_PIC.c,49 :: 		void Pin_Direction(char base , char pin , char state)
;GPIO_PIC.c,51 :: 		if (state==output)
	MOVF       FARG_Pin_Direction_state+0, 0
	XORLW      0
	BTFSS      STATUS+0, 2
	GOTO       L_Pin_Direction6
;GPIO_PIC.c,52 :: 		(*(volatile unsigned char*)(base|0x80))&=~(1<<pin);
	MOVLW      128
	IORWF      FARG_Pin_Direction_base+0, 0
	MOVWF      R2+0
	MOVF       FARG_Pin_Direction_pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__Pin_Direction13:
	BTFSC      STATUS+0, 2
	GOTO       L__Pin_Direction14
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__Pin_Direction13
L__Pin_Direction14:
	COMF       R0+0, 0
	MOVWF      R1+0
	MOVF       R2+0, 0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      R0+0
	MOVF       R1+0, 0
	ANDWF      R0+0, 1
	MOVF       R2+0, 0
	MOVWF      FSR
	MOVF       R0+0, 0
	MOVWF      INDF+0
	GOTO       L_Pin_Direction7
L_Pin_Direction6:
;GPIO_PIC.c,54 :: 		(*(volatile unsigned char*)(base|0x80))|=(1<<pin);
	MOVLW      128
	IORWF      FARG_Pin_Direction_base+0, 0
	MOVWF      R2+0
	MOVF       FARG_Pin_Direction_pin+0, 0
	MOVWF      R0+0
	MOVLW      1
	MOVWF      R1+0
	MOVF       R0+0, 0
L__Pin_Direction15:
	BTFSC      STATUS+0, 2
	GOTO       L__Pin_Direction16
	RLF        R1+0, 1
	BCF        R1+0, 0
	ADDLW      255
	GOTO       L__Pin_Direction15
L__Pin_Direction16:
	MOVF       R2+0, 0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      R0+0
	MOVF       R1+0, 0
	IORWF      R0+0, 1
	MOVF       R2+0, 0
	MOVWF      FSR
	MOVF       R0+0, 0
	MOVWF      INDF+0
L_Pin_Direction7:
;GPIO_PIC.c,55 :: 		}
L_end_Pin_Direction:
	RETURN
; end of _Pin_Direction

_Pin_Reset:

;GPIO_PIC.c,57 :: 		void Pin_Reset (char base , char pin )
;GPIO_PIC.c,59 :: 		(*(volatile unsigned char*)(base))&=~(1<<pin);
	MOVF       FARG_Pin_Reset_pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__Pin_Reset18:
	BTFSC      STATUS+0, 2
	GOTO       L__Pin_Reset19
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__Pin_Reset18
L__Pin_Reset19:
	COMF       R0+0, 0
	MOVWF      R1+0
	MOVF       FARG_Pin_Reset_base+0, 0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      R0+0
	MOVF       R1+0, 0
	ANDWF      R0+0, 1
	MOVF       FARG_Pin_Reset_base+0, 0
	MOVWF      FSR
	MOVF       R0+0, 0
	MOVWF      INDF+0
;GPIO_PIC.c,60 :: 		}
L_end_Pin_Reset:
	RETURN
; end of _Pin_Reset

_Pin_Set:

;GPIO_PIC.c,62 :: 		void Pin_Set (char base , char pin )
;GPIO_PIC.c,64 :: 		(*(volatile unsigned char*)(base))|=(1<<pin);
	MOVF       FARG_Pin_Set_pin+0, 0
	MOVWF      R0+0
	MOVLW      1
	MOVWF      R1+0
	MOVF       R0+0, 0
L__Pin_Set21:
	BTFSC      STATUS+0, 2
	GOTO       L__Pin_Set22
	RLF        R1+0, 1
	BCF        R1+0, 0
	ADDLW      255
	GOTO       L__Pin_Set21
L__Pin_Set22:
	MOVF       FARG_Pin_Set_base+0, 0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      R0+0
	MOVF       R1+0, 0
	IORWF      R0+0, 1
	MOVF       FARG_Pin_Set_base+0, 0
	MOVWF      FSR
	MOVF       R0+0, 0
	MOVWF      INDF+0
;GPIO_PIC.c,65 :: 		}
L_end_Pin_Set:
	RETURN
; end of _Pin_Set

_Pin_Toggle:

;GPIO_PIC.c,67 :: 		void Pin_Toggle (char base , char pin )
;GPIO_PIC.c,69 :: 		(*(volatile unsigned char*)(base))^=(1<<pin);
	MOVF       FARG_Pin_Toggle_pin+0, 0
	MOVWF      R0+0
	MOVLW      1
	MOVWF      R1+0
	MOVF       R0+0, 0
L__Pin_Toggle24:
	BTFSC      STATUS+0, 2
	GOTO       L__Pin_Toggle25
	RLF        R1+0, 1
	BCF        R1+0, 0
	ADDLW      255
	GOTO       L__Pin_Toggle24
L__Pin_Toggle25:
	MOVF       FARG_Pin_Toggle_base+0, 0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      R0+0
	MOVF       R1+0, 0
	XORWF      R0+0, 1
	MOVF       FARG_Pin_Toggle_base+0, 0
	MOVWF      FSR
	MOVF       R0+0, 0
	MOVWF      INDF+0
;GPIO_PIC.c,70 :: 		}
L_end_Pin_Toggle:
	RETURN
; end of _Pin_Toggle

_Port_Write:

;GPIO_PIC.c,72 :: 		void Port_Write(char base , char value)
;GPIO_PIC.c,74 :: 		(*(volatile unsigned char*)(base))=value;
	MOVF       FARG_Port_Write_base+0, 0
	MOVWF      FSR
	MOVF       FARG_Port_Write_value+0, 0
	MOVWF      INDF+0
;GPIO_PIC.c,76 :: 		}
L_end_Port_Write:
	RETURN
; end of _Port_Write

_Port_Read:

;GPIO_PIC.c,78 :: 		char Port_Read (char base )
;GPIO_PIC.c,81 :: 		result= (*(volatile unsigned char*)(base));
	MOVF       FARG_Port_Read_base+0, 0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      R0+0
	MOVF       R0+0, 0
	MOVWF      R1+0
;GPIO_PIC.c,82 :: 		return result;
	MOVF       R1+0, 0
	MOVWF      R0+0
;GPIO_PIC.c,83 :: 		}
L_end_Port_Read:
	RETURN
; end of _Port_Read

_Pin_Write:

;GPIO_PIC.c,85 :: 		void Pin_Write(char base, char pin, char value)
;GPIO_PIC.c,87 :: 		if (value==0)
	MOVF       FARG_Pin_Write_value+0, 0
	XORLW      0
	BTFSS      STATUS+0, 2
	GOTO       L_Pin_Write8
;GPIO_PIC.c,88 :: 		(*(volatile unsigned char*)(base))|=1<<pin ;
	MOVF       FARG_Pin_Write_pin+0, 0
	MOVWF      R0+0
	MOVLW      1
	MOVWF      R1+0
	MOVF       R0+0, 0
L__Pin_Write29:
	BTFSC      STATUS+0, 2
	GOTO       L__Pin_Write30
	RLF        R1+0, 1
	BCF        R1+0, 0
	ADDLW      255
	GOTO       L__Pin_Write29
L__Pin_Write30:
	MOVF       FARG_Pin_Write_base+0, 0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      R0+0
	MOVF       R1+0, 0
	IORWF      R0+0, 1
	MOVF       FARG_Pin_Write_base+0, 0
	MOVWF      FSR
	MOVF       R0+0, 0
	MOVWF      INDF+0
	GOTO       L_Pin_Write9
L_Pin_Write8:
;GPIO_PIC.c,90 :: 		(*(volatile unsigned char*)(base)) &=~(1<<pin);
	MOVF       FARG_Pin_Write_pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__Pin_Write31:
	BTFSC      STATUS+0, 2
	GOTO       L__Pin_Write32
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__Pin_Write31
L__Pin_Write32:
	COMF       R0+0, 0
	MOVWF      R1+0
	MOVF       FARG_Pin_Write_base+0, 0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      R0+0
	MOVF       R1+0, 0
	ANDWF      R0+0, 1
	MOVF       FARG_Pin_Write_base+0, 0
	MOVWF      FSR
	MOVF       R0+0, 0
	MOVWF      INDF+0
L_Pin_Write9:
;GPIO_PIC.c,91 :: 		}
L_end_Pin_Write:
	RETURN
; end of _Pin_Write

_Pin_Read:

;GPIO_PIC.c,93 :: 		char Pin_Read (char base, char pin)
;GPIO_PIC.c,96 :: 		result= (*(volatile unsigned char*)(base)&(1<<pin));
	MOVF       FARG_Pin_Read_base+0, 0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      R2+0
	MOVF       FARG_Pin_Read_pin+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__Pin_Read34:
	BTFSC      STATUS+0, 2
	GOTO       L__Pin_Read35
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__Pin_Read34
L__Pin_Read35:
	MOVF       R0+0, 0
	ANDWF      R2+0, 0
	MOVWF      R3+0
;GPIO_PIC.c,97 :: 		return result;
	MOVF       R3+0, 0
	MOVWF      R0+0
;GPIO_PIC.c,98 :: 		}
L_end_Pin_Read:
	RETURN
; end of _Pin_Read
