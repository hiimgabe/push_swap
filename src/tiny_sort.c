/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:42:26 by gabe              #+#    #+#             */
/*   Updated: 2023/11/02 15:05:14 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_highest(t_node *stack)
{
    int highest;

    highest = stack->value;
    while (stack)
    {
        if (stack->value > highest)
            highest = stack->value;
        stack = stack->next;
    }
    return (highest);
}

void    tiny_sort(t_node **a)
{
	int	highest;

	highest = ft_highest(*a);
	while (a)
	{
        if ((*a)->value == highest)
            ra(a, false);
        else if ((*a)->next->value == highest)
            ra(a, true);
        else if ((*a)->value > (*a)->next->value)
            sa(a);
        if (ft_is_sorted(*a))
            return ;
	}
}
