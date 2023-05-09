/* Entry Point */
ENTRY(_start)

/* define heap and stack size */
__HEAP_SIZE            = 0 ;
__STACK_SIZE           = 4096 ;

SRAM_SIZE =  56K;    /*启动时仅初始化自身管理的存储区*/
/* Define SRAM Base Address */
SRAM_BASE_ADDR = 0x40030000;
  
/* Define CPU0 Local Instruction SRAM Allocation */  
LOCALIMEM_SIZE = 16K;
/* Define CPU0 Local Instruction SRAM Base Address */
LOCALIMEM_BASE_ADDR = 0x50000000;

/* Define CPU0 Local Data SRAM Allocation */
LOCALDMEM_SIZE = 32K;
/* Define CPU0 Local Data SRAM Base Address */
LOCALDMEM_BASE_ADDR = 0x50800000;
        
MEMORY
{

    flash_rchw : org = 0x00FA0000,   len = 0x4
    cpu0_reset_vec : org = 0x00FA0000+0x10,   len = 0x4
    cpu1_reset_vec : org = 0x00FA0000+0x14,   len = 0x4
        
    m_text :	org = 0x11c0000, len = 1792K  
    
    /*ENM模块数据区，同Core1对应*/
    history_ram1 :	org = 0x40018000,	len = 0x100	/*用于存储历史数据区 1 的ram区*/
    history_ram2 :	org = 0x40018100,	len = 0x400	/*用于存储历史数据区 2 的ram区*/

    /*ccp 标定区，同Core1对应*/
    ccp_acr_ram :	org = 0x40018500,  len = 0x3180 
    ccp_avas_ram :	org = 0x4001B680,  len = 0x80 
    ccp_chrg_ram :	org = 0x4001B700,  len = 0x100 
    ccp_dhp_ram :	org = 0x4001B800,  len = 0x600 
    ccp_dim_ram :	org = 0x4001BE00,  len = 0x1780 
    ccp_dom_ram :	org = 0x4001D580,  len = 0x980 
    ccp_dsi_ram :	org = 0x4001DF00,  len = 0x80 
    ccp_enm_ram :	org = 0x4001DF80,  len = 0x500 
    ccp_hali_ram :	org = 0x4001E480,  len = 0x280 
    ccp_nm_ram :	org = 0x4001E700,  len = 0x80 
    ccp_peps_ram :	org = 0x4001E780,  len = 0x100 
    ccp_pmm_ram :	org = 0x4001E880,  len = 0x100 
    ccp_scr_ram :	org = 0x4001E980,  len = 0xF00 
    ccp_tmm_ram :	org = 0x4001F880,  len = 0x600 
    ccp_tqfrate_ram :	org = 0x4001FE80,  len = 0xB00 
    ccp_tqm_ram :	org = 0x40020980,  len = 0x5B80 
    ccp_bsw_ram :	org = 0x40026500,  len = 0x80 
    ccp_btk_ram :	org = 0x40026580,  len = 0x80    /*add for btk*/

    m_data :	org = 0x40030000,   len = 56K
    
    m_init :    org = 0x4003E000,   len = 8K
    
    local_imem  : org = 0x50000000,   len = 16K
    local_dmem  : org = 0x50800000,   len = 32K   
}


