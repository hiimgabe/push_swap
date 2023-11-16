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

GREEN		= \033[38;5;47m
YELLOW		= \033[38;5;226m
RED			= \033[38;5;196m
END 		= \033[0m

.c.o:
	@${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}
	@echo "[$(GREEN)compiling$(END)]: $<"

${NAME}: ${OBJ}
	@${MAKE} ${LIBFT_PATH}
	@${CC} ${OBJ} ${LIBFT} -o ${NAME}
	@echo "$(GREEN)$(NAME) created$(END)"

${NAME_BONUS}: ${OBJ_BONUS}
	@${MAKE} ${LIBFT_PATH}
	@${CC} ${OBJ_BONUS} ${LIBFT} -o ${NAME_BONUS}
	@echo "$(GREEN)$(NAME_BONUS) created$(END)"

all: ${NAME}

bonus: ${NAME_BONUS}

clean:
	@${MAKE} ${LIBFT_PATH} clean
	@${RM} ${OBJ}
	@${RM} ${OBJ_BONUS}
	@echo "$(RED)cleaning objects$(END)"

fclean: clean
	@${MAKE} ${LIBFT_PATH} fclean
	@${RM} ${NAME}
	@${RM} ${NAME_BONUS}
	@echo "$(RED)$(NAME) deleted$(END)"
	@echo "$(RED)$(NAME_BONUS) deleted$(END)"

re: fclean all