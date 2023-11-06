/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:36:24 by gabe              #+#    #+#             */
/*   Updated: 2023/11/06 17:35:56 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_node  *a;
	t_node  *b;

	a = NULL;
	b = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
		argv = ft_split_argv(argv[1], ' ');
	ft_init_stack(&a, argv);
	if (!ft_is_sorted(a))
	{
		if (ft_lst_size(a) == 2)
			sa(&a);
		else if(ft_lst_size(a) == 3)
			tiny_sort(&a);
		else
			push_swap(&a, &b);
	}
	free(a);
	free(b);
	return(0);
}