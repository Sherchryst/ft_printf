# DIRECTORIES
SRC_DIR = ft_printf
DEP_DIR	= $(SRC_DIR)/dep
OBJ_DIR	= $(SRC_DIR)/obj
DIR		= $(DEP_DIR) $(OBJ_DIR)

# FILES
LIBFT	= libft
NAME	= libftprintf.a
SRC		= display_c.c display_o.c display_s.c display_ws.c init.c \
		parse_field_width.c parser.c treatement.c display_d.c display_other.c \
		display_u.c display_x.c parse_arguments.c parse_precision.c reinit.c \
		display_gap.c display_p.c display_wchar.c ft_printf.c parse_convert.c \
		parse_specifier.c switch_display.c
DEP		:= $($(SRC_DIR)/SRC:$(SRC_DIR)/%.c=$(DEP_DIR)/%.d)
OBJ		:= $($(SRC_DIR)/SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
# COMPILATION
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
DFLAGS	= -MP -MMD -MF $(DEP_DIR)/$*.d -MT '$@'
LFLAGS	= -L./ -lftprintf -I include/

$(NAME): $(OBJ)
	@echo 'Creation of $@'
	@make -C $(LIBFT)
	@cp $(LIBFT)/$@ .
	@ar -rcs $(NAME) $(OBJ)



all: $(NAME)

clean:
	@make clean -C $(LIBFT)
	rm -rf $(DIR)

fclean: clean
	@make fclean -C $(LIBFT)
	rm -f $(NAME)

re: fclean all

$(DEP_DIR):
	mkdir $@

$(OBJ_DIR):
	mkdir $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(DIR)
	@echo 'Compilation of $<'
	@$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@

-include $(DEP)

.PHONY: all clean fclean re
