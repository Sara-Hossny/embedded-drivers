/********************************************/
/* Description : RCC 						*/
/* Author      : sara hossny         		*/
/* Date        : 9/8/2023                   */
/* Version     : 0.1V                       */
/********************************************/
#include "STD_Types.h"
#include "BIT_Math.h"
#include "RCC_PRIV.h"
#include "RCC_CONFG.h"
#include "RCC.h"
void RCC_VoidInit (void){
	#if RCC_SYS== RCC_HSI
		SET_BIT(RCC->RCC_CR , RCC_HSI);
		while(GET_BIT(RCC->RCC_CR, 1)!=1);
		CLR_BIT(RCC->RCC_CFGR , 0); 
		CLR_BIT(RCC->RCC_CFGR , 1); 
		while((RCC->RCC_CFGR&&0x0c) != 0x00);
	#elif RCC_SYS== RCC_HSE
		#if (RCC_HSE_TYPE==HSE_BYPASS)
			SET_BIT(RCC->RCC_CR , 18);
		#elseif (RCC_HSE_TYPE==HSE_NOTBYPASS)
			CLR_BIT(RCC->RCC_CR , 18); 
		#else
			#error "wrong configaration "
		#endif
		SET_BIT(RCC->RCC_CR , RCC_HSE);
		while(GET_BIT(RCC->RCC_CR, 17)!=1);
		SET_BIT(RCC->RCC_CFGR , 0); 
		CLR_BIT(RCC->RCC_CFGR , 1); 
		while(RCC->RCC_CFGR&&0x0c != 0x01);
	#elif (RCC_SYS== RCC_PLL) 
		#if RCC_PLL_SCR==RCC_HSI
			SET_BIT(RCC->RCC_CR , RCC_HSI);
			while(GET_BIT(RCC->RCC_CR, 1)!=1);
			CLR_BIT(RCC->RCC_PLLCFGR , 22); 
		#elif RCC_PLL_SCR==RCC_HSE
			#if (RCC_HSE_TYPE==HSE_BYPASS)
				SET_BIT(RCC->RCC_CR , 18);
			#elif (RCC_HSE_TYPE==HSE_NOTBYPASS)
				CLR_BIT(RCC->RCC_CR , 18); 
			#else
				#error "wrong configaration "
			#endif
			SET_BIT(RCC->RCC_CR , RCC_HSE);
			while(GET_BIT(RCC->RCC_CR, 17)!=1);
		#endif
			SET_BIT(RCC->RCC_PLLCFGR , 22); 
			
		EDIT_VALUE(RCC->RCC_PLLCFGR ,(~(RCC_PLLN<<6 |RCC_PLLP|RCC_PLLM)),0xF00037FFF );
		SET_BIT(RCC->RCC_CR , RCC_PLL);
		while(GET_BIT(RCC->RCC_CR, 17)!=1);
		SET_BIT(RCC->RCC_CFGR , 1);
		CLR_BIT(RCC->RCC_CFGR , 0);
		while(RCC->RCC_CFGR&&0x0c != 0x10);		
	#else
		#error("configation is wrong")
	#endif 
	
}
void RCC_VoidEnablePeripheral(uint8 copyu8PerNumber ,uint8 copyu8BusNumber ){
	switch(copyu8BusNumber){
		case(RCC_AHB1):
		SET_BIT(RCC->RCC_AHB1ENR,copyu8PerNumber);
		break;
		case(RCC_AHB2):
		SET_BIT(RCC->RCC_AHB2ENR,copyu8PerNumber);
		break;
		case(RCC_APB1):
		SET_BIT(RCC->RCC_APB1ENR,copyu8PerNumber);
		break;
		case(RCC_APB2):
		SET_BIT(RCC->RCC_APB2ENR,copyu8PerNumber);
		break;
				
		
	}
	
	
}
