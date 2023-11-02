/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:46:53 by gabe              #+#    #+#             */
/*   Updated: 2023/11/02 14:25:12 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_rotate(t_node **stack, bool reverse)
{
	t_node	*first;
	t_node	*last;
	t_node	*second_last;

	if (!stack || !*stack /*|| stack_len == 1*/)
		return ;
	first = *stack;
	last = ft_get_last_node(*stack, false);
	second_last = ft_get_last_node(*stack, true);
	if (!reverse)
	{
		*stack = (*stack)->next;
		last->next = first;
		first->next = NULL;
	}
	else
	{
		last->next = *stack;
		*stack = last;
		second_last->next = NULL;
	}
}

void	ra(t_node **stack, bool reverse)
{
	ft_rotate(stack, reverse);
	if (!reverse)
		ft_printf("ra\n");
	else
		ft_printf("rra\n");
}

void	rb(t_node **stack, bool reverse)
{
	ft_rotate(stack, reverse);
	if (!reverse)
		ft_printf("rb\n");
	else
		ft_printf("rrb\n");
}

void	rr(t_node **stack_a, t_node **stack_b, bool reverse)
{
	ft_rotate(stack_a, reverse);
	ft_rotate(stack_b, reverse);
	if (!reverse)
		ft_printf("rr\n");
	else
		ft_printf("rrr\n");
}