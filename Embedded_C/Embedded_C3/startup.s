/*
Assembly startup for cortex-m3 project
	ENG :- Ahmed ELgazzar
	*/

/*SRAM 0x20000000*/

.section .vectors

.word 0x20001000            /*   Stack top address   */
 .word _reset               /*     1 Reset -> main   */  
 .word vector_handler      /*     2 NMI             */
 .word vector_handler      /*     3 Hard Fault      */
 .word vector_handler      /*     4 MM Fault        */
 .word vector_handler      /*     5 Bus Fault       */ 
 .word vector_handler      /*     6 Usage Fault     */ 
 .word vector_handler      /*     7 RESEVED         */
 .word vector_handler      /*     8 RESEVED         */
 .word vector_handler      /*     9 RESEVED         */
 .word vector_handler      /*    10 RESEVED         */
 .word vector_handler      /*    11 SV Call         */ 
 .word vector_handler      /*    12 Debug Reseved   */ 
 .word vector_handler      /*    13 RESEVED         */ 
 .word vector_handler      /*    14 PendSV          */  
 .word vector_handler      /*    15 sysTick         */  
 .word vector_handler      /*    16 IRQ0            */ 
 .word vector_handler      /*    17 IRQ1            */ 
 .word vector_handler      /*    18 IRQ2            */ 
 .word vector_handler      /*    19 IRQ3            */ 
 .word vector_handler      /*    20 IRQ4            */ 
 .word vector_handler      /*    21 IRQ5            */ 
 .word vector_handler      /*    22 IRQ6            */ 
 .word vector_handler      /*    23 IRQ7            */  

.section .text

_reset:
	bl main
	b .

.thumb_func

vector_handler:
    b _reset


