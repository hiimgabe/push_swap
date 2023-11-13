/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:17:51 by gabe              #+#    #+#             */
/*   Updated: 2023/11/13 14:19:36 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_line(char *line)
{
	if (!ft_strncmp("sa", line, 3) || !ft_strncmp("sb", line, 3)
		|| !ft_strncmp("ss", line, 3) || !ft_strncmp("pa", line, 3)
		|| !ft_strncmp("pb", line, 3) || !ft_strncmp("ra", line, 3)
		|| !ft_strncmp("rb", line, 3) || !ft_strncmp("rr", line, 3)
		|| !ft_strncmp("rra", line, 3) || !ft_strncmp("rrb", line, 3)
		|| !ft_strncmp("rrr", line, 3))
		return (1);
	return (0);
}

void	exec_command(char *line, t_node **a, t_node **b)
{
	if (!ft_strncmp("sa", line, 3))
		sa(a, true);
	else if (!ft_strncmp("sb", line, 3))
		sb(b, true);
	else if (!ft_strncmp("ss", line, 3))
		ss(a, b, true);
	else if (!ft_strncmp("pa", line, 3))
		pa(a, b, true);
	else if (!ft_strncmp("pb", line, 3))
		pb(a, b, true);
	else if (!ft_strncmp("ra", line, 3))
		ra(a, false, true);
	else if (!ft_strncmp("rb", line, 3))
		rb(b, false, true);
	else if (!ft_strncmp("rr", line, 3))
		rr(a, b, false, true);
	else if (!ft_strncmp("rra", line, 4))
		ra(b, true, true);
	else if (!ft_strncmp("rrb", line, 4))
		rb(b, true, true);
	else if (!ft_strncmp("rrr", line, 4))
		ft_rotate_both(a, b, false, true);
}

void	read_command(t_node **a, t_node **b, int i)
{
	char	*line;
	char	buff;

	line = ft_calloc(sizeof(char *), 4);
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
			line = ft_calloc(sizeof(char *), 4);
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
	if (ft_is_sorted(a) && !b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	clear_stack(&a);
	clear_stack(&b);
	return(0);
}