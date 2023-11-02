/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:36:24 by gabe              #+#    #+#             */
/*   Updated: 2023/11/02 15:27:14 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    int i = 0;
    t_node  *a;
    t_node  *b;

    a = NULL;
    b = NULL;
    if (argc < 2 || (argc == 2 && !argv[1][0]))
        return (1);
    if (argc == 2)
        argv = ft_split_argv(argv[1], ' ');
    while(argv[++i])
        ft_insert_end(&a, ft_atol(argv[i]));
    /*if (!(ft_is_sorted(a)))
    {
        if (ft_lstsize(a) == 2)
            //sa
        else if (ft_lstsize == 3)
            //tiny_sort
        else
            //push_swap
    }*/
    if (!ft_is_sorted(a))
    {
        if(ft_lst_size(a) == 3)
            tiny_sort(&a);
    }
    free(a);
    free(b);
    return(0);
}