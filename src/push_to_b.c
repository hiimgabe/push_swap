/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:52:59 by gabe              #+#    #+#             */
/*   Updated: 2024/01/08 14:58:25 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_node(t_node *a, int i)
{
	while (a && i--)
		a = a->next;
	return (a);
}

void	best_rotate(t_node **a, int mid)
{
	int	ascent;
	int	descent;

	ascent = ascent_ocurr(*a, mid);
	descent = descent_ocurr(*a, mid);
	if (ascent < descent)
		while (ascent--)
			ra(a, false, false);
	else
		while (descent--)
			ra(a, true, false);
}

void	bubble_sort(int *stack, int size)
{
	int	i;
	int	tmp;

	i = 1;
	while (i < size)
	{
		if (stack[i] < stack[i - 1])
		{
			tmp = stack[i];
			stack[i] = stack[i - 1];
			stack[i - 1] = tmp;
			i = 1;
		}
		i++;
	}
}

int	*sorted_stack(t_node *a)
{
	int	*sorted;
	int	i;
	int	size;

	i = 0;
	size = ft_lst_size(a);
	sorted = (int *)malloc(sizeof(int) * size);
	if (!sorted)
		return (NULL);
	while (i < size)
	{
		sorted[i] = a->value;
		a = a->next;
		i++;
	}
	bubble_sort(sorted, size);
	return (sorted);
}

void	push_to_b(t_node **a, t_node **b)
{
	int	*sorted;
	int	mid;
	int	rotate;

	while (ft_lst_size(*a) > 3)
	{
		sorted = sorted_stack(*a);
		mid = sorted[ft_lst_size(*a) / 2];
		rotate = ft_lst_size(*a) / 2;
		while (rotate-- > 0)
		{
			if ((*a)->value < mid)
				pb(a, b, false);
			else
				best_rotate(a, mid);
		}
		free(sorted);
	}
}
