/*
 * keypad.h
 *
 * Created: 4/22/2021 6:32:00 PM
 *  Author: Marco
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_


#include"MemMap.h"
#include<util/delay.h>


#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define C0 4
#define C1 5
#define C2 6
#define C3 7

#define KEYPAD_PORT PORTD
#define DataDir_KEYPAD_PORT DDRD
#define keypadPIN PIND

void Keypad_init();
char Keypad_getkey();

#endif /* KEYPAD_H_ */
