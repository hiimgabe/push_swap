
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_node
{
	int     value;
	int     position;
	int     price;
	bool    median;
	struct s_node  *next;
	struct s_node  *target;
} t_node;

// SPLIT
char	**ft_split_argv(char const *str, char c);

// UTILS
int		ft_atol(const char *str);

// NODE
void	ft_insert_end(t_node **root, long value);
t_node	*ft_get_last_node(t_node *stack);

// STACK
void    ft_init_stack(t_node *stack, char **argv);

// SWAP
void	ft_swap(t_node **stack);
void    ft_push(t_node **push, t_node **stack);
void	sa(t_node **stack);
void	sb(t_node **stack);
void	ss(t_node **stack_a, t_node **stack_b);
void    pb(t_node **stack_a, t_node **stack_b);
void	pa(t_node **stack_a, t_node **stack_b);

// PUSH

#endif