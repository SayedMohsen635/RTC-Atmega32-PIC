/*
 * stdMacros.h
 *
 * Created: 7/17/2022 7:05:54 PM
 *  Author: Sayed
 */ 


#ifndef STDMACROS_H_
#define STDMACROS_H_

#define REGISTER_SIZE 8
#define SET_BIT(reg , bit)    reg |= (1 << bit)
#define CLR_BIT(reg , bit)    reg &= ~(1 << bit)
#define TOG_BIT(reg , bit)    reg ^= (1 << bit)
#define READ_BIT(reg , bit)   ((reg & (1 << bit)) >> bit)
#define IS_BIT_SET(reg , bit) ((reg & (1 << bit)) >> bit)
#define IS_BIT_CLR(reg , bit) !((reg & (1 << bit)) >> bit)
#define ROR(reg , num)		  reg = (reg << (REGISTER_SIZE - num)) | (reg >> num)
#define ROL(reg , num)		  reg = (reg >> (REGISTER_SIZE - num)) | (reg << num)

#endif /* STDMACROS_H_ */