


#include "Basic_Types.h"
#include "BLMGR.h"


#include "PWM.h"
#include "GPT.h"

#define VALUE_10    ( (u8) 10 )
#define VALUE_0     ( (u8)  0 )
#define VALUE_25    ( (u8) 25 )
#define VALUE_4     ( (u8) 4  )
#define VALUE_5     ( (u8) 5  )
#define VALUE_1     ( (u8) 1  )
#define VALUE_20    ( (u8) 20 )
#define VALUE_100   ( (u8) 100)

void Cyclic30ms(void);
void main(void);
void _delay_ms(u8 delay);
void sei(void);


void main(void)
{
    u16 Count= VALUE_0;
	u16 start = VALUE_0;
	u16 Count2 = VALUE_0;
 


	Cyclic30ms();
	
	BLMGR_BluetoothInit();
	BLMGR_SetReceiver( (u8) ROLE_MAPP);
    
							
	PWM_Init();
	sei();
	PWM_SetSpeed(VALUE_25);

	
	while(1)
	{
		Count2 = (Count2 +VALUE_1) %VALUE_20;
		BLMGR_SetBattLevel( (u8) Count2 / VALUE_4);
		
		_delay_ms(VALUE_100);
		Count ++;
		if(start == VALUE_0)
		{
					if(Count > VALUE_5)
					{
						BLMGR_StartDevice();

						start = VALUE_1;
					}
					
		}

	    
		
		
	}
	
	
}


void Cyclic30ms(void)
{
    static u8 TimeoutCounter = VALUE_0;
    TimeoutCounter ++;
    if(TimeoutCounter == VALUE_10)
    {
        BLMGR_BluetoothStateMachine();
        TimeoutCounter = VALUE_0;


    }
}


