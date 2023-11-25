/********************************************/
/* Description : SysTick_timer */
/* Author      : sara hossny         */
/* Date        : 9/8/2023                  */
/* Version     : 0.1V                       */
/********************************************/
 /* Gaurd */
#ifndef  SysTick_timer_H 
#define  SysTick_timer_H
#include "STD_Types.h"
typedef enum {
Enable,
Disable
}state;
typedef enum {
AHB_div_8,
AHB
}SysTickCLK;
tenuErrorStatus SYStickstate_Enu(state copyenustate );
tenuErrorStatus SYStickIntCfg_Enu(state copyenuIntState );
tenuErrorStatus SYStickCLKCfg_Enu(SysTickCLK copyenuClk );
/*Reload value must be between 0x00000001-0x00FFFFFF */
tenuErrorStatus SYStickReloadValue_Enu(uint32 copyu32ReloadValue );
void SYStickGetCurrentValue_u32ptr(uint32* u32ReloadValue );
tenuErrorStatus SYStickIntialization_Enu(state copyenustate,state copyenuIntState,SysTickCLK copyenuClk ,uint32 copyu32ReloadValue  );
void SYStickDelayms(uint32 copyu32DelayValue);


#endif