/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@42lehavre.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 19:14:25 by abosc             #+#    #+#             */
/*   Updated: 2026/05/03 19:14:26 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int atoi(const char* str)
{
	int result = 0;
	int sign = 1;

	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return sign * result;
}