/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:13:00 by gabe              #+#    #+#             */
/*   Updated: 2023/12/11 10:12:14 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_stack(t_node **stack)
{
	t_node	*next;
	t_node	*current;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

void	free_array(char **argv)
{
	int	i;

	i = 1;
	if (!argv)
		return ;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	exit_error(t_node **stack)
{
	clear_stack(stack);
	ft_printf("Error\n");
	exit (0);
}
