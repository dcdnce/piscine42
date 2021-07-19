/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 11:08:24 by pforesti          #+#    #+#             */
/*   Updated: 2021/07/19 11:08:34 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_stock_str.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

struct	s_stock_str	*ft_strs_to_tab(int	ac, char **av)
{
	t_stock_str	*stocks;
	int			i;

	stocks = malloc((ac + 1) * sizeof(*stocks));
	if (!stocks)
		return (NULL);
	i = -1;
	while (++i < ac)
	{
		stocks[i].size = ft_strlen(av[i]);
		stocks[i].str = av[i];
		stocks[i].copy = malloc((stocks[i].size + 1) * sizeof(*av[i]));
		if (!stocks[i].copy)
			return (NULL);
		ft_strcpy(stocks[i].copy, av[i]);
	}
	stocks[i].str = 0;
	return (stocks);
}
