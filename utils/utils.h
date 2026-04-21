/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@42lehavre.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 22:50:05 by abosc             #+#    #+#             */
/*   Updated: 2026/04/19 00:31:42 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

///////////
// ENUMS //
///////////
enum e_vga_colors
{
	VGA_COLOR_BLACK = 0,
	VGA_COLOR_BLUE = 1,
	VGA_COLOR_GREEN = 2,
	VGA_COLOR_CYAN = 3,
	VGA_COLOR_RED = 4,
	VGA_COLOR_MAGENTA = 5,
	VGA_COLOR_BROWN = 6,
	VGA_COLOR_LIGHT_GREY = 7,
	VGA_COLOR_DARK_GREY = 8,
	VGA_COLOR_LIGHT_BLUE = 9,
	VGA_COLOR_LIGHT_GREEN = 10,
	VGA_COLOR_LIGHT_CYAN = 11,
	VGA_COLOR_LIGHT_RED = 12,
	VGA_COLOR_LIGHT_MAGENTA = 13,
	VGA_COLOR_YELLOW = 14,
	VGA_COLOR_WHITE = 15
};

//////////////////////////
// FUNCTIONS PROTOTYPES //
//////////////////////////
void			putchar		(char c);
int				putstr		(const char *str);
unsigned char	kcolors		(unsigned char fg, unsigned char bg);
void			set_color	(unsigned char fg, unsigned char bg);