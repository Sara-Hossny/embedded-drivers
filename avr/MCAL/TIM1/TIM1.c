#include "STD_Types.h"
#include "BIT_Math.h"

#include "TIM1.h"
#include "TIM1_cfg.h"
#include "TIM1_priv.h"

pf TIM1_pfCtcCallback ;
pf TIM1_pfOvfCallback ;

void TIM1_voidInit(void)
{

 TCNT0 = 0;
 OCR0  = 0;
 /* Disable Interrupt  OVF CM */
 CLR_BIT(TIMSK , 0) ;
 CLR_BIT(TIMSK , 1) ;
 /* Clear IF flags OVF CM */
 SET_BIT(TIFR  , 0) ;
 SET_BIT(TIFR  , 1) ;

}

void TIM1_voidEnableOVFIntterrupt(void)
{
	SET_BIT(TIMSK , 0) ;
}
void TIM1_voidDisableOVFIntterrupt(void)
{
	CLR_BIT(TIMSK , 0) ;
}
void TIM1_voidEnableCTCIntterrupt(void)
{
		SET_BIT(TIMSK , 1) ;
}
void TIM1_voidDisableCTCIntterrupt(void)
{

	CLR_BIT(TIMSK , 1) ;
}
void TIM1_voidSetOvfCallback(pf pfOvfCallbackCpy)
{
	TIM1_pfOvfCallback = pfOvfCallbackCpy ;
}
void TIM1_voidSetCtcCallback(pf pfCtcCallbackCpy)
{
	TIM1_pfCtcCallback = pfCtcCallbackCpy;
}
/*OVF ISR*/
void __vector_11 (void) __attribute__((signal ,used));
void __vector_11 (void)
{
	TIM1_pfOvfCallback();
}
/*CM ISR*/
void __vector_10 (void) __attribute__((signal ,used));
void __vector_10 (void)
{
   TIM1_pfCtcCallback();
}
void TIM1_voidDelayMs(uint16 u16DalayTimeCpy)
{
}
