/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:54:45 by gabe              #+#    #+#             */
/*   Updated: 2024/01/08 15:00:24 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_insert_end(t_node **stack, long nb)
{
	t_node	*last;
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = (int)nb;
	new_node->next = NULL;
	if (!*stack)
		*stack = new_node;
	else
	{
		last = ft_get_last_node(*stack, false);
		last->next = new_node;
	}
}

t_node	*ft_get_last_node(t_node *stack, bool second_last)
{
	if (!stack)
		return (NULL);
	if (!second_last)
		while (stack->next)
			stack = stack->next;
	else
		while (stack->next->next)
			stack = stack->next;
	return (stack);
}
