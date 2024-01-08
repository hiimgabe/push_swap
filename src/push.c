/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:19:26 by gabe              #+#    #+#             */
/*   Updated: 2024/01/08 14:43:32 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_node **src, t_node **stack)
{
	t_node	*push;

	if (!src || !stack)
		return ;
	push = *src;
	*src = (*src)->next;
	if (!*stack)
	{
		*stack = push;
		(*stack)->next = NULL;
	}
	else
	{
		push->next = *stack;
		*stack = push;
	}
}

void	pb(t_node **stack_a, t_node **stack_b, bool silent)
{
	ft_push(stack_a, stack_b);
	if (!silent)
		ft_printf("pb\n");
}

void	pa(t_node **stack_a, t_node **stack_b, bool silent)
{
	ft_push(stack_b, stack_a);
	if (!silent)
		ft_printf("pa\n");
}
