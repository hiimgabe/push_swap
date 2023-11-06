/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:05:14 by gabe              #+#    #+#             */
/*   Updated: 2023/11/06 17:49:28 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void    ft_init_stack(t_node **stack, char **argv)
{
	long	nb;
	int 	i;

	i = 1;
	while (argv[i])
	{
		nb = ft_atol(argv[i]);
		if (nb < INT_MIN || nb > INT_MAX)
		{
			ft_printf("Error1\n");
			exit (0);
		}
		if (is_duplicate(*stack, nb))
		{
			ft_printf("Error2\n");
			exit (0);
		}
		if (!check_char(argv[i]))
		{
			ft_printf("Error3\n");
			exit (0);
		}
		ft_insert_end(stack, nb);
		i++;
	}
}

void	init_nodes(t_node **a, t_node **b)
{
	set_position(*a);
	set_position(*b);
	set_target(*a, *b);
	set_price(*a, *b);
}