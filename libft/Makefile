# DIRECTORIES
DEP_DIR	= dep
OBJ_DIR	= obj
DIR		= $(DEP_DIR) $(OBJ_DIR)

# FILES
NAME	= libft.a
SRC		= ft_isalnum.c ft_isdigit.c ft_memccpy.c ft_memset.c \
		ft_atoi.c ft_isalpha.c ft_isprint.c ft_memcpy.c ft_bzero.c \
		ft_isascii.c ft_memmove.c ft_strlen.c ft_memcmp.c \
		ft_strdup.c ft_calloc.c ft_strmapi.c ft_strlcpy.c ft_strnew.c \
		ft_strlcat.c ft_strchr.c ft_strrchr.c ft_putnbr_fd.c \
		ft_strnstr.c ft_strncmp.c ft_memchr.c ft_isupper.c ft_strcat.c \
		ft_tolower.c ft_toupper.c ft_isspace.c ft_islower.c ft_strcpy.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_strncpy.c \
		ft_itoa.c ft_putchar_fd.c ft_putendl_fd.c ft_putstr_fd.c
DEP		:= $(SRC:%.c=$(DEP_DIR)/%.d)
OBJ		:= $(SRC:%.c=$(OBJ_DIR)/%.o)

# COMPILATION
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
DFLAGS	= -MP -MMD -MF $(DEP_DIR)/$*.d -MT '$@'

$(NAME): $(OBJ)
	@echo 'Creation of $@'
	@ar -rcs $@ $^

all: $(NAME)

clean:
	rm -rf $(DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(DEP_DIR):
	mkdir $@

$(OBJ_DIR):
	mkdir $@

$(OBJ_DIR)/%.o: %.c | $(DIR)
	@echo 'Compilation of $<'
	@$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@

$(OBJ_DIR)/%bonus.o: %.c | $(DIR)
	@echo 'Compilation of $<'
	@$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@

-include $(DEP)

.PHONY: all clean fclean re
