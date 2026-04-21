/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@42lehavre.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 00:26:19 by abosc             #+#    #+#             */
/*   Updated: 2026/04/19 00:28:04 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../kernel/kernel.h"

void set_color(unsigned char fg, unsigned char bg)
{
	g_terminal[current_terminal].color = kcolors(fg, bg);
}