/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:37:56 by gabe              #+#    #+#             */
/*   Updated: 2023/11/02 14:15:50 by gabe             ###   ########.fr       */
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
	new_node->next = NULL;
	new_node->value = (int)nb;
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
	return(stack);
}