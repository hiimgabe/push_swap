NAME = push_swap

NAME_BONUS = checker

SRC = src/main.c src/init.c src/utils.c src/node_utils.c src/split.c src/swap.c src/push.c src/rotate.c src/tiny_sort.c \
		src/target.c src/price.c src/push_swap.c src/push_to_b.c src/exit.c

SRC_BONUS = bonus/checker.c src/init.c src/utils.c src/node_utils.c src/split.c src/swap.c src/push.c src/rotate.c src/tiny_sort.c \
			src/target.c src/price.c src/push_swap.c src/push_to_b.c src/exit.c


OBJ = ${SRC:.c=.o}

OBJ_BONUS = ${SRC_BONUS:.c=.o}

CC = cc
RM = rm -rf
CFLAGS = -Wall -Werror -Wextra -g
INCLUDE = -I include
MAKE = make -C
LIBFT_PATH = libft
LIBFT = -L ${LIBFT_PATH} -lft
.c.o:
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

${NAME_BONUS}: ${OBJ_BONUS}
	${MAKE} ${LIBFT_PATH}
	${CC} ${OBJ_BONUS} ${LIBFT} -o ${NAME_BONUS}

${NAME}: ${OBJ}
	${MAKE} ${LIBFT_PATH}
	${CC} ${OBJ} ${LIBFT} -o ${NAME}

all: ${NAME}

bonus: ${NAME_BONUS}

clean:
	${MAKE} ${LIBFT_PATH} clean
	${RM} ${OBJ}
	${RM} ${OBJ_BONUS}

fclean: clean
	${MAKE} ${LIBFT_PATH} fclean
	${RM} ${NAME}
	${RM} ${NAME_BONUS}

re: fclean all