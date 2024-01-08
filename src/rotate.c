/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:46:53 by gabe              #+#    #+#             */
/*   Updated: 2024/01/08 14:45:37 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_node **stack, bool reverse)
{
	t_node	*rotate;
	t_node	*last;
	t_node	*second_last;

	if (!stack || !*stack || ft_lst_size(*stack) == 1)
		return ;
	rotate = *stack;
	last = ft_get_last_node(*stack, false);
	second_last = ft_get_last_node(*stack, true);
	if (!reverse)
	{
		*stack = (*stack)->next;
		last->next = rotate;
		rotate->next = NULL;
	}
	else
	{
		last->next = *stack;
		*stack = last;
		second_last->next = NULL;
	}
}

void	ra(t_node **stack, bool reverse, bool silent)
{
	ft_rotate(stack, reverse);
	if (!reverse)
	{
		if (!silent)
			ft_printf("ra\n");
	}
	else
	{
		if (!silent)
			ft_printf("rra\n");
	}
}

void	rb(t_node **stack, bool reverse, bool silent)
{
	ft_rotate(stack, reverse);
	if (!reverse)
	{
		if (!silent)
			ft_printf("rb\n");
	}
	else
	{
		if (!silent)
			ft_printf("rrb\n");
	}
}

void	rr(t_node **a, t_node **b, bool reverse, bool silent)
{
	if (!reverse)
	{
		ft_rotate(a, false);
		ft_rotate(b, false);
		if (!silent)
			ft_printf("rr\n");
	}
	else
	{
		ft_rotate(a, true);
		ft_rotate(b, true);
		if (!silent)
			ft_printf("rrr\n");
	}
}

void	ft_rotate_both(t_node **a, t_node **b, bool reverse, bool silent)
{
	t_node	*cheapest;

	cheapest = ft_cheapest(*b);
	while (cheapest != *b && cheapest->target != *a)
		rr(a, b, reverse, silent);
}
