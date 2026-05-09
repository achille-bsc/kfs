/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 01:29:47 by etaquet           #+#    #+#             */
/*   Updated: 2026/05/07 01:34:56 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
# define HELPERS_H

#include "define.h"

int atoi(const char* str);
size_t split_words(char* line, char** argv, size_t max_args);
int ft_strcmp(const char* a, const char* b);
size_t ft_strlcpy(char* dst, const char* src, size_t dst_size);
size_t strlen(const char* str);
uint32_t read_cr2(void);
uint32_t read_cr0(void);

#endif