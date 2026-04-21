/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putchar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@42lehavre.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 22:49:10 by abosc             #+#    #+#             */
/*   Updated: 2026/04/21 12:29:28 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../kernel/kernel.h"

void putchar(char c)
{
    t_terminal *term = &g_terminal[current_terminal];

	if (c == '\n')
    {
        term->cursor_x = 0;
        term->cursor_y++;
        update_cursor();
        return ;
    }
    
	unsigned char *vga_ptr = (unsigned char *)0xB8000;
    int pos = term->cursor_y * 80 + term->cursor_x;
    term->terminal_buffer[pos] = c;
    vga_ptr[2 * pos] = c;
    vga_ptr[2 * pos + 1] = term->color;
    term->cursor_x++;
    update_cursor();
}