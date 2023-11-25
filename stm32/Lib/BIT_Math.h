/********************************************/
/* Description : bit manipulation STD lib   */
/* Author      : Sara hossny hassan           */
/* Date        : 9/8/2023    V0.1          */
/* Version     : 0.1V   Initial Creation    */
/********************************************/
#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(Reg , BitNum)   (Reg) |= (1<<(BitNum))  
#define CLR_BIT(Reg , BitNum)   (Reg) &=~(1<<(BitNum))
#define TGL_BIT(Reg , BitNum)   (Reg) ^= (1<<(BitNum))
#define GET_BIT(Reg , BitNum)   (((Reg) >> (BitNum))&0x01)
#define EDIT_VALUE(Reg ,value, mask ) (Reg) = value|(~mask&Reg)
#endif



