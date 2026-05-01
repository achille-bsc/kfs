/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putchar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@42lehavre.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 22:49:10 by abosc             #+#    #+#             */
/*   Updated: 2026/05/01 19:58:43 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../kernel/kernel.h"

static inline uint16_t vga_entry(unsigned char uc, uint8_t color){
  return (uint16_t)uc | (uint16_t) color << 8;
}

void putchar(char c)
{
    uint16_t *vga_ptr = (uint16_t *)0xB8000;
    t_terminal *term = &g_terminal[g_current_terminal];

	if (c == '\n')
    {
        term->cursor_x = 0;
        if (term->cursor_y < 24)
            term->cursor_y++;
        else
        {
            // Scroll up
            for (size_t i = 0; i < (TERMINAL_WIDTH * (TERMINAL_HEIGHT - 1)); i++) {
                term->terminal_buffer[i] = term->terminal_buffer[i + TERMINAL_WIDTH];
                vga_ptr[i] = term->terminal_buffer[i];
            }
            // Clear the last line
            for (size_t i = (TERMINAL_WIDTH * (TERMINAL_HEIGHT - 1)); i < (TERMINAL_WIDTH * TERMINAL_HEIGHT); i++) {
                term->terminal_buffer[i] = vga_entry(' ', term->color);
                vga_ptr[i] = term->terminal_buffer[i];
            }
        }
        // term->cursor_y++;
        update_cursor();
        return ;
    }
    else if (c == '\b')
    {
        if (term->cursor_x > 0) {
            term->cursor_x--;
        } else if (term->cursor_y > 0) {
            term->cursor_y--;
            for (size_t i = TERMINAL_WIDTH; i > 0; i--) {
                if ((char)term->terminal_buffer[(term->cursor_y * TERMINAL_WIDTH) + i - 1] != ' ') {
                    term->cursor_x = i;
                    break;
                }
            }
        }
        int pos = term->cursor_y * 80 + term->cursor_x;
        term->terminal_buffer[pos] = vga_entry(' ', term->color);
        vga_ptr[pos] = term->terminal_buffer[pos];
        update_cursor();
        return ;
    }
    else
    {
        // unsigned char *vga_ptr = (unsigned char *)0xB8000;
        int pos = term->cursor_y * 80 + term->cursor_x;
        term->terminal_buffer[pos] = vga_entry(c, term->color);
        vga_ptr[pos] = term->terminal_buffer[pos];
        term->cursor_x++;
        if (term->cursor_x >= 80)
        {
            term->cursor_x = 0;
            if (term->cursor_y < 24)
                term->cursor_y++;
            else
            {
                // Scroll up
                for (size_t i = 0; i < (TERMINAL_WIDTH * (TERMINAL_HEIGHT - 1)); i++) {
                    term->terminal_buffer[i] = term->terminal_buffer[i + TERMINAL_WIDTH];
                    vga_ptr[i] = term->terminal_buffer[i];
                }
                // Clear the last line
                for (size_t i = (TERMINAL_WIDTH * (TERMINAL_HEIGHT - 1)); i < (TERMINAL_WIDTH * TERMINAL_HEIGHT); i++) {
                    term->terminal_buffer[i] = vga_entry(' ', term->color);
                    vga_ptr[i] = term->terminal_buffer[i];
                }
            }
        }
        update_cursor();    
    }
    
}