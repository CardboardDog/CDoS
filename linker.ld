OUTPUT_FORMAT(elf32-i386) /* build elf for i386 */
ENTRY(start) /* start function (see boot.s) */
SECTIONS{
	. = 1048576; /* 1M */
	.text(4096):ALIGN(4096){
		*(.multibot) /* multiboot header */
		*(.text) /* text (see boot.s) */
	}
	.data : {
		*(.data) /* initialized r/w data */
	}
	.bss : { 
		*(.bss) /* uninitialized r/w data */
	}
}