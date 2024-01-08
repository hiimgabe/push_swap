/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:36:02 by gabe              #+#    #+#             */
/*   Updated: 2024/01/08 14:43:50 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	finish_rotation(t_node **stack, t_node *cheapest, char c)
{
	while (*stack != cheapest)
	{
		if (c == 'a')
		{
			if (cheapest->above_median)
				ra(stack, false, false);
			else
				ra(stack, true, false);
		}
		else
		{
			if (cheapest->above_median)
				rb(stack, false, false);
			else
				rb(stack, true, false);
		}
	}
}

void	move_node(t_node **a, t_node **b)
{
	t_node	*cheapest;

	cheapest = ft_cheapest(*b);
	if (cheapest->above_median && cheapest->target->above_median)
		ft_rotate_both(a, b, false, false);
	else if (!cheapest->above_median && !cheapest->target->above_median)
		ft_rotate_both(a, b, true, false);
	finish_rotation(b, cheapest, 'b');
	finish_rotation(a, cheapest->target, 'a');
	pa(a, b, false);
}

void	push_swap(t_node **a, t_node **b)
{
	t_node	*top;

	if (ft_lst_size(*a) == 5)
		small_sort(a, b);
	else
		push_to_b(a, b);
	tiny_sort(a);
	while (*b)
	{
		init_nodes(a, b);
		move_node(a, b);
	}
	set_position(*a);
	top = ft_smallest(*a);
	while (*a != top)
	{
		if (top->above_median)
			ra(a, false, false);
		else
			ra(a, true, false);
	}
}
