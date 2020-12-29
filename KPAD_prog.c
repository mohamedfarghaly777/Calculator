


#include "LIB/STD_TYPES.h"
#include "KPAD_int.h"
#include "DIO_int.h"
#include "KPAD_cfg.h"

#define F_CPU 8000000UL
#include "avr/delay.h"

u8 KPAD_au8ColPins[4] = {Pin0,Pin1,Pin2,Pin3};
u8 KPAD_au8RowPins[4] = {Pin4,Pin5,Pin6,Pin7};

/************* KeyPad Key Index ***************/
/*         Col_0    Col_1   Col_2   Col_3     */
/*	                                          */
/* row_0      7        8       9      /      */
/*	                                          */
/* row_1  	  4        5       6       *      */
/*	                                          */
/* row_2	  1        2      3        -     */
/*	                                          */
/* row_3	  clc       0      =      +    */
/**********************************************/

/* 0x0D clc
 *
 *= 0x0f
 *+ 0x04
 *+ 0x08
 *+ 0x0c
 *+ 0x10
 */



u8 KPAD_au8SwitchVal[4][4] =
{
		/* COL 0 */
		{
				0x07,
				0x04,
				0x01,
				0x0D
		},
		/* COL 1 */
		{
				0x08,
				0x05,
				0x02,
				0x00
		},
		/* COL 2 */
		{
				0x09,
				0x06,
				0x03,
				0x0F
		},
		/* COL 3 */
		{
				0x10,
				0x0C,
				0x0B,
				0x0A
		}
};
void KPAD_vidInit(void)
{
	DIO_vidSetPortValue(KPAD_PORT,High);
}

u8 KPAD_u8GetPressedKey(void)
{
	u8 u8ColLoop,u8RowLoop;
	/* Initialize the return value with no key pressed */
	u8 u8RetVal = KPAD_NOKEY_PRESSED;
	/* Loop on all column pins to activate and read the row pins */
	for(u8ColLoop = 0; u8ColLoop < 4 ; u8ColLoop++)
	{
		/* Activate the column */
		DIO_vidSetPinValue(KPAD_PORT,KPAD_au8ColPins[u8ColLoop],Low);
		/* Loop on Row pins to check key pressed */
		for(u8RowLoop = 0; u8RowLoop < 4 ; u8RowLoop++)
		{
			/* Check if current Key pressed */
			if(DIO_u8GetPinValue(KPAD_PORT,KPAD_au8RowPins[u8RowLoop]) == Low)
			{
				/* Set return value with the pressed key index */
				u8RetVal = KPAD_au8SwitchVal[u8ColLoop][u8RowLoop];
				/* Wait until the switch is released */
				while(DIO_u8GetPinValue(KPAD_PORT,KPAD_au8RowPins[u8RowLoop]) == Low)
					;
				/* Delay to avoid bouncing */
				_delay_ms(50);
			}
			else
			{
				/* No Switch pressed Do Nothing */
			}
		}
		/* Deactivate the column */
		DIO_vidSetPinValue(KPAD_PORT,KPAD_au8ColPins[u8ColLoop],High);
	}
	/* Return Key index pressed */
	return u8RetVal;
}
