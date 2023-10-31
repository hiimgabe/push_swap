NAME = push_swap

SRC = src/main.c src/init.c src/utils.c src/node_utils.c

OBJ = ${SRC:.c=.o}

CC = cc
RM = rm -rf
CFLAGS = -Wall -Werror -Wextra -g
INCLUDE = -I include
MAKE = make -C
LIBFT_PATH = libft
LIBFT = -L ${LIBFT_PATH} -lft

.c.o:
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	${MAKE} ${LIBFT_PATH}
	${CC} ${OBJ} ${LIBFT} -o ${NAME}

all: ${NAME}

clean:
	${MAKE} ${LIBFT_PATH} clean
	${RM} ${OBJ}

fclean: clean
	${MAKE} ${LIBFT_PATH} fclean
	${RM} ${NAME}

re: fclean all