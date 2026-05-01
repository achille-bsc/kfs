/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vga_buffer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@42lehavre.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 18:56:56 by abosc             #+#    #+#             */
/*   Updated: 2026/05/01 19:10:20 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../kernel/kernel.h"

void update_vga_buffer()
{
	uint16_t *vga_ptr = (uint16_t *)0xB8000;
	t_terminal *term = &g_terminal[g_current_terminal];

	for (size_t i = 0; i < TERMINAL_WIDTH * TERMINAL_HEIGHT; i++) {
		vga_ptr[i] = term->terminal_buffer[i];
	}
}