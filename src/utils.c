/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:12:31 by gabe              #+#    #+#             */
/*   Updated: 2024/01/08 14:52:27 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	int		signs;
	long	n;

	signs = 1;
	n = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == 45 || *str == 43)
	{
		if (*str == 45)
			signs *= -signs;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		n *= 10;
		n = n + (*str - 48);
		str++;
	}
	return (n * signs);
}

t_node	*ft_highest(t_node *stack)
{
	t_node	*highest;

	highest = stack;
	while (stack)
	{
		if (stack->value > highest->value)
			highest = stack;
		stack = stack->next;
	}
	return (highest);
}

t_node	*ft_smallest(t_node *stack)
{
	t_node	*smallest;

	smallest = stack;
	while (stack)
	{
		if (stack->value < smallest->value)
			smallest = stack;
		stack = stack->next;
	}
	return (smallest);
}
