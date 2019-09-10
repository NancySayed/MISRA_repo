/*
 * KEYPAD.c
 *
 * Created: 30/01/2016 06:38:37 م
 *  Author: hossam
 */ 
#include "DIO.h"

/*Local Symbols*/
#define KPD_COL_PORT (PD)
#define KPD_ROW_PORT (PD)
#define KPD_COL_MASK ((u8) 0x70)
#define KPD_ROW_MASK ((u8) 0x0f)
#define KPD_COL_PIN_NUM 4u
#define KPD_ROW_PIN_NUM 0u

#define KPD_0xff    ( (u8) 0xff)
#define KPD_0x00    ( (u8) 0x00)
#define VALUE_0     ( (u8) 0)
#define VALUE_4     ( (u8) 4)
#define VALUE_3     ( (u8) 3)
#define VALUE_1     ( (u8) 1)
#define VALUE_2     ( (u8) 2)



/**************************************************/
void KPD_COL_READ(u8 *VALPTR);
void KPD_ROW_WRITE(u8 DATA);
void KPD_Init(void);
void KPD_COL_INIT(void);
void KPD_ROW_INIT(void);
void KPD_ReadVal(u8* ValuePtr);



void KPD_ROW_INIT(void)
{
    DIO_InitPortDirection(KPD_ROW_PORT, KPD_0xff , KPD_ROW_MASK);
    DIO_WritePort(KPD_ROW_PORT,KPD_0x00, KPD_ROW_MASK);
}

void KPD_COL_INIT(void)
{
    DIO_InitPortDirection(KPD_COL_PORT,KPD_0x00, KPD_COL_MASK);
}

void KPD_COL_READ(u8 *VALPTR)
{
    *(VALPTR)= DIO_ReadPort(KPD_COL_PORT,KPD_COL_MASK);
    *(VALPTR) = (*(VALPTR)) >> KPD_COL_PIN_NUM;
}

void KPD_ROW_WRITE(u8 DATA)
{
    DIO_WritePort(KPD_ROW_PORT,((DATA) << KPD_ROW_PIN_NUM), KPD_ROW_MASK);
}
 

void KPD_Init(void)
{
	KPD_COL_INIT();
	KPD_ROW_INIT();
	
}
void KPD_ReadVal(u8* ValuePtr)
{
    const u8 KeysLut[]= {'1' , '2' , '3' , '4' , '5' , '6','7' , '8' , '9','*' , '0' , '#'};
    u8 Rowdata;
    u8 ColData;
    u8 LoopTermnate = 0;
	for(Rowdata = VALUE_0 ; (Rowdata <  VALUE_4) && (LoopTermnate == VALUE_0) ; Rowdata ++)
	{
		KPD_ROW_WRITE((VALUE_1<<Rowdata));
		KPD_COL_READ(&ColData);
		if(ColData != VALUE_0)
		{
		    u8 index= (Rowdata*VALUE_3) + (ColData/VALUE_2);
			*ValuePtr = KeysLut[index];
			LoopTermnate = VALUE_1;
		}
		else
		{
			*ValuePtr = (u8) 'n';
		}
	}

	
	
}

