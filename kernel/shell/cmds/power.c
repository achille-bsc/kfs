/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@42lehavre.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 22:54:32 by abosc             #+#    #+#             */
/*   Updated: 2026/05/01 23:00:30 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmds.h"
#include "../../../io/io.h"

void power_halt(void)
{
  __asm__ volatile("cli; hlt"); 
}

void power_reboot(void)
{
  uint8_t good = 0x02;
  while (good & 0x02) {
    good = inb(0x64);
  }
  outb(0x64, 0xFE);
  __asm__ volatile("hlt");
}