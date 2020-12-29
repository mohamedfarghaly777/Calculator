
#include "LIB/STD_TYPES.h"
#include "DIO_int.h"
#include "KPAD_int.h"
#include "LCD_int.h"



void main(void)

{	u8 u8PressedKey;
	u8 oper ;
	/* Set KeyPad Columns Pins direction */
	DIO_vidSetPinDirection(PortC,Pin0,Output);
	DIO_vidSetPinDirection(PortC,Pin1,Output);
	DIO_vidSetPinDirection(PortC,Pin2,Output);
	DIO_vidSetPinDirection(PortC,Pin3,Output);
	/* Set KeyPad Row Pins direction */
	DIO_vidSetPinDirection(PortC,Pin4,Input);
	DIO_vidSetPinDirection(PortC,Pin5,Input);
	DIO_vidSetPinDirection(PortC,Pin6,Input);
	DIO_vidSetPinDirection(PortC,Pin7,Input);


	/* Set LCD data Port directions */
	DIO_vidSetPortDir(PortA,Output);
	/* Set LCD Control Pins directions */
	DIO_vidSetPinDirection(PortD,Pin0,Output);
	DIO_vidSetPinDirection(PortD,Pin1,Output);
	DIO_vidSetPinDirection(PortD,Pin2,Output);


	KPAD_vidInit();
	LCD_vidInit();
	u16 result = 0 ;

	u8 n1 =0;
	u8 n2 =0;
	u8 flag= 0 ;
	u8 flag2= 0 ;
	u8 flag3 =0;
	u8 temp =0;
	while(1)
	{
		u8PressedKey = KPAD_u8GetPressedKey();

		if(u8PressedKey!=KPAD_NOKEY_PRESSED){

		while (u8PressedKey!=0x0D && u8PressedKey!=0x0F && u8PressedKey!=0x0A && u8PressedKey!=0x0B && u8PressedKey!=0x0C && u8PressedKey!=0x10 && u8PressedKey != KPAD_NOKEY_PRESSED){
			if (flag == 0 ){
				LCD_vidWriteNumber(u8PressedKey);
			n1= n1 *10 + u8PressedKey;
			u8PressedKey = KPAD_u8GetPressedKey();
				}
			else {
				LCD_vidWriteNumber(u8PressedKey);
			n2= n2 *10 + u8PressedKey;
			u8PressedKey = KPAD_u8GetPressedKey();
			flag3=1;
				}}
		flag=1;
		oper = u8PressedKey;
		if (oper == 0x0F ){
			LCD_vidWriteChar('=');
			flag2=1;
		}
		if (oper==0x0A ){
			LCD_vidWriteChar('+');
			temp = oper;
		}
		else if (oper== 0x0B ){
			LCD_vidWriteChar('-');
			temp = oper;
		}
		else if (oper== 0x0C ){
			LCD_vidWriteChar('*');
			temp = oper;
				}
		else if (oper== 0x10 ){
			LCD_vidWriteChar('/');
			temp = oper;
				}
		else if (oper== 0x0D ){
			LCD_vidWriteCommand(LCD_CLR);
			flag=0;
			flag2 =0;
			flag3=0;
			result=0;
			n1=0;
			n2=0;
			temp=0;
			oper=0;
				}

		if (flag &&flag2 && flag3){
			if (temp==0x0A ){

			result= n1 + n2;
		}
		else if (temp== 0x0B ){

			result= n1 - n2;
		}
		else if (temp== 0x0C ){

			result= n1 * n2;
				}
		else if (temp== 0x10 ){

			result= n1 / n2;
				}


			LCD_vidWriteNumber(result);
			flag=0;
			flag2 =0;
			flag3=0;
			result=0;
			n1=0;
			n2=0;
			temp=0;
			oper=0;
			}
		}
		}

}
