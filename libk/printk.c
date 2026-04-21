/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printk.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@42lehavre.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 23:30:33 by abosc             #+#    #+#             */
/*   Updated: 2026/04/19 00:30:45 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "./lib.h"

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