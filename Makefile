# DIRECTORIES
BUILD	= .build
DEP_DIR	= $(BUILD)/dep
OBJ_DIR = $(BUILD)/obj
DIRS	:= $(DEP_DIR) $(OBJ_DIR)

# FILES
NAME	= libftprintf.a
SRC		= display_c.c display_o.c display_s.c display_ws.c init.c \
		parse_field_width.c parser.c treatement.c display_d.c display_other.c \
		display_u.c display_x.c parse_arguments.c parse_precision.c reinit.c \
		display_gap.c display_p.c display_wchar.c ft_printf.c parse_convert.c \
		parse_specifier.c switch_display.c ft_strndup.c ft_strcmp.c \
		ft_putnbrmax_fd.c ft_putstr.c ft_strdup.c ft_putnbrumax_fd.c \
		ft_strcmp.c ft_strnew.c ft_memset.c ft_strlen.c ft_itoa_base.c \
		ft_calloc.c ft_putchar_fd.c
DEP		:= $(SRC:%.c=$(DEP_DIR)/%.d)
OBJ		:= $(SRC:%.c=$(OBJ_DIR)/%.o)

# COMPILATION
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -Ofast -fno-builtin
DFLAGS	= -MP -MMD -MF $(DEP_DIR)/$*.d -MT '$@'
$(NAME): $(OBJ)
	@ar -rcs $@ $^
	@echo "\n\033[01mThe library archive of \033[00m\033[32m"
	@echo "	███████╗████████╗     ██████╗ ██████╗ ██╗███╗   ██╗████████╗███████╗	"
	@echo "	██╔════╝╚══██╔══╝     ██╔══██╗██╔══██╗██║████╗  ██║╚══██╔══╝██╔════╝	"
	@echo "	█████╗     ██║        ██████╔╝██████╔╝██║██╔██╗ ██║   ██║   █████╗  	"
	@echo "	██╔══╝     ██║        ██╔═══╝ ██╔══██╗██║██║╚██╗██║   ██║   ██╔══╝  	"
	@echo "	██║        ██║███████╗██║     ██║  ██║██║██║ ╚████║   ██║   ██║     	"
	@echo "	╚═╝        ╚═╝╚══════╝╚═╝     ╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝   ╚═╝   ╚═╝ \033[00m"
	@echo "							       \033[01mHas been created!\n\033[00m"

all: $(NAME)

clean:
	@rm -rf $(BUILD)
	@echo "\033[1;34mExecute:\t\033[1;33mCleaning build\t\033[0;32m[OK]\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;34mExecute:\t\033[1;33mCleaning lib\t\033[0;32m[OK]\033[0m"
re: fclean all

$(BUILD):
	@echo "\033[1;32mCreation of .build\033[0m \n"
	@mkdir $@ $(DIRS)

$(OBJ_DIR)/%.o: src/%.c | $(BUILD)
	@echo "\033[1;34mExecute: \t\033[1;33mCompilation of $(notdir $<)\033[0m"
	@$(CC) $(CFLAGS) $(DFLAGS) -I ./inc -c $< -o $@

-include $(DEP)

.PHONY: all clean fclean re
