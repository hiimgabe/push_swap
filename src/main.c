/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:36:24 by gabe              #+#    #+#             */
/*   Updated: 2023/11/02 14:24:54 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_node  *a;
    t_node  *b;
    int i = 1;

    a = NULL;
    b = NULL;
    if (argc < 2 || (argc == 2 && !argv[1][0]))
        return (1);
    if (argc == 2)
        argv = ft_split_argv(argv[1], ' ');
    //ft_init_stack(a)
    /*if (!(ft_is_sorted(a)))
    {
        if (ft_lstsize(a) == 2)
            //sa
        else if (ft_lstsize == 3)
            //tiny_sort
        else
            //push_swap
    }*/
    while (argv[i] != 0)
    {
        ft_insert_end(&a, ft_atol(argv[i]));
        ft_insert_end(&b, ft_atol(argv[i]));
        i++;
    }
    rr(&a, &b, true);
    while (a)
    {
        ft_printf("a: %d\n", a->value);
        a = a->next;
    }
    ft_printf("\n\n");
    while (b)
    {
        ft_printf("b: %d\n", b->value);
        b = b->next;
    }
    free(a);
    free(b);
    return(0);
}