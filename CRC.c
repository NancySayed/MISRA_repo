#include "Basic_Types.h"

/***************************************************************************************/
#define VALUE_1                  ((u8) 1)
#define VALUE_2                  ((u8) 2)
#define VALUE_0                  ((u16) 0)
#define VALUE_0Xff               ((u8) 0xff)
#define VALUE_8                  ((u8) 8)
#define VALUE_7                  ((u8) 7)
#define VALUE_15                 ((u8) 15)
#define VALUE_16                 ((u8) 16)
#define internal_buffer_size                 ((u8) 8)



#define VALUE_0x10000            ((u32) 0x10000)
#define VALUE_0x18005            ((u32) 0x18005)
#define VALUE_0x8000             ((u16) 0x8000)
#define rand1                      ((u32)32768)
#define rand2                      ((u32)65536)


static u32 GetPower(u32 Base,u32 Pow);
static u16 gen_crc16(const u8 *data, u16 size, u32 CRC16);
void SECR_CrcPolynomialGenerate(u32* PolynomialPtr,u8 CrcLengthInBits);
void SECR_GnerateCrc(const u8* PayloadPtr,u16 PayloadLength, u16* CrcPtr, u32 CrcPoly);
u32 myrand(void);

/***************************************************************************************/

u32 myrand(void)  /* RAND_MAX assumed to be 32767. */
{
    static u32 next = 1;

    return((u32)(next/rand2) % rand1);
}



void SECR_CrcPolynomialGenerate(u32* PolynomialPtr,u8 CrcLengthInBits)
{
	u32 DevisorValue;
	DevisorValue = (u32)(GetPower((u32) VALUE_2, (u32) CrcLengthInBits)) - VALUE_1;
	*PolynomialPtr = ( myrand() % DevisorValue ) + VALUE_0x10000 ;
}
/***************************************************************************************/
void SECR_GnerateCrc(const u8* PayloadPtr,u16 PayloadLength, u16* CrcPtr, u32 CrcPoly)
{
	u16 LoopIndex;
	static u8 InternalBuffer[8];
	/*Copying data to internal buffer*/
	for (LoopIndex = VALUE_0; LoopIndex < PayloadLength; LoopIndex ++)
	{
		InternalBuffer[LoopIndex] = PayloadPtr[LoopIndex];
	}
	/*perform bit wise invert on the data*/
	for (LoopIndex = VALUE_0; LoopIndex < PayloadLength; LoopIndex ++)
	{
		InternalBuffer[LoopIndex]  ^= VALUE_0Xff;
	}
	/*Generate CRC*/
	*CrcPtr = gen_crc16(InternalBuffer,PayloadLength*VALUE_8,VALUE_0x18005);
}
/***************************************************************************************/
static u32 GetPower(u32 Base,u32 Pow)
{
	u32 result = 1;
	u32 LoopIndex1;
	for (LoopIndex1 = (u32) VALUE_0; LoopIndex1 < Pow; LoopIndex1 ++)
	{
		result *= Base;
	}
	return result;
}
/***************************************************************************************/
static u16 gen_crc16(const u8 *data, u16 size, u32 CRC16)
{
	u16 out = VALUE_0;
	u16 bits_read = VALUE_0;
	u16 bit_flag;
	u16 i;
	u16 crc = VALUE_0;
	u16 j = 0x0001;
	u8 index=0;
	u8 *data_backup=*data;
	/* Sanity check: */
	if(data == ((u8) VALUE_0))
	{
	    return VALUE_0;
	}
	else
	{
        while(size > VALUE_0)
        {
            bit_flag = out >> VALUE_15;

            /* Get next bit: */
            out <<= (u16) VALUE_1;
            out |= ((u16) data[index] >> bits_read) & ((u16) VALUE_1); /* item a) work from the least significant bits*/

            /* Increment bit counter: */
            bits_read++;
            if(bits_read > VALUE_7)
            {
                bits_read = VALUE_0;
                index++;
                size--;
            }

            /* Cycle check: */
            if(bit_flag)
            {
                out ^= CRC16;
            }

        }

        /* item b) "push out" the last 16 bits*/

        for (i = VALUE_0; i < VALUE_16; ++i) {
            bit_flag = out >> VALUE_15;
            out <<= 1;
            if(bit_flag)
            {
                out ^= CRC16;
            }
        }

        /* item c) reverse the bits*/



        for (i = VALUE_0x8000; i != VALUE_0; i >>=1)
        {
            if (i && out)
                {
                    crc |= j;
                }
            j <<= 1;
        }

        return crc;
	}
}
/***************************************************************************************/
