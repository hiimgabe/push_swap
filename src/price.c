/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   price.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:37:35 by gabe              #+#    #+#             */
/*   Updated: 2024/01/08 14:54:08 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_price(t_node *a, t_node *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_lst_size(a);
	len_b = ft_lst_size(b);
	while (b)
	{
		b->price = b->position;
		if (!b->above_median)
			b->price = len_b - b->position;
		if (b->target->above_median)
			b->price += b->target->position;
		else
			b->price += len_a - b->target->position;
		b = b->next;
	}
}
