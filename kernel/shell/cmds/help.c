/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@42lehavre.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 18:51:01 by abosc             #+#    #+#             */
/*   Updated: 2026/05/03 20:07:58 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../utils/utils.h"

void help_shell()
{
	putstr("[help] - gives every commands available");
	putstr("[shutdown]");
	putstr("[reboot]");
	putstr("[stack  ]");
}