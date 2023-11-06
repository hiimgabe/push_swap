/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:05:14 by gabe              #+#    #+#             */
/*   Updated: 2023/11/06 22:38:14 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_stack(t_node **stack)
{
	t_node	*next;
	t_node	*current;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

void	free_array(char **argv)
{
	int	i;

	i = 1;
	if (!argv)
		return ;
	free(*argv);
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	exit_error(t_node **stack)
{
	clear_stack(stack);
	ft_printf("Error\n");
	exit (0);
}

static bool	check_char(char *str)
{
	while (*str != 0)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

static bool	is_duplicate(t_node *stack, long nb)
{
	while (stack)
	{
		if (stack->value == nb)
			return (true);
		stack = stack->next;
	}
	return (false);
}

void    ft_init_stack(t_node **stack, char **argv, bool split)
{
	long	nb;
	int 	i;

	i = 1;
	while (argv[i])
	{
		nb = ft_atol(argv[i]);
		if (nb < INT_MIN || nb > INT_MAX || is_duplicate(*stack, nb) || !check_char(argv[i]))
			exit_error(stack);
		ft_insert_end(stack, nb);
		i++;
	}
	if (split)
		free_array(argv);
}

void	init_nodes(t_node **a, t_node **b)
{
	set_position(*a);
	set_position(*b);
	set_target(*a, *b);
	set_price(*a, *b);
}