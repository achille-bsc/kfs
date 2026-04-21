/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@42lehavre.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 23:07:42 by abosc             #+#    #+#             */
/*   Updated: 2026/04/19 00:05:18 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//////////////
// INCLUDES //
//////////////
#include "types.h"
#include "../utils/utils.h"

///////////////
// FUNCTIONS //
///////////////
int strlen(const char *s);
int strcmp(const char *s1, const char *s2);
void *memset(void *s, int c, size_t n);
void *memcpy(void *dest, const void *src, size_t n);
char *itoa(int num);
void printk(const char *str, ...);