/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:42:26 by gabe              #+#    #+#             */
/*   Updated: 2024/01/08 14:47:04 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tiny_sort(t_node **a)
{
	t_node	*highest;

	highest = ft_highest(*a);
	if (highest == *a)
		ra(a, false, false);
	else if (highest == (*a)->next)
		ra(a, true, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false);
}

void	small_sort(t_node **a, t_node **b)
{
	while (ft_lst_size(*a) > 3)
	{
		init_nodes(a, b);
		smallest_to_top(a, ft_smallest(*a), 'a');
		pb(a, b, false);
	}
}
