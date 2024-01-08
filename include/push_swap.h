/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:05:14 by gabe              #+#    #+#             */
/*   Updated: 2024/01/08 15:06:35 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int				value;
	int				position;
	int				price;
	bool			above_median;
	struct s_node	*next;
	struct s_node	*target;
}	t_node;

// SPLIT
char	**ft_split_argv(char const *str, char c);

// UTILS
int		ft_lst_size(t_node *stack);
long	ft_atol(const char *str);
bool	ft_is_sorted(t_node *stack);
t_node	*ft_get_last_node(t_node *stack, bool second_last);
t_node	*ft_smallest(t_node *stack);
t_node	*ft_highest(t_node *stack);
t_node	*ft_cheapest(t_node *stack);

// PRICE
void	set_price(t_node *a, t_node *b);

// EXIT
void	clear_stack(t_node **stack);
void	free_array(char **argv);
void	exit_error(t_node **stack);

// INIT
void	init_nodes(t_node **a, t_node **b);
void	ft_insert_end(t_node **root, long value);
void	set_position(t_node *stack);
void	set_target(t_node *a, t_node *b);

// STACK
void	ft_init_stack(t_node **stack, char **argv, bool split);
void	smallest_to_top(t_node **stack, t_node *smallest, char c);

// SWAP
void	ft_swap(t_node **stack);
void	ft_push(t_node **push, t_node **stack);
void	ft_rotate(t_node **stack, bool reverse);
void	ft_rotate_both(t_node **a, t_node **b, bool reverse, bool silent);
void	sa(t_node **stack, bool silent);
void	sb(t_node **stack, bool silent);
void	ss(t_node **stack_a, t_node **stack_b, bool silent);
void	pb(t_node **stack_a, t_node **stack_b, bool silent);
void	pa(t_node **stack_a, t_node **stack_b, bool silent);
void	ra(t_node **stack, bool reverse, bool silent);
void	rb(t_node **stack, bool reverse, bool silent);
void	rr(t_node **a, t_node **b, bool reverse, bool silent);

// TINY SORT
void	tiny_sort(t_node **a);
void	small_sort(t_node **a, t_node **b);

void	push_to_b(t_node **a, t_node **b);
int		descent_ocurr(t_node *a, int mid);
int		ascent_ocurr(t_node *a, int mid);
t_node	*get_node(t_node *a, int i);

// PUSH
void	push_swap(t_node **a, t_node **b);

#endif