/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_verif.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 22:40:34 by pforesti          #+#    #+#             */
/*   Updated: 2021/07/28 22:40:35 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_verif_firstline(char *str)
{
	int	i;
	int	k;

	i = ft_strlen(str) - 3;
	while (str[i])
	{
		k = 0;
		while (str[i + ++k])
			if (str[i] == str[i + k])
				return (-1);
		i++;
	}
	return (0);
}

/* Verify first line of the file; 	*/
/* Stores everything in a t_map:   	*/
/*		- char(s)					*/
/*		- get and check nb of lines	*/
/*		- get length of lines		*/
t_map	*ft_p_firstline(int fd)
{
	char	firstline[TAILLE_BUFFER];
	t_map	*map;
	int		i;
	int		j;
	int		tru_nbl;

	i = ft_getcharunt(fd, '\n', firstline, 1);
	firstline[i] = '\0';
	j = ft_getcharunt(fd, '\n', 0, 0);
	tru_nbl = ft_getcharunt(fd, '\0', 0, 2);
	map = malloc(sizeof(*map));
	(*map).len_l = j;
	(*map).nb_l = ft_atoi_firstline(firstline);
	i = ft_strlen(firstline) - 3;
	(*map).v = firstline[i];
	(*map).o = firstline[i + 1];
	(*map).p = firstline[i + 2];
	if (ft_verif_firstline(firstline)
		|| ((*map).nb_l > tru_nbl && (*map).nb_l != 1))
		map->error = -2;
	else
		map->error = 0;
	close(fd);
	return (map);
}

/* Verify the map -- and malloc the *str_map	*/
/* 		- Matching char(s) for map.v & map.o  	*/
/*		- Matching length of lines       		*/
char	*ft_verif_lines(int fd, t_map *map)
{
	char	*str_map;
	int		i;
	int		j;

	ft_getcharunt(fd, '\n', 0, 0);
	str_map = malloc(((map->len_l + 1) * map->nb_l) * sizeof(*str_map));
	read(fd, str_map, (((map->len_l + 1) * map->nb_l) + 1));
	str_map[((map->len_l + 1) * map->nb_l)] = '\0';
	i = -1;
	while (str_map[++i])
	{
		j = -1;
		while (str_map[i + ++j] != '\n')
			if (str_map[i + j] != map->v && str_map[i + j] != map->o)
				map->error = -2;
		if (j != map->len_l)
			map->error = -2;
		if ((*map).error == -2)
			break ;
		i += j;
	}
	close(fd);
	return (str_map);
}
