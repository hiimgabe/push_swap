/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:42:26 by gabe              #+#    #+#             */
/*   Updated: 2023/11/04 12:14:43 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    tiny_sort(t_node **a)
{
	t_node *highest;

	highest = *a;
	while (a)
	{
        if (*a == highest)
            ra(a, false);
        else if ((*a)->next == highest)
            ra(a, true);
        else if ((*a)->value > (*a)->next->value)
            sa(a);
        if (ft_is_sorted(*a))
            return ;
	}
}

void	small_sort(t_node **a, t_node **b)
{
	while (ft_lst_size(*a) > 3)
	{
		init_nodes(a, b);
		smallest_to_top(a, ft_smallest(*a), 'a');
		pb(a, b);
	}
}