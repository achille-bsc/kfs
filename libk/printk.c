/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printk.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@42lehavre.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 23:30:33 by abosc             #+#    #+#             */
/*   Updated: 2026/04/27 20:15:11 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "./lib.h"

static int	putHex(unsigned int num, int uppercase)
{
	char	buffer[9];
	char	*digits_lower = "0123456789abcdef";
	char	*digits_upper = "0123456789ABCDEF";
	char	*digits;
	int		i;

	digits = uppercase ? digits_upper : digits_lower;
	i = 8;
	buffer[8] = '\0';
	if (num == 0)
		return (putchar('0'), 1);
	while (num > 0)
	{
		buffer[--i] = digits[num % 16];
		num /= 16;
	}
	return (putstr(&buffer[i]));
}

void handle_args(const char *str, va_list args)
{
	int x = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'd')
			{
				int num = va_arg(args, int);
				x += putstr(itoa(num));
			}
			else if (*str == 's')
			{
				char *s = va_arg(args, char *);
				x += putstr(s);
			}
			else if (*str == 'c')
			{
				char c = (char)va_arg(args, int);
				putchar(c);
				x++;
			}
			else if (*str == 'x' || *str == 'X')
			{
				unsigned int num = va_arg(args, unsigned int);
				x += putHex(num, *str == 'X');
			}
		}
		else
		{
			putchar(*str);
			x++;
		}
		str++;
	}
}


void printk(const char *str, ...)
{
    va_list args;
    va_start(args, str);
    
	handle_args(str, args);

    va_end(args);
}