/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@42lehavre.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 12:36:56 by abosc             #+#    #+#             */
/*   Updated: 2026/04/27 21:51:15 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libk/types.h"

#ifndef KEYBOARD_H
#define KEYBOARD_H

typedef struct s_idt_entry
{
    uint16_t  offset_low;
    uint16_t  selector;
    uint8_t   zero;
    uint8_t   flags;
    uint16_t  offset_high;
}   __attribute__((packed)) t_idt_entry;

typedef struct s_idtr
{
    uint16_t    limit;
    uint32_t    base;
} __attribute__((packed)) t_idtr;

static const char min_scancode_table[] = {
    0,    0,   '1', '2', '3', '4', '5', '6',
    '7', '8', '9', '0', '-', '=', '\b', '\t',
    'q', 'w', 'e', 'r', 't', 'y', 'u', 'i',
    'o', 'p', '[', ']', '\n', 0,  'a', 's',
    'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',
    '\'', 0,   0,  '\\','z', 'x', 'c', 'v',
    'b', 'n', 'm', ',', '.', '/', 0,   0,
    0,   ' ',
};

static const char max_scancode_table[] = {
    0,    0,   '!', '@', '#', '$', '%', '^',
    '&', '*', '(', ')', '_', '+', '\b', '\t',
    'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I',
    'O', 'P', '[', ']', '\n', 0,  'A', 'S',
    'D', 'F', 'G', 'H', 'J', 'K', 'L', ';',
    '\'', 0,   0,  '\\','Z', 'X', 'C', 'V',
    'B', 'N', 'M', '<', '>', '?', 0,   0,
    0,   ' ',
};

struct interrupt_frame;

void idt_init(void);
void idt_set_gate(unsigned char num, unsigned int handler);


#endif