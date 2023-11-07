/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:05:14 by gabe              #+#    #+#             */
/*   Updated: 2023/11/07 16:26:46 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	check_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((!ft_isdigit(*str) && *str != 45) || (str[i] == 45 && !ft_isdigit(str[i + 1])))
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