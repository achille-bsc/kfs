/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@42lehavre.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 00:50:05 by abosc             #+#    #+#             */
/*   Updated: 2026/05/01 19:52:43 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kernel.h"
#include "../io/io.h"
#include "../utils/utils.h"

void update_cursor()
{
	// printk("Updating cursor position to %d\n", get_pos());
	int pos = get_pos();
	outb(0x3D4, 0x0F);           // on veut modifier l'octet bas de la position
	outb(0x3D5, pos & 0xFF);     // on envoie l'octet bas

	outb(0x3D4, 0x0E);           // on veut modifier l'octet haut
	outb(0x3D5, (pos >> 8));     // on envoie l'octet haut
}


void terminal_init()
{
	// enable_cursor(14, 15);
	for (int i = 0; i < TERMINAL_COUNTERS; i++)
	{
		g_terminal[i].cursor_x = 0;
		g_terminal[i].cursor_y = 0;
		g_terminal[i].color = kcolors(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
		for (int j = 0; j < VGA_BUFFER_SIZE; j++)
		{
			g_terminal[i].terminal_buffer[j] = (uint16_t)' ' | ((uint16_t)g_terminal[i].color << 8);
		}
	}

	
	for (int i = 0; i < TERMINAL_COUNTERS; i++)
	{
		g_current_terminal = i;
		for (int j = 0; j < TERMINAL_COUNTERS; j++)
		{
			if (j == i)
				set_color(VGA_COLOR_WHITE, VGA_COLOR_GREEN);
			else
				set_color(VGA_COLOR_WHITE, VGA_COLOR_BLUE);
			printk("[alt+%d]", j + 1, j);
			set_color(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
			if (j < TERMINAL_COUNTERS - 1)
				putchar(' ');
		}
		putchar('\n');
	}
	g_current_terminal = 0;
	update_cursor();
	update_vga_buffer();
}