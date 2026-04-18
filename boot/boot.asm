; ************************************************************************** ;
;                                                                            ;
;                                                        :::      ::::::::   ;
;   boot.asm                                           :+:      :+:    :+:   ;
;                                                    +:+ +:+         +:+     ;
;   By: abosc <abosc@42lehavre.fr>                 +#+  +:+       +#+        ;
;                                                +#+#+#+#+#+   +#+           ;
;   Created: 2026/04/18 20:49:36 by abosc             #+#    #+#             ;
;   Updated: 2026/04/18 20:49:36 by abosc            ###   ########.fr       ;
;                                                                            ;
; ************************************************************************** ;

; Constantes Multiboot
MB_ALIGN    equ 1<<0
MB_MEMINFO  equ 1<<1
MB_FLAGS    equ MB_ALIGN | MB_MEMINFO
MB_MAGIC    equ 0x1BADB002
MB_CHECKSUM equ -(MB_MAGIC + MB_FLAGS)

section .multiboot
align 4
    dd MB_MAGIC
    dd MB_FLAGS
    dd MB_CHECKSUM

section .bss
align 16
stack_bottom:
    resb 16384
stack_top:

section .text
extern kernel_main
global _start
_start:
    mov esp, stack_top
    call kernel_main
    cli
.hang:
    hlt
    jmp .hang