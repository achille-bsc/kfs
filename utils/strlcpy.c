/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@42lehavre.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 19:00:28 by abosc             #+#    #+#             */
/*   Updated: 2026/05/03 19:10:49 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libk/types.h"

size_t strlcpy(char* dst, const char* src, size_t dst_size)
{
	size_t i = 0;

	if (dst_size == 0)
		return 0;
	while (src[i] && i + 1 < dst_size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return i;
}

