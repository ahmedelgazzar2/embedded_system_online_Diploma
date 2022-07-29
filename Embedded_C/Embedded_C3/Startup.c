/*****************ENG:- Ahmed ELgazzar**********/

#include"platorm_types.h"

extern void main();
extern u32 stack_top ;
extern u32 _E_text ;
extern u32 _S_data ;
extern u32 _E_data ;
extern u32 _S_bss ;
extern u32 _E_bss ;
void reset_handler();
void default_handler();
void nmi_handler()__attribute__((weak,alias("default_handler")));
void hw_fault_handler()__attribute__((weak,alias("default_handler")));
void mm_fault_handler()__attribute__((weak,alias("default_handler")));
void bus_fault_handler()__attribute__((weak,alias("default_handler")));
void usage_fault_handler()__attribute__((weak,alias("default_handler")));

uint32 vectors[] __attribute__((section(".vectors")))=
{
(uint32)&stack_top	,
(uint32)&reset_handler,
(uint32)&nmi_handler	,
(uint32)&hw_fault_handler	,
(uint32)&mm_fault_handler	,
(uint32)&bus_fault_handler	,
(uint32)&usage_fault_handler	,	
};

void reset_handler()
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
void default_handler()
{
	reset_handler();