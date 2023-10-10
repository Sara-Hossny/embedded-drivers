/********************************************/
/* Description : SysTick_timer */
/* Author      : sara hossny        		*/
/* Date        : 9/8/2023                   */
/* Version     : 0.1V                       */
/********************************************/
#ifndef  SysTick_timer_PRIV_H 
#define  SysTick_timer_PRIV_H
#include "STD_Types.h"
typedef struct {
  volatile uint32  STK_CTRL;
  volatile uint32  STK_LOAD;
  volatile uint32  STK_VAL;
  volatile uint32  STK_CALIB;

}SysTick_timer_T ;
#define SysTick_timer_BASE 0xE000E010
#define SysTick_timer ((SysTick_timer_T *) SysTick_timer_BASE)

#endif 
