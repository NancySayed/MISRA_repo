/*
 * BLMGR_CFG.c
 *
 * Created: 28/02/2016 06:54:45 م
 *  Author: hossam
 */ 
#include "DIO.h"
#include "BLMGR_CFG.h"
#define pin1    ( (u8) 4 )
#define pin2    ( (u8) 5 )
#define pin3    ( (u8) 2 )
#define shift   ( (u8) 1 )

BLMGR_DioPinConfig BuzzerConfig      = {(u8) PC, shift<<pin1};
BLMGR_DioPinConfig BlueToothPwrConfig = {(u8) PC,shift<<pin2};
BLMGR_DioPinConfig BluetoothKeyConfig = {(u8) PD,shift<<pin3};
	
