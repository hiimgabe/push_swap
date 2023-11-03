/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:37:56 by gabe              #+#    #+#             */
/*   Updated: 2023/11/03 17:40:15 by gabe             ###   ########.fr       */
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
		i++;
		stack = stack->next;
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
		if (pos < median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack->position = pos;
		stack = stack->next;
		pos++;
	}
}