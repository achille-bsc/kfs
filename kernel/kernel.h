/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@42lehavre.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 22:46:41 by abosc             #+#    #+#             */
/*   Updated: 2026/04/21 12:37:04 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../libk/lib.h"
#include    "../io/io.h"
#include    "terminal.h"

#define     VGA_BUFFER_SIZE     2000
#define     TERMINAL_COUNTERS   1

typedef struct s_terminal
{
    int                         cursor_x;
    int                         cursor_y;
    unsigned char               color;
    unsigned char               terminal_buffer[80*25];
}   t_terminal;

extern int current_terminal;
extern t_terminal g_terminal[TERMINAL_COUNTERS];
