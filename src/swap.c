/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreir <gamoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:52:30 by gabe              #+#    #+#             */
/*   Updated: 2023/11/09 11:30:45 by gamoreir         ###   ########.fr       */
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

void	sa(t_node **stack, bool silent)
{
	ft_swap(stack);
	if (!silent)
		ft_printf("sa\n");
}

void	sb(t_node **stack, bool silent)
{
	ft_swap(stack);
	if (!silent)
		ft_printf("sb\n");
}

void	ss(t_node **stack_a, t_node **stack_b, bool silent)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	if (!silent)
		ft_printf("ss\n");
}