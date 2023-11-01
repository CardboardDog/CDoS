bits 32 ;specify that this program is x32
section .text
align 4 ;multiboot
dd 0x1BADB002 ;magic number
dd 0x0 ;flags
dd -(0x0+0x1BADB002) ;checksum
global start ;make start accessable
extern boot_kernel ;boot kernel function (check kernel.c)
start:
    cli ;dissable interupts
    mov esp, stack_space ;stack pointer
    call boot_kernel ;start kernel
    hlt ;wait for kernel to shut down
resb 104856 ;give one MB of data to the stack
stack_space:
;this took an hour to write, don't judge