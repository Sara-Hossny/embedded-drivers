/********************************************/
/* file name : LED_priv.h                   */
/* Author      : sara hossny                */
/* Date        : 14/8/2023                  */
/* Version     : 0.1V                       */
/********************************************/
 /* Gaurd */
#ifndef LED_PRIV_H
#define LED_PRIV_H


#define LED_u8NORMAL    ((uint8) 0xAA)
#define LED_u8REVERSE   ((uint8) 0x55)
#define CONC_ENSURE(LED_u8NUM)          CONC_ENSURE_MARCO(LED_u8NUM)
#define CONC_ENSURE_MARCO(LED_u8NUM)    1##LED_u8NUM

typedef struct{
	uint8 u8GPIOPort;
	uint8 u8GPIOPinMap;
	uint8 u8LedModeConc;
}tstrPinMappingCfg ;

extern tstrPinMappingCfg LED_astrLedPinMapping[LED_MAX_NUM];



#endif
