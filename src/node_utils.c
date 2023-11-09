/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreir <gamoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:37:56 by gabe              #+#    #+#             */
/*   Updated: 2023/11/09 11:33:33 by gamoreir         ###   ########.fr       */
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
		stack = stack->next;
		i++;
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
		stack->position = pos;
		if (pos < median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		pos++;
	}
}

void	smallest_to_top(t_node **stack, t_node *smallest, char c)
{
	while (*stack != smallest)
	{
		if (c == 'a')
		{
			if (smallest->above_median)
				ra(stack, false, false);
			else
				ra(stack, true, false);
		}
		else
		{
			if (smallest->above_median)
				rb(stack, false, false);
			else
				rb(stack, true, false);
		}
	}
}

t_node	*ft_cheapest(t_node *stack)
{
	t_node	*cheapest;

	cheapest = stack;
	while (stack)
	{
		if (stack->price < cheapest->price)
			cheapest = stack;
		stack = stack->next;
	}
	return (cheapest);
}