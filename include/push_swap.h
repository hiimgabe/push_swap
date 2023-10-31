
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_node
{
    int     value;
    int     position;
    int     price;
    bool    median;
    s_node  next;
    s_node  target;
} t_node;

char	**ft_split_argv(char const *str, char c);
int		ft_atol(const char *str);
void	ft_insert_end(t_node **root, int value);

#endif