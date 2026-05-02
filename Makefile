# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abosc <abosc@42lehavre.fr>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/18 23:09:19 by abosc             #+#    #+#              #
#    Updated: 2026/05/01 23:18:12 by abosc            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        =   kernel.bin
ISO_NAME    =   kernel.iso
ISO_DIR     =   iso

LD          =   ld
CC          =   gcc
NASM        =   nasm

LD_FLAGS    =   -m elf_i386 -T linker.ld
ASM_FLAGS   =   -f elf32
CFLAGS      =   -Wall -Wextra -Werror -m32 -ffreestanding -fno-builtin \
                -nostdlib -nodefaultlibs -fno-exceptions -fno-stack-protector -mgeneral-regs-only \
				-I.

OBJ_DIR     =   obj

ASM_SRC     =   boot/boot.asm

C_SRC       =   kernel/kernel.c				\
				kernel/terminal.c			\
				kernel/keyboard/keyboard.c	\
				kernel/gdt/gdt.c			\
				kernel/shell/shell.c		\
				kernel/shell/cmds/power.c	\
				kernel/shell/cmds/stack.c	\
				utils/putchar.c				\
				utils/putstr.c				\
				utils/kcolors.c				\
				utils/set_color.c			\
				utils/pos.c					\
				utils/vga_buffer.c			\
				libk/strlen.c				\
				libk/memset.c				\
				libk/memcpy.c				\
				libk/strcmp.c				\
				libk/printk.c				\
				libk/itoa.c					\
				io/io.c						\

ASM_OBJ     =   $(ASM_SRC:%.asm=$(OBJ_DIR)/%.o)
C_OBJ       =   $(C_SRC:%.c=$(OBJ_DIR)/%.o)
OBJ         =   $(ASM_OBJ) $(C_OBJ)

all: $(ISO_NAME)

$(ISO_NAME): $(NAME)
	mkdir -p $(ISO_DIR)/boot/grub
	cp $(NAME) $(ISO_DIR)/boot/
	cp grub.cfg $(ISO_DIR)/boot/grub/
	grub-mkrescue --compress=gz -o $(ISO_NAME) $(ISO_DIR)

$(NAME): $(OBJ)
	$(LD) $(LD_FLAGS) -o $@ $^

$(OBJ_DIR)/%.o: %.asm
	mkdir -p $(dir $@)
	$(NASM) $(ASM_FLAGS) $< -o $@

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

run: re $(ISO_NAME)
	qemu-system-i386 -cdrom $(ISO_NAME)


dev: all $(ISO_NAME)
	qemu-system-i386 -drive format=raw,file=$(ISO_NAME) -s -S

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME) $(ISO_NAME)
	rm -rf $(ISO_DIR)

re: fclean all

.PHONY: all clean fclean re run dev
