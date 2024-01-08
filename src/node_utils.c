/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:37:56 by gabe              #+#    #+#             */
/*   Updated: 2024/01/08 14:55:18 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_is_sorted(t_node *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

int	ft_lst_size(t_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	set_position(t_node *stack)
{
	int	pos;
	int	median;

	if (!stack)
		return ;
	pos = 0;
	median = ft_lst_size(stack) / 2;
	while (stack)
	{
		stack->position = pos;
		if (pos < median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		pos++;
	}
}

void	smallest_to_top(t_node **stack, t_node *smallest, char c)
{
	while (*stack != smallest)
	{
		if (c == 'a')
		{
			if (smallest->above_median)
				ra(stack, false, false);
			else
				ra(stack, true, false);
		}
		else
		{
			if (smallest->above_median)
				rb(stack, false, false);
			else
				rb(stack, true, false);
		}
	}
}

t_node	*ft_cheapest(t_node *stack)
{
	t_node	*cheapest;

	cheapest = stack;
	while (stack)
	{
		if (stack->price < cheapest->price)
			cheapest = stack;
		stack = stack->next;
	}
	return (cheapest);
}
