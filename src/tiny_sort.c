/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:42:26 by gabe              #+#    #+#             */
/*   Updated: 2023/11/03 17:54:01 by gabe             ###   ########.fr       */
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
