/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:05:14 by gabe              #+#    #+#             */
/*   Updated: 2023/11/01 15:10:02 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_init_stack(t_node *stack, char **argv)
{
	long	nb;
	int i;

	i = 1;
	while (argv[i])
	{
		nb = ft_atol(argv[i]);
		ft_insert_end(&stack, nb);
	}
}