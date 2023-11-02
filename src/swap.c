/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:52:30 by gabe              #+#    #+#             */
/*   Updated: 2023/11/02 14:50:47 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_node **stack)
{
	t_node	*temp;

	if (!stack || !*stack)
		return ;
	if ((* stack)->next)
	{
		temp = *stack;
		*stack = (* stack)->next;
		temp->next = (* stack)->next;
		(* stack)->next = temp;
	}
}

void	sa(t_node **stack)
{
	ft_swap(stack);
	ft_printf("sa\n");
}

void	sb(t_node **stack)
{
	ft_swap(stack);
	ft_printf("sb\n");
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_printf("ss\n");
}