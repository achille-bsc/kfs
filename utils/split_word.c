/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@42lehavre.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 19:08:46 by abosc             #+#    #+#             */
/*   Updated: 2026/05/03 19:08:47 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../libk/types.h"

size_t split_words(char* line, char** argv, size_t max_args)
{
	size_t argc = 0;
	char* p = line;

	while (*p && argc < max_args)
	{
		while (*p == ' ' || *p == '\t')
			p++;
		if (*p == '\0')
			break;
		argv[argc++] = p;
		while (*p && *p != ' ' && *p != '\t')
			p++;
		if (*p == '\0')
			break;
		*p = '\0';
		p++;
	}
	return argc;
}