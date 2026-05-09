/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@42lehavre.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 22:45:19 by abosc             #+#    #+#             */
/*   Updated: 2026/05/03 19:15:01 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmds/cmds.h"
#include "../../utils/utils.h"
#include "../../libk/lib.h"
#define SHELL_BUF_SIZE 1024

static char shell_buffer[SHELL_BUF_SIZE];
static int shell_idx = 0;


static void shell_execute(void)
{
    shell_buffer[shell_idx] = '\0';
    putchar('\n');
    char line[128];
	char* argv[8];
	size_t argc;

	if (!shell_buffer)
		return 1;
	if (strcmp(shell_buffer, "\n") == 0)
		return 0;
    strlcpy(line, shell_buffer, sizeof(line));
	argc = split_words(line, argv, 8);
	if (argc == 0)
		return 0;

    if (strcmp(argv[0], "reboot") == 0) {
        putstr("Start rebooting...\n");
        power_reboot();
    } else if (strcmp(argv[0], "halt") == 0) {
        putstr("Dropping anchor. Halting CPU...\n");
        power_halt();
    } else if (strcmp(argv[0], "stack") == 0) {
        if (argv[1])
		{
			size_t words = (size_t)atoi(argv[1]);
			if (words > 0)
				dump_kernel_stack(words);
			else
				putstr("Usage: dump [words]\n");
		}
		else
			dump_kernel_stack(8);
    } else if (shell_idx > 0) {
        putstr("Unknown command: ");
        putstr(argv[0]);
        putchar('\n');
    }
    set_color(VGA_COLOR_LIGHT_GREEN, VGA_COLOR_BLACK);
    // Reset for the next command
    shell_idx = 0;
    putstr("kfs> ");
    set_color(VGA_COLOR_LIGHT_GREEN, VGA_COLOR_BLACK);
}

void shell_init()
{
    shell_idx = 0;
    putstr("\nkfs> ");
}

void shell_handle_char(char c)
{
    if (c == '\n') {
        shell_execute();
    } else if (c == '\b') {
        if (shell_idx > 0) {
            shell_idx--;
            putchar('\b'); // Let the VGA driver erase it from the screen
        }
    } else {
        if (shell_idx < SHELL_BUF_SIZE - 1) {
            shell_buffer[shell_idx++] = c;
            putchar(c); // print on the screen
        }
    }
}