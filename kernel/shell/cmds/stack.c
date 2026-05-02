/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@42lehavre.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 22:34:45 by abosc             #+#    #+#             */
/*   Updated: 2026/05/01 23:03:30 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libk/types.h"
#include "../../../libk/lib.h"
#include "../../../utils/utils.h"

void dump_kernel_stack(size_t words)
{
    uintptr_t    esp;
    uintptr_t    ebp;
    uint32_t    *ptr;
    size_t        i;

    __asm__ volatile ("mov %%esp, %0" : "=r"(esp));
    __asm__ volatile ("mov %%ebp, %0" : "=r"(ebp));

    printk("STACK", "esp=0x%x ebp=0x%x words=%u\n",
        (unsigned int)esp, (unsigned int)ebp, (unsigned int)words);

    ptr = (uint32_t *)esp;

    i = 0;
    while (i < words)
    {
        set_color((i + 1) % 16, VGA_COLOR_BLACK);
        printk("STACK [+0x%x] @0x%x = 0x%x\n",
            (unsigned int)(i * sizeof(uint32_t)),
            (unsigned int)(uintptr_t)(ptr + i),
            ptr[i]);
		i++;
		set_color(VGA_COLOR_LIGHT_GREEN, VGA_COLOR_BLACK);
    }
}
