/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@42lehavre.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 19:34:54 by abosc             #+#    #+#             */
/*   Updated: 2026/05/03 19:12:59 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keyboard.h"
#include "../kernel.h"
#include "../shell/shell.h"
// #include "../../utils/utils.h"

t_idt_entry idt[256];

__attribute__((interrupt)) void keyboard_handler(struct interrupt_frame* frame) {
  (void)frame;
    uint8_t keyboard_input = inb(0x60);
    
    // Send End of Interrupt (EOI) to the master PIC FIRST!
    outb(0x20, 0x20); 
    
    if (keyboard_input == 0x2A || keyboard_input == 0x36)
      shift_held = 1;
    else if (keyboard_input == 0xAA || keyboard_input == 0xB6)
      shift_held = 0;
    else if (keyboard_input == 0x38)
      alt_held = 1;
    else if (keyboard_input == 0xB8)
      alt_held = 0;
    else if (keyboard_input == 0x3A)
      caps_lock_on = !caps_lock_on;

    // Key press is registered when the top bit is 0
    if (!(keyboard_input & 0x80)) {
        if (shift_held || caps_lock_on) {
            if (keyboard_input < sizeof(max_scancode_table)) {
                char c = max_scancode_table[keyboard_input];
                if (alt_held && (
                    c == (char)'1'
                    || c == (char)'2'
                    || c == (char)'3'
                    || c == (char)'4'
                    || c == (char)'5'
                    || c == (char)'6'
                    || c == (char)'7'
                    || c == (char)'8'
                    || c == (char)'9'
                    || c == (char)'0'
                  )
                ) {
                  if (c == '0') g_current_terminal = 9 % TERMINAL_COUNTERS;
                  else
                    g_current_terminal = (c - '1') % TERMINAL_COUNTERS;
                  update_vga_buffer();
                  update_cursor();
                  shell_init();
                }
                else if (c) shell_handle_char(c);
            }
        } else {
            if (keyboard_input < sizeof(min_scancode_table)) {
                char c = min_scancode_table[keyboard_input];
                if (alt_held && (
                    c == (char)'1'
                    || c == (char)'2'
                    || c == (char)'3'
                    || c == (char)'4'
                    || c == (char)'5'
                    || c == (char)'6'
                    || c == (char)'7'
                    || c == (char)'8'
                    || c == (char)'9'
                    || c == (char)'0'
                  )
                ) {
                  if (c == '0') g_current_terminal = 9 % TERMINAL_COUNTERS;
                  else
                    g_current_terminal = (c - '1') % TERMINAL_COUNTERS;
                  update_vga_buffer();
                  update_cursor();
                  shell_init();
                }
                else if (c) shell_handle_char(c);
            }
        }
    }
}

void idt_set_gate(unsigned char num, unsigned int handler)
{
    unsigned short cs;
    __asm__ volatile ("mov %%cs, %0" : "=r"(cs));

    idt[num].offset_low  = handler & 0xFFFF;        // garde les 16 bits bas
    idt[num].selector    = cs;                      // utilise le selecteur de code courant
    idt[num].zero        = 0;                       // toujours 0
    idt[num].flags       = 0x8E;                    // interrupt gate ring 0
    idt[num].offset_high = (handler >> 16) & 0xFFFF; // garde les 16 bits hauts
}
 
void idt_init(void)
{
	/* Register the keyboard IRQ handler (IRQ1 -> INT 0x21 after PIC remap) */
	idt_set_gate(0x21, (unsigned int)keyboard_handler);
 
	t_idtr idtr;
	idtr.limit = (sizeof(t_idt_entry) * 256) - 1;
	idtr.base  = (unsigned int)&idt;
	__asm__ volatile("lidt %0" : : "m"(idtr));
}
