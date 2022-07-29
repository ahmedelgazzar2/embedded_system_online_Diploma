/*
	linker script to cortex-m3
	by ENG :- Ahmed ELgazzar
*/

MEMORY
{
    
  FLASH(RX): ORIGIN = 0X08000000 , LENGTH = 128K
  SRAM(RWX): ORIGIN = 0X20000000 , LENGTH = 20K

}

SECTIONS
{

    .text : 
    {
       *(.vectors*)
       *(.text*)
       *(.rodata)
	   _E_text = .;
    }> FLASH
	
    .data : 
    { 
		_S_data = .;
       *(.data)
		_E_data = .;
		. = ALIGN(4);
    }> SRAM AT>flash
	
    .bss :
    {
       _S_bss = .;
       *(.bss)
		_E_bss = .;
    }> SRAM
	
   .comment :
   {

     *(.comment) *(COMMON)

   }> FLASH
   
}

