/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@42lehavre.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 23:36:11 by abosc             #+#    #+#             */
/*   Updated: 2026/04/18 23:36:36 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *itoa(int num)
{
	static char buffer[12];
	int i = 10;
	buffer[11] = '\0';

	int is_negative = num < 0;
	if (is_negative)
		num = -num;

	do {
		buffer[i--] = '0' + (num % 10);
		num /= 10;
	} while (num > 0);

	if (is_negative)
		buffer[i--] = '-';

	return &buffer[i + 1];
}