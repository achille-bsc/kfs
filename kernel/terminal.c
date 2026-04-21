/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@42lehavre.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 00:50:05 by abosc             #+#    #+#             */
/*   Updated: 2026/04/21 12:35:39 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kernel.h"
#include "../io/io.h"


void update_cursor()
{
	int pos = g_terminal[current_terminal].cursor_y * 80 + g_terminal[current_terminal].cursor_x;
	outb(0x3D4, 0x0F);           // on veut modifier l'octet bas de la position
	outb(0x3D5, pos & 0xFF);     // on envoie l'octet bas

	outb(0x3D4, 0x0E);           // on veut modifier l'octet haut
	outb(0x3D5, (pos >> 8));     // on envoie l'octet haut
}

void terminal_init()
{
	for (int i = 0; i < TERMINAL_COUNTERS; i++)
	{
		g_terminal[i].cursor_x = 0;
		g_terminal[i].cursor_y = 0;
		g_terminal[i].color = kcolors(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
		for (int j = 0; j < VGA_BUFFER_SIZE; j++)
			g_terminal[i].terminal_buffer[j] = ' ';
	}
	update_cursor();
}