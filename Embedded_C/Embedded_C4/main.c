/*
	BY   : ENG. Ahmed ELgazzar
	DATE : 6/8/2022
*/
#include"platform_types.h"

#define SYSCTL_RCGC2_R	    (*((vu32 *)0x400FE108))	
#define GPIO_PORTF_DIR_R	(*((vu32 *)0X40025400))	
#define GPIO_PORTF_DEN_R	(*((vu32 *)0X4002551C))	
#define GPIO_PORTF_DATA_R	(*((vu32 *)0X400253FC))

void main()
{
	vu32 delay;
	SYSCTL_RCGC2_R = 0x20;
	//delay to set gpio upand running
	for (delay = 0;delay < 200;delay++);
	GPIO_PORTF_DIR_R |= (1<<3);
	GPIO_PORTF_DEN_R |= (1<<3);
	while(1)
	{
		GPIO_PORTF_DATA_R |= (1<<3);
		for (delay = 0;delay < 200000;delay++);
		GPIO_PORTF_DATA_R &= ~(1<<3);
		for (delay = 0;delay < 200000;delay++);
	}
}	