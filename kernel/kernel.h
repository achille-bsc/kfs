/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@42lehavre.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 22:46:41 by abosc             #+#    #+#             */
/*   Updated: 2026/05/01 19:55:44 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../libk/lib.h"
#include    "../io/io.h"
#include    "terminal.h"
#include    "keyboard/keyboard.h"

#define     VGA_BUFFER_SIZE     2000
#define     TERMINAL_COUNTERS   10
#define     KERNEL_SEGMENT      0x08
#define     TERMINAL_WIDTH      80
#define     TERMINAL_HEIGHT     25

typedef struct s_terminal
{
    int                         cursor_x;
    int                         cursor_y;
    unsigned char               color;
    uint16_t                    terminal_buffer[TERMINAL_WIDTH * TERMINAL_HEIGHT];
}   t_terminal;

extern int          g_current_terminal;
extern t_terminal   g_terminal[TERMINAL_COUNTERS];
extern int          shift_held;
extern int          alt_held;
extern int          caps_lock_on;
