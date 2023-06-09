/* Entry Point */
ENTRY(_start)

/* define heap and stack size */
__HEAP_SIZE            = 0 ;
__STACK_SIZE           = 4096 ;

SRAM_SIZE =  256K;    
/* Define SRAM Base Address */
SRAM_BASE_ADDR = 0x40000000;
  
/* Define CPU1 Local Instruction SRAM Allocation */  
LOCALIMEM_SIZE = 16K;
/* Define CPU1 Local Instruction SRAM Base Address */
LOCALIMEM_BASE_ADDR = 0x51000000;

/* Define CPU1 Local Data SRAM Allocation */
LOCALDMEM_SIZE = 32K;
/* Define CPU1 Local Data SRAM Base Address */
LOCALDMEM_BASE_ADDR = 0x51800000;
        
MEMORY
{
    SRAM :	org = 0x40000000,   len = 96K
    
    local_imem  : org = 0x51000000,   len = 16K
    local_dmem  : org = 0x51800000,   len = 32K   
}


SECTIONS
{

    .startup : ALIGN(0x400)
    {
    __start = . ;
    	*(.startup)
    } > SRAM
    
    .core_exceptions_table   : ALIGN(4096)
    {
      __IVPR_VALUE = . ;
      KEEP(*(.core_exceptions_table))
    } > SRAM

    .intc_vector_table   : ALIGN(4096)
    {
      KEEP(*(.intc_vector_table))
    } > SRAM
      
    .text : 
    {
      *(.text.startup)
      *(.text)      
      *(.text.*)
      KEEP (*(.init))
      KEEP (*(.fini))            
      . = ALIGN(16);
    } > SRAM
      
    .ctors :
    {
      __CTOR_LIST__ = .;
      /* gcc uses crtbegin.o to find the start of
         the constructors, so we make sure it is
         first.  Because this is a wildcard, it
         doesn't matter if the user does not
         actually link against crtbegin.o; the
         linker won't look for a file to match a
         wildcard.  The wildcard also means that it
         doesn't matter which directory crtbegin.o
         is in.  */
      KEEP (*crtbegin.o(.ctors))
      KEEP (*crtbegin?.o(.ctors))
      /* We don't want to include the .ctor section from
         from the crtend.o file until after the sorted ctors.
         The .ctor section from the crtend file contains the
         end of ctors marker and it must be last */
      KEEP (*(EXCLUDE_FILE(*crtend?.o *crtend.o) .ctors))
      KEEP (*(SORT(.ctors.*)))
      KEEP (*(.ctors))
      __CTOR_END__ = .;
    } > SRAM

    .dtors :
    {
      __DTOR_LIST__ = .;
      KEEP (*crtbegin.o(.dtors))
      KEEP (*crtbegin?.o(.dtors))
      KEEP (*(EXCLUDE_FILE(*crtend?.o *crtend.o) .dtors))
      KEEP (*(SORT(.dtors.*)))
      KEEP (*(.dtors))
      __DTOR_END__ = .;
    } > SRAM
        
    .preinit_array :
    {
      PROVIDE_HIDDEN (__preinit_array_start = .);
      KEEP (*(.preinit_array*))
      PROVIDE_HIDDEN (__preinit_array_end = .);
    } > SRAM

    .init_array :
    {
      PROVIDE_HIDDEN (__init_array_start = .);
      KEEP (*(SORT(.init_array.*)))
      KEEP (*(.init_array*))
      PROVIDE_HIDDEN (__init_array_end = .);
    } > SRAM

    .fini_array :
    {
      PROVIDE_HIDDEN (__fini_array_start = .);
      KEEP (*(SORT(.fini_array.*)))
      KEEP (*(.fini_array*))
      PROVIDE_HIDDEN (__fini_array_end = .);
    } > SRAM
        
    .rodata :
    {
      *(.rodata)
      *(.rodata.*)
    } > SRAM
    
    .eh_frame_hdr : { *(.eh_frame_hdr) } > SRAM
    .eh_frame     : { KEEP (*(.eh_frame)) } > SRAM 
      
	.data   : 
	{
	  *(.data)
	  *(.data.*)
	}  > SRAM
    
    .sdata2  :
	{  
	  *(.sdata2)
	  *(.sdata2.*)
	} > SRAM

	.sbss2    (NOLOAD)   :
	{
      /* _SDA2_BASE_ = .; */ 
	  *(.sbss2)
	  *(.sbss2.*)
	} > SRAM
    
    .sdata  :
	{
	  *(.sdata)
	  *(.sdata.*)
	} > SRAM
    
	.bss   (NOLOAD)  :
	{
	  __BSS_START = .;
	  *(.sbss)
	  *(.sbss.*)	
      *(.bss)
      *(.bss.*)
      *(COMMON)
      __BSS_END = .;
    } > SRAM
    
    .stack (NOLOAD) : ALIGN(16) 
    {
      __HEAP = . ;
      PROVIDE (_end = . );
      PROVIDE (end = . );            
      . += __HEAP_SIZE ;
      __HEAP_END = . ;
      _stack_end = . ;
      . +=  __STACK_SIZE ;
      _stack_addr = . ;
      __SP_INIT = . ;
      . += 4;
    } > local_dmem
 
/*-------- LABELS USED IN CODE -------------------------------*/
        
/* Labels for Copying Initialised Data from Flash to RAM */
__DATA_SRAM_ADDR  = ADDR(.data);
__SDATA_SRAM_ADDR = ADDR(.sdata);

__DATA_SIZE   = SIZEOF(.data);
__SDATA_SIZE  = SIZEOF(.sdata);

__DATA_ROM_ADDR  = LOADADDR(.data);
__SDATA_ROM_ADDR = LOADADDR(.sdata);
   
/* Labels Used for Initialising SRAM ECC */
__SRAM_SIZE = SRAM_SIZE;
__SRAM_BASE_ADDR = SRAM_BASE_ADDR;
      
__LOCAL_DMEM_SIZE = LOCALDMEM_SIZE;
__LOCAL_DMEM_BASE_ADDR = LOCALDMEM_BASE_ADDR;

__LOCAL_IMEM_SIZE = LOCALIMEM_SIZE;
__LOCAL_IMEM_BASE_ADDR = LOCALIMEM_BASE_ADDR;

__BSS_SIZE    = __BSS_END - __BSS_START;  
      
}

