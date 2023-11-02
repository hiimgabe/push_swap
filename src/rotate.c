/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:46:53 by gabe              #+#    #+#             */
/*   Updated: 2023/11/02 13:52:22 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	first = *stack;
	last = ft_get_last_node(stack);
	*stack = (*stack)->next;
	last->next = first;
}

void	ra(t_node **stack)
{
	ft_rotate(stack);
	ft_printf("ra\n");
}