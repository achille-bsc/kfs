/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@42lehavre.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 22:55:03 by abosc             #+#    #+#             */
/*   Updated: 2026/05/01 22:59:14 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../utils/utils.h"
#include "../../../libk/types.h"


void dump_kernel_stack(size_t words);
void power_halt(void);
void power_reboot(void);