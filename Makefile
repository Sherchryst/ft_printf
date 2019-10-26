# DIRECTORIES
LFT_DIR	= libft
PRI_DIR	= libft/printf
DEP_DIR	= dep
OBJ_DIR	= obj
DIR		= $(addprefix $(LFT_DIR)/, $(LFT_DIR)) \
		$(addprefix $(PRI_DIR)/, $(PRI_DIR))

# FILES
NAME	= libftprintf.a
SRCS_LFT= ft_isalnum.c ft_isdigit.c ft_memccpy.c ft_memset.c ft_putchar.c \
		ft_atoi.c ft_isalpha.c ft_isprint.c ft_memcpy.c ft_bzero.c \
		ft_isascii.c ft_isspace.c ft_memmove.c ft_strlen.c ft_memcmp.c \
		ft_putstr.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
		ft_strncat.c ft_strlcat.c ft_putnbr.c ft_strchr.c ft_strrchr.c \
		ft_strstr.c ft_strnstr.c ft_strnchr.c ft_strncmp.c ft_strcmp.c \
		ft_strnlen.c ft_isupper.c ft_tolower.c ft_islower.c ft_toupper.c \
		ft_memdel.c ft_memalloc.c ft_strnew.c ft_strdel.c ft_strclr.c \
		ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
		ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
		ft_itoa.c ft_putendl.c ft_putchar_fd.c ft_putendl_fd.c ft_putstr_fd.c \
		ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
		ft_lstiter.c ft_lstmap.c ft_isblank.c ft_iscntrl.c ft_isgraph.c \
		ft_isxdigit.c ft_strjoinfree.c
SRCS_PRI= display_c.c display_other.c display_wchar.c init.c parse_precision.c \
		switch_display.c display_d.c display_p.c display_ws.c \
		parse_arguments.c parse_specifier.c treatement.c display_gap.c \
		display_s.c display_x.c parse_convert.c parser.c display_o.c \
		display_u.c ft_printf.c parse_field_width.c reinit.c
SRC		= $(addprefix $(LFT_DIR)/, $(SRCS_LFT)) \
		$(addprefix $(PRI_DIR)/, $(SRCS_PRI))
DEP		:= $(SRC:%.c=$(DEP_DIR)/%.d)
OBJ		:= $(SRC:%.c=$(OBJ_DIR)/%.o)

# COMPILATION
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
DFLAGS	= -MP -MMD -MF $(DEP_DIR)/$*.d -MT '$@'

$(NAME): $(OBJ)
	@echo 'Creation of $@'
	@ar -rcs $@ $^
	ranlib $@

all: $(NAME)

clean:
	rm -rf $(DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

$(DEP_DIR):
	mkdir $@

$(OBJ_DIR):
	mkdir $@

$(OBJ_DIR)/%.o: %.c | $(DIR)
	@echo 'Compilation of $<'
	@$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@

%.out: %.c $(NAME) | $(DIR)
	$(CC) $(CFLAGS) $(DFLAGS) $< -o $@ -L./libft -lft -I ./includes

-include $(DEP)

.PHONY: all clean fclean re
