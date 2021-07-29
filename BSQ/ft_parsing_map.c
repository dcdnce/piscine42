/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 22:40:28 by pforesti          #+#    #+#             */
/*   Updated: 2021/07/28 22:40:29 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	**ft_p_map_obst(int **t, t_map map, char *str_map)
{
	int		x;
	int		y;
	int		obst;
	char	*a;

	y = 0;
	a = str_map;
	while (++y < (map.nb_l + 1))
	{
		obst = 0;
		x = 1;
		while (*a != '\n')
		{
			if (*a == map.o)
				obst += 1;
			t[y][x] = t[y - 1][x] + obst;
			x += 1;
			a++;
		}
		a++;
	}
	return (t);
}

/* Malloc and initialize the **t		*/
/*		- will contains binaries value	*/
int	**ft_p_map(t_map map, char *str_map)
{
	int	**t;
	int	i;

	t = malloc(sizeof(*t) * (map.nb_l + 1));
	if (!t)
		return (NULL);
	i = -1;
	while (++i < (map.nb_l + 1))
	{
		t[i] = malloc(sizeof(int) * (map.len_l + 1));
		if (!t[i])
			return (NULL);
	}
	i = -1;
	while (++i < (map.len_l + 1))
		t[0][i] = 0;
	i = -1;
	while (++i < (map.nb_l + 1))
		t[i][0] = 0;
	t = ft_p_map_obst(t, map, str_map);
	return (t);
}
