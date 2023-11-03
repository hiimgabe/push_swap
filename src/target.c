/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:53:21 by gabe              #+#    #+#             */
/*   Updated: 2023/11/03 17:59:41 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target(t_node *a, t_node *b)
{
	long	best_target;
	t_node	*start;
	t_node	*target_node;

	start = a;
	while (b)
	{
		best_target = INT_MAX;		
		while (a)
		{
			if (a->value > b->value && a->value < best_target)
			{
				best_target = a->value;
				target_node = a;
			}
			a = a->next;
		}
		a = start;
		if (best_target == INT_MAX)
			b->target = ft_smallest(a);
		else
			b->target = target_node;
		b = b->next;
	}
}