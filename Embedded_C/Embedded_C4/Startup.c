/*****************ENG:- Ahmed ELgazzar**********/

#include"platform_types.h"

extern void main();
//extern u32 stack_top ;
void Default_Handler();
void Reset_Handler();
void NMI_Handler() __attribute__((weak, alias("Default_Handler")));
void H_falut_Handler() __attribute__((weak, alias("Default_Handler")));
static u32 stack_top[256];//256 * 4 = 1024 byte.



void(*const vectors[])() __attribute__((section(".vector"))) =
{
	(void(*)()) ((u32)stack_top+sizeof(stack_top)),
	&Reset_Handler,
	&NMI_Handler,
	&H_falut_Handler
};

extern u32 _E_text ;
extern u32 _S_data ;
extern u32 _E_data ;
extern u32 _S_bss ;
extern u32 _E_bss ;

void Reset_Handler()
{
	int i;
	u32 data_size =(u8 *)&_E_data-(u8 *)&_S_data ;
	u32 bss_size  =(u8 *)&_E_bss-(u8 *)&_S_bss ;
	u8 * p_src=(u8 *)&_E_text ;
	u8 * p_dst=(u8 *)&_S_data ; 	
	for(i=0;i<data_size;i++,p_dst++,p_src++)
	{
		*p_dst=*p_src;
		
	}
	p_dst=(u8 *)&_S_bss ;
	for(i=0;i<data_size;i++,p_dst++)
	{
		*p_dst=(u8)0;
		
	}
	main();
}
	
void Default_Handler()
{
	Reset_Handler();
}