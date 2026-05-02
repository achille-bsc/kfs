/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gdt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@42lehavre.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 21:14:24 by abosc             #+#    #+#             */
/*   Updated: 2026/05/01 22:12:05 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libk/types.h"

// Une entrée de la GDT = 8 octets exactement
typedef struct {
    uint16_t limit_low;    // bits 0-15 de la limite
    uint16_t base_low;     // bits 0-15 de la base
    uint8_t  base_mid;     // bits 16-23 de la base
    uint8_t  access;       // droits d'accès (le plus important)
    uint8_t  granularity;  // flags + bits 16-19 de la limite
    uint8_t  base_high;    // bits 24-31 de la base
} __attribute__((packed)) gdt_entry_t;

typedef struct {
    uint16_t limit;   // taille totale de la GDT - 1
    uint32_t base;    // adresse de la GDT
} __attribute__((packed)) gdtr_t;

#define KERNEL_CODE_ACCESS  0x9A  // 1001 1010
//                                   P=1, DPL=00, S=1, E=1, DC=0, RW=1, A=0

#define KERNEL_DATA_ACCESS  0x92  // 1001 0010
//                                   P=1, DPL=00, S=1, E=0, DC=0, RW=1, A=0

#define USER_CODE_ACCESS    0xFA  // 1111 1010
//                                   P=1, DPL=11, S=1, E=1, DC=0, RW=1, A=0

#define USER_DATA_ACCESS    0xF2  // 1111 0010
//                                   P=1, DPL=11, S=1, E=0, DC=0, RW=1, A=0

#define GRANULARITY  0xCF  // 1100 1111
//                            G=1, DB=1, 0, 0, limite_high=1111


void gdt_init(void);