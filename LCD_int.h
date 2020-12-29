
#ifndef LCD_INT_H_
#define LCD_INT_H_

#define LCD_CLR          0x01

#define LCD_ENTRYMODE    0x06
#define LCD_DISPON_BLINK 0x0F

#define LCD_FUNCSET      0x3C

#define LCD_LINE1_LOC0   0x80
#define LCD_LINE1_LOC1   0x81
#define LCD_LINE1_LOC2   0x82
#define LCD_LINE1_LOC3   0x83
#define LCD_LINE1_LOC4   0x84
#define LCD_LINE1_LOC5   0x85
#define LCD_LINE1_LOC6   0x86
#define LCD_LINE1_LOC7   0x87
#define LCD_LINE1_LOC8   0x88
#define LCD_LINE1_LOC9   0x89
#define LCD_LINE1_LOC10  0x8A
#define LCD_LINE1_LOC11  0x8B
#define LCD_LINE1_LOC12  0x8C
#define LCD_LINE1_LOC13  0x8D
#define LCD_LINE1_LOC14  0x8E
#define LCD_LINE1_LOC15  0x8F

#define LCD_LINE2_LOC0   0xC0
#define LCD_LINE2_LOC1   0xC1
#define LCD_LINE2_LOC2   0xC2
#define LCD_LINE2_LOC3   0xC3
#define LCD_LINE2_LOC4   0xC4
#define LCD_LINE2_LOC5   0xC5
#define LCD_LINE2_LOC6   0xC6
#define LCD_LINE2_LOC7   0xC7
#define LCD_LINE2_LOC8   0xC8
#define LCD_LINE2_LOC9   0xC9
#define LCD_LINE2_LOC10  0xCA
#define LCD_LINE2_LOC11  0xCB
#define LCD_LINE2_LOC12  0xCC
#define LCD_LINE2_LOC13  0xCD
#define LCD_LINE2_LOC14  0xCE
#define LCD_LINE2_LOC15  0xCF


void LCD_vidInit(void);

void LCD_vidWriteCommand(u8 u8CmdCpy);

void LCD_vidWriteChar(u8 u8DataCpy);



void LCD_vidWriteNumber(u16 u16NumCpy);

#endif /* LCD_INT_H_ */
