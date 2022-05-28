# mini talk makefile

CC		=	gcc

CFLAGS		=	-Wall -Wextra -Werror

INCLUDE		=	-Iinclude/

NAME		=	minitalk

SRC_PATH	=	src/

SERVER_FILES	=	server.c

CLIENT_FILES	=	client.c

SERVER_SRC	=	$(addprefix $(SRC_PATH),$(SERVER_FILES))

CLIENT_SRC	=	$(addprefix $(SRC_PATH),$(CLIENT_FILES))

SERVER_OBJ	=	${SERVER_SRC:%.c=%.o}

CLIENT_OBJ	=	${CLIENT_SRC:%.c=%.o}

SERVER		=	server

CLIENT		=	client

LIB_PATH	=	-Llib/libft

LIB		=	-lft

LIBFT		=	lib/libft/libft.a

all	:	${NAME}

dirty	:	
	${CC} ${INCLUDE} ${SERVER_SRC} ${LIB_PATH} ${LIB} -o ${SERVER}
	${CC} ${INCLUDE} ${CLIENT_SRC} ${LIB_PATH} ${LIB} -o ${CLIENT}

dirtyc	:	dirty
	./client 123 abc

dirtys	:	dirty
	./server

${NAME}	:	${SERVER} ${CLIENT}

${SERVER}:	${LIBFT} ${SERVER_OBJ}
	@echo "[gcamelo-'s mini talk]> Compiling the '${SERVER}' executable..."
	@${CC} ${CFLAGS} ${INCLUDE} ${SERVER_OBJ} ${LIB_PATH} ${LIB} -o ${SERVER}

${CLIENT}:	${LIBFT} ${CLIENT_OBJ}
	@echo "[gcamelo-'s mini talk]> Compiling the '${CLIENT}' executable..."
	@${CC} ${CFLAGS} ${INCLUDE} ${CLIENT_OBJ} ${LIB_PATH} ${LIB} -o ${CLIENT}

${LIBFT}:
	@echo "[gcamelo-'s mini talk]> Start do compiling the libft library..."
	@cd ./lib/libft ; \
	make -s

%.o	: %.c
	@echo "[gcamelo-'s mini talk]> Compiling $@"
	@${CC} ${CFLAGS} ${INCLUDE} -c -o $@ $(subst .o,.c,$@)

clean	:
	@echo "[gcamelo-'s mini talk]> Cleaning .o files..."
	@rm -f ${SERVER_OBJ} ${CLIENT_OBJ}

fclean	: clean
	@echo "[gcamelo-'s mini talk]> Cleaning the mini talk executables..."
	@rm -f ${SERVER} ${CLIENT}

re	: re_echo fclean ${NAME}

re_echo	:
	@echo "[gcamelo-'s mini talk]> Redoing..."

.PHONY	: all clean fclean re
