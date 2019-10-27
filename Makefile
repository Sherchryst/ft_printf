# DIRECTORIES
BUILD	= .build
DEP_DIR	= $(BUILD)/dep
OBJ_DIR = $(BUILD)/obj
DIRS	:= $(DEP_DIR) $(addprefix $(DEP_DIR)/, $(SUB_DIR)) \
		  $(OBJ_DIR) $(addprefix $(OBJ_DIR)/, $(SUB_DIR))

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
	@ar rc $@ $^
	@ranlib $@
	@echo "                                                                    "
	@echo "\033[1;32mCreation of:\033[0m"
	@echo "███████╗████████╗     ██████╗ ██████╗ ██╗███╗   ██╗████████╗███████╗"
	@echo "██╔════╝╚══██╔══╝     ██╔══██╗██╔══██╗██║████╗  ██║╚══██╔══╝██╔════╝"
	@echo "█████╗     ██║        ██████╔╝██████╔╝██║██╔██╗ ██║   ██║   █████╗  "
	@echo "██╔══╝     ██║        ██╔═══╝ ██╔══██╗██║██║╚██╗██║   ██║   ██╔══╝  "
	@echo "██║        ██║███████╗██║     ██║  ██║██║██║ ╚████║   ██║   ██║     "
	@echo "╚═╝        ╚═╝╚══════╝╚═╝     ╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝   ╚═╝   ╚═╝     "
	@echo "                                                                    "
all: $(NAME)

clean:
	rm -rf $(BUILD)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(BUILD):
	@echo 'Creation of $(BUILD) directory'
	@mkdir $@ $(DIRS)

$(OBJ_DIR)/%.o: src/%.c | $(BUILD)
	@echo "\033[1;34mft_printf\t\033[1;33mCompilation of $(notdir $<)\033[0m"
	@$(CC) $(CFLAGS) $(DFLAGS) -I ./inc -c $< -o $@

-include $(DEP)

.PHONY: all clean fclean re
