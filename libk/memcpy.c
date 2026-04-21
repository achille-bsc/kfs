/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@42lehavre.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 23:09:10 by abosc             #+#    #+#             */
/*   Updated: 2026/04/18 23:13:59 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void *memcpy(void *dest, const void *src, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((uint8_t *)dest)[i] = ((const uint8_t *)src)[i];
		i++;
	}
	return (dest);
}