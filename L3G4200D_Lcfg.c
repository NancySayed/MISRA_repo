/*
 * L3G4200D_Lcfg.c
 *
 * Created: 27/09/2015 02:11:03 م
 *  Author: hossam
 */ 
#include "L3G4200D_Lcfg.h"
#include "Basic_Types.h"
#include "L3G4200D_Lcfg.h"
#include "L3G4200D.h"

#define     VALUE_1     ( (u8) 0x01 )

#if(u8TIMEOUT_FUNCTION == u8USE_DELAY)
void u8START_TIME_OUT_MS(u8 DELAY_MS, u8 * FLAG_PTR)
{
    _delay_ms(DELAY_MS);
     *(FLAG_PTR) = VALUE_1;
}
/*#define u8START_TIME_OUT_MS(DELAY_MS,FLAG_PTR) do { _delay_ms(DELAY_MS); *(FLAG_PTR) = 0x01 } while(0)*/
#else
#define u8START_TIME_OUT_MS(DELAY_MS,FLAG_PTR)
#endif


const L3G4200D_CfgType L3G4200D_ConfigParam = {
                                                u8FS_250,
                                                {u8X_AXIS_ACTIVE, u8Y_AXIS_ACTIVE, u8Z_AXIS_ACTIVE},
                                                {u8NO_FILTERS, u8NO_FILTERS},
                                                {0X2CA4, 0x2CA4, 0x2CA, u8INT1_X, u8INT1_Y, u8INT1_Z, 0x00 , 0x00 }
                                               };



/*
const L3G4200D_CfgType L3G4200D_ConfigParam = {
                                                u8FS_250,

                                               .strAxisActivation.u8XAxisActivation    = u8X_AXIS_ACTIVE,
											   .strAxisActivation.u8YAxisActivation    = u8Y_AXIS_ACTIVE,
											   .strAxisActivation.u8ZAxisActivation    = u8Z_AXIS_ACTIVE,

											   .strFilterCfg.u8FilterOnData            = u8NO_FILTERS,
											   .strFilterCfg.u8FilterOnInterrupt       = u8NO_FILTERS,

											   .strIntCfg.u16ThresholdX                = 0X2CA4,
											   .strIntCfg.u16ThresholdY                = 0x2CA4,
											   .strIntCfg.u16ThresholdZ                = 0x2CA,
											   .strIntCfg.u8XAxisInterrupt             = u8INT1_X,
											   .strIntCfg.u8YAxisInterrupt             = u8INT1_Y,
											   .strIntCfg.u8ZAxisInterrupt             = u8INT1_Z,
											   .strIntCfg.u8AOICfg                     = 0x00,
											   .strIntCfg.u8IntDuration                = 0x00
											   };

*/
