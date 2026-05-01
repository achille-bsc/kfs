/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@42lehavre.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 12:41:29 by abosc             #+#    #+#             */
/*   Updated: 2026/05/01 19:10:20 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../kernel/kernel.h"

int get_pos()
{
	return (&g_terminal[g_current_terminal])->cursor_y * 80 + (&g_terminal[g_current_terminal])->cursor_x;
}