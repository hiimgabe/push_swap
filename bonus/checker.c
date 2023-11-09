/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreir <gamoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:17:51 by gabe              #+#    #+#             */
/*   Updated: 2023/11/09 11:50:11 by gamoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_command(char *line, t_node **a, t_node **b)
{
	if (!ft_strncmp("sa", line, 2))
		sa(&a, true);
	else if (!ft_strncmp("sb", line, 2))
		sb(&b, true);
	else if (!ft_strncmp("ss", line, 2))
		ss(&a, &b, true);
	else if (!ft_strncmp("pa", line, 2))
		pa(&a, &b, true);
	else if (!ft_strncmp("pb", line, 2))
		pb(&a, &b, true);
	else if (!ft_strncmp("ra", line, 2))
		ra(&a, false, true);
	else if (!ft_strncmp("rb", line, 2))
		rb(&b, false, true);
	else if (!ft_strncmp("rr", line, 2))
		rr(&b, false, true);
	else if (!ft_strncmp("rra", line, 3))
		ra(&b, true, true);
	else if (!ft_strncmp("rrb", line, 3))
		rb(&b, true, true);
	else if (!ft_strncmp("rrr", line, 3))
		rotate_both(&a, &b, false, true);
}

void	read_command(t_node **a, t_node **b, int i)
{
	char	*line;
	char	buff;

	line = ft_calloc(sizeof(char), 4);
	while (read(0, &buff, 1))
	{
		if (i >= 3 || buff == '\n')
		{
			line[i] = '\0';
			if (!check_line(line))
			{
				free(line);
				clear_stack(a);
				clear_stack(b);
				ft_printf("Error\n");
				exit(1);
			}
			exec_command(line, a, b);
			free(line);
			line = ft_calloc(sizeof(char), 4);
			i = 0;
		}
		else
			line[i++] = buff;
	}
}

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
	ft_init_stack(&a, argv, argc == 2);
	read_command(&a, &b, 0);
	if (!ft_is_sorted(a))
	{
		if (ft_lst_size(a) == 2)
			sa(&a, false);
		else if(ft_lst_size(a) == 3)
			tiny_sort(&a);
		else
			push_swap(&a, &b);
	}
	clear_stack(&a);
	clear_stack(&b);
	return(0);
}