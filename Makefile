NAME        =   kernel.bin
ISO_NAME    =   kernel.iso
ISO_DIR     =   iso

LD          =   ld
CC          =   gcc
NASM        =   nasm

LD_FLAGS    =   -m elf_i386 -T linker.ld
ASM_FLAGS   =   -f elf32
CFLAGS      =   -Wall -Wextra -Werror -m32 -ffreestanding -fno-builtin \
                -nostdlib -nodefaultlibs -fno-stack-protector -mgeneral-regs-only\
				-I.

OBJ_DIR     =   obj

ASM_SRC     =   boot/boot.asm

C_SRC       =   kernel/kernel.c

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

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME) $(ISO_NAME)
	rm -rf $(ISO_DIR)

re: fclean all

.PHONY: all clean fclean re run
