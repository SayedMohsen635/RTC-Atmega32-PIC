/*
 * Interrupts.h
 *
 * Created: 9/13/2022 1:23:42 PM
 *  Author: sayed
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_
#define ISC00   0
#define ISC01   1
#define INT0    6
#define INTF0   6

/************************************************************************/
/*                          Interrupt Vectors                           */
/************************************************************************/

/* External Interrupt Vectors */

/* External Interrupt Request 0 */
#define EXT_INT_0			__vector_1
/* External Interrupt Request 1 */
#define EXT_INT_1			__vector_2
/* External Interrupt Request 2 */
#define EXT_INT_2			__vector_3
/* Timer/Counter0 Overflow */
#define TIMER0_OVF_vect		__vector_11
/* Timer/Counter0 Compare Match */
#define TIMER0_COMP_vect	__vector_10

/* Set Global Interrupt (I-Bit) in status register */
#define sei() __asm__ __volatile__("sei" ::: "memory")

/* Clear Global Interrupt (I-Bit) in status register */
#define cli() __asm__ __volatile__("cli" ::: "memory")

/* ISR Definition */
#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal , used));\
void INT_VECT(void)

#endif /* INTERRUPTS_H_ */