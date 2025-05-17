/*
 * EXTI_private.h
 *
 * Created: 2/10/2025 1:54:54 PM
 *  Author: TUF
 */ 


#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_


#define GICR *((volatile u8*)(0x5B))
#define GIFR *((volatile u8*)(0x5A))
#define MCUCR *((volatile u8*)(0x55))
#define MCUCSR *((volatile u8*)(0x54))

#define ISC11 3
#define ISC10 2
#define ISC01 1
#define ISC00 0

#define ISC2  6

#define INT1 7
#define INT0 6
#define INT2 5

#define INTF1 7
#define INTF0 6
#define INTF2 5

#define BIT_MUSK 3

#endif /* EXTI_PRIVATE_H_ */