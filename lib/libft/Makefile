NAME = libft.a

CC = gcc

SRC_PART1 = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_atoi.c ft_memset.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_bzero.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c get_next_line_utils.c get_next_line.c ft_printf.c ft_solve_char.c ft_solve_str.c ft_solve_ptr.c ft_solve_int.c ft_solve_unsig.c ft_solve_hex.c ft_lstadd_back.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_lstsize.c ft_lstadd_front.c ft_lstdelone.c ft_lstlast.c ft_lstnew.c

OBJ_PART1 = ${SRC_PART1:%.c=%.o}

all: ${NAME} clean

${NAME}: ${OBJ_PART1}
	@echo "[gcamelo-'s mini talk]> Archiving the libft lib in a .a file."
	@ar -crs ${NAME} ${OBJ_PART1}

${OBJ_PART1}: obj_echo
	@${CC} -Wall -Wextra -Werror -c $(subst .o,.c,$@)

obj_echo:
	@echo "[gcamelo-'s mini talk]> Compiling the embedded libft."

clean:
	@echo "[gcamelo-'s mini talk]> Cleaning libft .o files."
	@rm -f ${OBJ_PART1}

fclean: clean
	@echo "[gcamelo-'s mini talk]> Force cleaning libft."
	@rm -f ${NAME}

re: clean all

.PHONY: all clean fclean re
