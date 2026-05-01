/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@42lehavre.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 20:49:36 by abosc             #+#    #+#             */
/*   Updated: 2026/05/01 20:00:12 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kernel.h"

int g_current_terminal = 0;

t_terminal g_terminal[TERMINAL_COUNTERS];
int shift_held = 0;
int alt_held = 0;
int caps_lock_on = 0;

void pic_init()
{
	outb(0x20, 0x11);
	
	outb(0xA0, 0x11);
	outb(0x21, 0x20);
	outb(0xA1, 0x28);
	outb(0x21, 0x04);
	outb(0xA1, 0x02);
	outb(0x21, 0x01);
	outb(0xA1, 0x01);
	outb(0x21, 0xFD);
	outb(0xA1, 0xFF);
}

int kernel_main(void)
{
	terminal_init();
	idt_init();
	pic_init();

	/* Enable maskable interrupts */
	__asm__ volatile("sti");

	g_terminal[g_current_terminal].color = (VGA_COLOR_BLACK << 4) | VGA_COLOR_GREEN;
	putstr("Hello, World!");
	set_color(VGA_COLOR_LIGHT_GREEN, VGA_COLOR_BLACK);
	putstr("42\n");
	g_terminal[g_current_terminal].color = (VGA_COLOR_BLACK << 4) | VGA_COLOR_WHITE;

	while (1)
	{
	}
}