/*
 * L3G4200D_Cfg.h
 *
 * Created: 24/09/2015 09:13:50 م
 *  Author: hossam
 */ 


#ifndef L3G4200D_CFG_H_
#define L3G4200D_CFG_H_
#include "Basic_Types.h"
#include "DIO.h"
#include "SPI.h"

#define VALUE_4     ((u8) 4)
#define VALUE_1     ((u8) 1)




/*SPI Communication Configuration*/
#define GYHD_INIT_SLAVE_SELECT              do { DIO_InitPortDirection(PB,VALUE_1<<VALUE_4,VALUE_1<<VALUE_4); DIO_WritePort(PB,VALUE_1<<VALUE_4,VALUE_1<<VALUE_4)} while(0)
#define GYHD_ACTIVATE_SLAVE_SELECT          do { DIO_WritePort(PB,~(VALUE_1<<VALUE_4),VALUE_1<<VALUE_4)} while(0)
#define GYHD_DEACTIVATE_SLAVE_SELECT        do { DIO_WritePort(PB,(VALUE_1<<VALUE_4),(VALUE_1<<VALUE_4))} while (0)

/*Timeout Management Configuration*/
#define u8USE_DELAY (0x00)
#define u8USE_TIMER ((u8) 0x01)
#define u8TIMEOUT_FUNCTION (u8USE_DELAY)
/*Self Axis Movement Detection Config*/
#define u8SELF_AXIS_MOV  (ON)

void _delay_ms(u8 DELAY_MS);
void u8START_TIME_OUT_MS(u8 DELAY_MS, u8 *FLAG_PTR);


#endif /* L3G4200D_CFG_H_ */
