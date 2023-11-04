/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:05:14 by gabe              #+#    #+#             */
/*   Updated: 2023/11/04 12:01:33 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_init_stack(t_node **stack, char **argv)
{
	int i;

	i = 0;
	while (argv[++i])
	{
		ft_insert_end(stack, ft_atol(argv[i]));
	}
}

void	init_nodes(t_node **a, t_node **b)
{
	set_position(*a);
	set_position(*b);
	set_target(*a, *b);
	set_price(*a, *b);
}