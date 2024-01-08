/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:57:52 by gabe              #+#    #+#             */
/*   Updated: 2024/01/08 15:00:13 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	descent_ocurr(t_node *a, int mid)
{
	int		ocurr;
	t_node	*last;

	ocurr = ft_lst_size(a);
	last = ft_get_last_node(a, false);
	while (last->value != a->value)
	{
		if (last->value < mid)
			return (ocurr);
		ocurr--;
		last = get_node(a, ocurr);
	}
	return (0);
}

int	ascent_ocurr(t_node *a, int mid)
{
	int	ocurr;

	ocurr = 0;
	while (a)
	{
		if (a->value < mid)
			return (ocurr);
		ocurr++;
		a = a->next;
	}
	return (0);
}