SECTIONS
{
    .rchw   : 
    {
        KEEP(*(.rchw))
    } > flash_rchw

    .cpu0_reset_vector  : 
    {
        KEEP(*(.cpu0_reset_vector))
    } > cpu0_reset_vec

    .cpu1_reset_vector  : 
    {
        KEEP(*(.cpu1_reset_vector))
    } > cpu1_reset_vec

    /* Note: if you move the 'startup' section shall modify the RCHW2_0 value for the corresponding core in the flashrchw.c file. */
    .startup : ALIGN(0x400)
    {
    __start = . ;
    	*(.startup)
    } > m_text
    
    .core_exceptions_table   : ALIGN(4096)
    {
      __IVPR_VALUE = . ;
      KEEP(*(.core_exceptions_table))
    } > m_text

    .intc_vector_table   : ALIGN(4096)
    {
      KEEP(*(.intc_vector_table))
    } > m_text
      
    .text : 
    {
      *(.text.startup)
      *(.text)      
      *(.text.*)
      KEEP (*(.init))
      KEEP (*(.fini))            
      . = ALIGN(16);
    } > m_text
      
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
    } > m_text

    .dtors :
    {
      __DTOR_LIST__ = .;
      KEEP (*crtbegin.o(.dtors))
      KEEP (*crtbegin?.o(.dtors))
      KEEP (*(EXCLUDE_FILE(*crtend?.o *crtend.o) .dtors))
      KEEP (*(SORT(.dtors.*)))
      KEEP (*(.dtors))
      __DTOR_END__ = .;
    } > m_text
        
    .preinit_array :
    {
      PROVIDE_HIDDEN (__preinit_array_start = .);
      KEEP (*(.preinit_array*))
      PROVIDE_HIDDEN (__preinit_array_end = .);
    } > m_text

    .init_array :
    {
      PROVIDE_HIDDEN (__init_array_start = .);
      KEEP (*(SORT(.init_array.*)))
      KEEP (*(.init_array*))
      PROVIDE_HIDDEN (__init_array_end = .);
    } > m_text

    .fini_array :
    {
      PROVIDE_HIDDEN (__fini_array_start = .);
      KEEP (*(SORT(.fini_array.*)))
      KEEP (*(.fini_array*))
      PROVIDE_HIDDEN (__fini_array_end = .);
    } > m_text
          
    .rodata :
    {
      *(.rodata)
      *(.rodata.*)
    } > m_text
    
    .eh_frame_hdr : { *(.eh_frame_hdr) } > m_text
    .eh_frame     : { KEEP (*(.eh_frame)) } > m_text 
      
	.data   : 
	{
	  *(.data)
	  *(.data.*)
	}  > m_data AT>m_text
    
    .sdata2  :
	{  
	  *(.sdata2)
	  *(.sdata2.*)
	} > m_data AT>m_text

	.sbss2    (NOLOAD)   :
	{
      /* _SDA2_BASE_ = .; */ 
	  *(.sbss2)
	  *(.sbss2.*)
	} > m_data
    
    .sdata  :
	{
	  *(.sdata)
	  *(.sdata.*)
	} > m_data AT>m_text
    
	.bss   (NOLOAD)  :
	{
	  __BSS_START = .;
	  *(.sbss)
	  *(.sbss.*)	
      *(.bss)
      *(.bss.*)
      *(COMMON)
      __BSS_END = .;
    } > m_data
    /***************************/
    .history_unit1 : ALIGN(4)
    {
    	KEEP(*(.history_unit1))
    } > history_ram1 AT>m_text
    
    .history_unit2 : ALIGN(4)
    {
    	KEEP(*(.history_unit2))
    } > history_ram2 AT>m_text
    .ccp_acr_unit :	ALIGN(4)
    {
        KEEP(*(.ccp_acr_unit))
    } > ccp_acr_ram AT>m_text
    .ccp_avas_unit :	ALIGN(4)
    {
        KEEP(*(.ccp_avas_unit))
    } > ccp_avas_ram AT>m_text
    .ccp_chrg_unit :	ALIGN(4)
    {
        KEEP(*(.ccp_chrg_unit))
    } > ccp_chrg_ram AT>m_text
    .ccp_dhp_unit :	ALIGN(4)
    {
        KEEP(*(.ccp_dhp_unit))
    } > ccp_dhp_ram AT>m_text
    .ccp_dim_unit :	ALIGN(4)
    {
        KEEP(*(.ccp_dim_unit))
    } > ccp_dim_ram AT>m_text
    .ccp_dom_unit :	ALIGN(4)
    {
        KEEP(*(.ccp_dom_unit))
    } > ccp_dom_ram AT>m_text
    .ccp_dsi_unit :	ALIGN(4)
    {
        KEEP(*(.ccp_dsi_unit))
    } > ccp_dsi_ram AT>m_text
    .ccp_enm_unit :	ALIGN(4)
    {
        KEEP(*(.ccp_enm_unit))
    } > ccp_enm_ram AT>m_text
    .ccp_hali_unit :	ALIGN(4)
    {
        KEEP(*(.ccp_hali_unit))
    } > ccp_hali_ram AT>m_text
    .ccp_nm_unit :	ALIGN(4)
    {
        KEEP(*(.ccp_nm_unit))
    } > ccp_nm_ram AT>m_text
    .ccp_peps_unit :	ALIGN(4)
    {
        KEEP(*(.ccp_peps_unit))
    } > ccp_peps_ram AT>m_text
    .ccp_pmm_unit :	ALIGN(4)
    {
        KEEP(*(.ccp_pmm_unit))
    } > ccp_pmm_ram AT>m_text
    .ccp_scr_unit :	ALIGN(4)
    {
        KEEP(*(.ccp_scr_unit))
    } > ccp_scr_ram AT>m_text
    .ccp_tmm_unit :	ALIGN(4)
    {
        KEEP(*(.ccp_tmm_unit))
    } > ccp_tmm_ram AT>m_text
    .ccp_tqfrate_unit :	ALIGN(4)
    {
        KEEP(*(.ccp_tqfrate_unit))
    } > ccp_tqfrate_ram AT>m_text
    .ccp_tqm_unit :	ALIGN(4)
    {
        KEEP(*(.ccp_tqm_unit))
    } > ccp_tqm_ram AT>m_text
    .ccp_bsw_unit :	ALIGN(4)
    {
        KEEP(*(.ccp_bsw_unit))
    } > ccp_bsw_ram AT>m_text
    
    .ccp_btk_unit :	ALIGN(4)
    {
        KEEP(*(.ccp_btk_unit))
    } > ccp_btk_ram AT>m_text
        
    .m_init_unit : ALIGN(4)
    {
    	KEEP(*(m_init_unit))
    } > m_init AT>m_text
    /******************************/
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
__INITDATA_SRAM_ADDR = ADDR(.m_init_unit);

__DATA_SIZE   = SIZEOF(.data);
__SDATA_SIZE  = SIZEOF(.sdata);
__INITDATA_SIZE  = SIZEOF(.m_init_unit);

__DATA_ROM_ADDR  = LOADADDR(.data);
__SDATA_ROM_ADDR = LOADADDR(.sdata);
__INITDATA_ROM_ADDR = LOADADDR(.m_init_unit);
   
/* Labels Used for Initialising SRAM ECC */
__SRAM_SIZE = SRAM_SIZE;
__SRAM_BASE_ADDR = SRAM_BASE_ADDR;
      
__LOCAL_DMEM_SIZE = LOCALDMEM_SIZE;
__LOCAL_DMEM_BASE_ADDR = LOCALDMEM_BASE_ADDR;

__LOCAL_IMEM_SIZE = LOCALIMEM_SIZE;
__LOCAL_IMEM_BASE_ADDR = LOCALIMEM_BASE_ADDR;

__BSS_SIZE    = __BSS_END - __BSS_START;  
      
}

