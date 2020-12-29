
#include "LIB/STD_TYPES.h"
#include "LCD_int.h"
#define F_CPU 8000000UL
#include "avr/delay.h"
#include "DIO_int.h"
#include "LCD_cfg.h"

void LCD_vidInit(void)
{
	_delay_ms(30);

	LCD_vidWriteCommand(LCD_FUNCSET);

	_delay_ms(1);

	LCD_vidWriteCommand(LCD_DISPON_BLINK);

	_delay_ms(1);

	LCD_vidWriteCommand(LCD_CLR);

	_delay_ms(2);

	LCD_vidWriteCommand(LCD_ENTRYMODE);
}

void LCD_vidWriteCommand(u8 u8CmdCpy)
{
	DIO_vidSetPinValue(LCD_CTRL_PORT,RS_PIN,Low);

	DIO_vidSetPinValue(LCD_CTRL_PORT,RW_PIN,Low);

	DIO_vidSetPinValue(LCD_CTRL_PORT,E_PIN,High);

	DIO_vidSetPortValue(LCD_DATA_PORT,u8CmdCpy);

	DIO_vidSetPinValue(LCD_CTRL_PORT,E_PIN,Low);

	_delay_ms(5);

	DIO_vidSetPinValue(LCD_CTRL_PORT,E_PIN,High);
}

void LCD_vidWriteChar(u8 u8DataCpy)
{
	DIO_vidSetPinValue(LCD_CTRL_PORT,RS_PIN,High);

	DIO_vidSetPinValue(LCD_CTRL_PORT,RW_PIN,Low);

	DIO_vidSetPinValue(LCD_CTRL_PORT,E_PIN,High);

	DIO_vidSetPortValue(LCD_DATA_PORT,u8DataCpy);

	DIO_vidSetPinValue(LCD_CTRL_PORT,E_PIN,Low);

	_delay_ms(5);

	DIO_vidSetPinValue(LCD_CTRL_PORT,E_PIN,High);

}

void LCD_vidWriteNumber(u16 u16NumCpy)
{
	u8 u8LocVar;

	if(u16NumCpy >= 10000)
	{
		u8LocVar = (u8)(u16NumCpy / (u16)10000);
		LCD_vidWriteChar(u8LocVar+48);

		u16NumCpy = u16NumCpy - (u16)(u8LocVar * (u16)10000);

		u8LocVar = (u8)(u16NumCpy / (u16)1000);
		LCD_vidWriteChar(u8LocVar+48);

		u16NumCpy = u16NumCpy - (u16)(u8LocVar * (u16)1000);

		u8LocVar = (u8)(u16NumCpy / (u16)100);
		LCD_vidWriteChar(u8LocVar+48);

		u16NumCpy = u16NumCpy - (u16)(u8LocVar * (u16)100);

		u8LocVar = (u8)(u16NumCpy / (u16)10);
		LCD_vidWriteChar(u8LocVar+48);

		u16NumCpy = u16NumCpy - (u16)(u8LocVar * (u16)10);

		LCD_vidWriteChar((u8)(u16NumCpy + 48));
	}
	else if(u16NumCpy >= 1000)
	{
		u8LocVar = (u8)(u16NumCpy / (u16)1000);
		LCD_vidWriteChar(u8LocVar+48);

		u16NumCpy = u16NumCpy - (u16)(u8LocVar * (u16)1000);

		u8LocVar = (u8)(u16NumCpy / (u16)100);
		LCD_vidWriteChar(u8LocVar+48);

		u16NumCpy = u16NumCpy - (u16)(u8LocVar * (u16)100);

		u8LocVar = (u8)(u16NumCpy / (u16)10);
		LCD_vidWriteChar(u8LocVar+48);

		u16NumCpy = u16NumCpy - (u16)(u8LocVar * (u16)10);

		LCD_vidWriteChar(u16NumCpy+48);
	}
	else if(u16NumCpy >= 100)
	{
		u8LocVar = (u8)(u16NumCpy / (u16)100);
		LCD_vidWriteChar(u8LocVar+48);

		u16NumCpy = u16NumCpy - (u16)(u8LocVar * (u16)100);

		u8LocVar = (u8)(u16NumCpy / (u16)10);
		LCD_vidWriteChar(u8LocVar+48);

		u16NumCpy = u16NumCpy - (u16)(u8LocVar * (u16)10);

		LCD_vidWriteChar(u16NumCpy+48);
	}
	else if(u16NumCpy >= 10)
	{
		u8LocVar = (u8)(u16NumCpy / (u16)10);
		LCD_vidWriteChar(u8LocVar+48);

		u16NumCpy = u16NumCpy - (u16)(u8LocVar * (u16)10);

		LCD_vidWriteChar(u16NumCpy+48);
	}
	else
	{
		LCD_vidWriteChar(u16NumCpy+48);
	}
}
