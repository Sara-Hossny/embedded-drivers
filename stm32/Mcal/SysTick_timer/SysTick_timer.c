/********************************************/
/* Description : SysTick_timer 						*/
/* Author      : sara hossny         		*/
/* Date        : 9/8/2023                   */
/* Version     : 0.1V                       */
/********************************************/
#include "STD_Types.h"
#include "BIT_Math.h"
#include "SysTick_timer_PRIV.h"
#include "SysTick_timer_CONFG.h"
#include "SysTick_timer.h"
tenuErrorStatus SYStickstate_Enu(state copyenustate ){
	if((copyenustate==Enable)||(copyenustate==Disable)){
	CLR_BIT(SysTick_timer->STK_CTRL , 0) ;
	SysTick_timer->STK_CTRL|=copyenustate;
	return E_OK;}
	return E_NOK_CONFIG_PARM_ERROR;
}
tenuErrorStatus SYStickIntCfg_Enu(state copyenuIntState ){
	if((copyenuIntState==Enable)||(copyenuIntState==Disable)){
	CLR_BIT(SysTick_timer->STK_CTRL , 1) ;
	SysTick_timer->STK_CTRL|=copyenuIntState>>1;
	return E_OK;}
	return E_NOK_CONFIG_PARM_ERROR;
}
tenuErrorStatus SYStickCLKCfg_Enu(SysTickCLK copyenuClk ){
	if((copyenuClk==AHB_div_8)||(copyenuClk==AHB)){
	CLR_BIT(SysTick_timer->STK_CTRL , 2) ;
	SysTick_timer->STK_CTRL|=copyenuClk>>2;
	return E_OK;}
	return E_NOK_CONFIG_PARM_ERROR;
}
tenuErrorStatus SYStickReloadValue_Enu(uint32 copyu32ReloadValue ){
	if(copyu32ReloadValue>0 && copyu32ReloadValue<0x01000000){
	SysTick_timer->STK_LOAD=copyu32ReloadValue;
	return E_OK;}
	return E_NOK_CONFIG_PARM_ERROR;
}
void SYStickGetCurrentValue_u32ptr(uint32* u32ReloadValue ){
	*u32ReloadValue=SysTick_timer->STK_VAL;
	
}
tenuErrorStatus SYStickIntialization_Enu(state copyenustate,state copyenuIntState,SysTickCLK copyenuClk ,uint32 copyu32ReloadValue  ){
	tenuErrorStatus local_state ;
	SYStickstate_Enu(Disable);
	local_state=SYStickReloadValue_Enu(copyu32ReloadValue);
	if(local_state==E_OK){
	SysTick_timer->STK_VAL=0;
	SYStickstate_Enu(Enable);
	return local_state;}
	return	E_NOK_CONFIG_PARM_ERROR ;
}
void SYStickDelayms(uint32 copyu32DelayValue){
	SYStickstate_Enu(Disable);
	switch ((SysTick_timer->STK_CTRL & 0X4) ){
		case 0 :
		SYStickReloadValue_Enu(2000*copyu32DelayValue);
		SysTick_timer->STK_VAL=0;
		SYStickstate_Enu(Enable);
		break ;
		case 1 :
		SYStickReloadValue_Enu(16000*copyu32DelayValue);
		SysTick_timer->STK_VAL=0;
		SYStickstate_Enu(Enable);
		break;
		default:
		break;
	}
}
