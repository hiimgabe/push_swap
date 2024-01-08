/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:59:48 by gabe              #+#    #+#             */
/*   Updated: 2024/01/08 14:41:27 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	howmanywords(char const *str, char c)
{
	size_t	wrdcnt;
	size_t	i;

	wrdcnt = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			wrdcnt++;
			while (str[i] && str[i] != c)
				i++;
		}
		else
			i++;
	}
	return (wrdcnt);
}

static char	*addword(char const *str, char c)
{
	char	*word;
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	word = (char *) malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split_argv(char const *str, char c)
{
	size_t	w;
	char	**res;

	w = 0;
	res = (char **) malloc(sizeof(char *) * (howmanywords(str, c) + 2));
	if (!res || !str)
		return (NULL);
	res[w++] = "\0";
	while (*str)
	{
		if (*str != c)
		{
			res[w] = addword(str, c);
			while (*str && *str != c)
				str++;
			w++;
		}
		else
			str++;
	}
	res[w] = 0;
	return (res);
}
