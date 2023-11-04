/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:36:02 by gabe              #+#    #+#             */
/*   Updated: 2023/11/04 13:42:17 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_node(t_node **a, t_node **b)
{
	t_node	*cheapest;

	cheapest = ft_cheapest(b);
	if (cheapest->above_median && cheapest->target->above_median)
		//ft_rotate_both();
}

void	push_swap(t_node **a, t_node **b)
{
	if (ft_lst_size(a) == 5)
		small_sort(a, b);
	else
		push_to_b(a, b);
	tiny_sort(a);
	while (b)
	{
		init_nodes(a, b);
		move_node(a, b);
	}
}