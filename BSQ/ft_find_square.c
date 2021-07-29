/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 22:40:16 by pforesti          #+#    #+#             */
/*   Updated: 2021/07/28 22:40:19 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	sqr(int **t, int l, int c, int size)
{
	int	ad;
	int	res;

	ad = t[l - 1][c - 1] + t[l + size][c + size];
	res = ad - t[l - 1][c + size] - t[l + size][c - 1];
	return (res);
}

void	ft_init(int *c, int *l, int *size)
{
	*size = 0;
	*c = 1;
	*l = 1;
}

t_square	ft_update_square(t_square square, int l, int c, int size)
{
	square.l = l;
	square.c = c;
	square.size = size;
	return (square);
}

t_square	ft_find_square(int **t, int maxc, int maxl)
{
	int			c;
	int			l;
	int			size;
	t_square	square;

	ft_init(&c, &l, &size);
	square.maxl = maxl;
	square.maxc = maxc;
	while (c < maxc && l < maxl && (l + size < maxl))
	{
		if (sqr(t, l, c, size) <= 0 && (l + size < maxl) && (c + size < maxc))
		{
			square = ft_update_square(square, l, c, size);
			size++;
		}
		else
			c++;
		if (c + size >= maxc)
		{
			c = 1;
			l++;
		}
	}
	return (square);
}

void	ft_show_map(t_square square, t_map map, char *str_map)
{
	char	*a;
	int		x;
	int		y;

	a = str_map;
	y = 0;
	while (++y < square.maxl)
	{
		x = 0;
		while (++x < square.maxc)
		{
			if (y >= square.l && y <= square.l + square.size
				&& x >= square.c && x <= square.c + square.size)
				*str_map = map.p;
			str_map++;
		}
		str_map++;
	}
	write(1, a, (map.len_l + 1) * map.nb_l);
}
