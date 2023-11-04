/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:52:59 by gabe              #+#    #+#             */
/*   Updated: 2023/11/04 13:31:34 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_node(t_node *a, int i)
{
	while (a && i--)
		a = a->next;
	return (a);
}

int	descent_ocurr(t_node *a, int mid)
{
	int	ocurr;
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

void	best_rotate(t_node **a, int	mid)
{
	int	ascent;
	int	descent;

	ascent = ascent_ocurr(*a, mid);
	descent = descent_ocurr(*a, mid);
	if (ascent < descent)
		while (ascent--)
			ra(a, false);
	else
		while (descent--)
			ra(a, true);
}

void	bubble_sort(int	*stack, int	size)
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
		return NULL;
	while (a)
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
		sorted = sorted_stack(a);
		mid = sorted[ft_lst_size(a) / 2];
		rotate = ft_lst_size(a) / 2;
		while (rotate-- > 0)
		{
			if ((*a)->value < mid)
				pb(a, b);
			else
				best_rotate(a, mid);
		}
		free(sorted);
	}
}