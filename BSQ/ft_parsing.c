/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 22:40:23 by pforesti          #+#    #+#             */
/*   Updated: 2021/07/28 22:40:24 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_read_to_file(int	fd)
{
	char	buffer[TAILLE_BUFFER];
	int		nb_read;

	nb_read = 1;
	while (nb_read)
	{
		nb_read = read(STDIN_FILENO, buffer, TAILLE_BUFFER);
		if (nb_read)
			write(fd, buffer, nb_read);
	}
	close(fd);
}

int	ft_parsing_stdin(char *path)
{
	int			fd;
	t_map		*map;
	t_square	square;
	int			**t;
	char		*str_map;

	fd = open(path, O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
		return (-1);
	ft_read_to_file(fd);
	fd = open(path, O_RDONLY);
	map = ft_p_firstline(fd);
	if (map->error == -2)
		return (-2);
	fd = open(path, O_RDONLY);
	str_map = ft_verif_lines(fd, map);
	if (map->error)
		return (-2);
	t = ft_p_map(*map, str_map);
	square = ft_find_square(t, (*map).len_l + 1, (*map).nb_l + 1);
	ft_show_map(square, *map, str_map);
	free(map);
	free(t);
	free(str_map);
	return (1);
}

int	ft_parsing(char *path)
{
	int			fd;
	t_map		*map;
	t_square	square;
	int			**t;
	char		*str_map;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	map = ft_p_firstline(fd);
	if (map->error == -2)
		return (-2);
	fd = open(path, O_RDONLY);
	str_map = ft_verif_lines(fd, map);
	if (map->error)
		return (-2);
	t = ft_p_map(*map, str_map);
	square = ft_find_square(t, (*map).len_l + 1, (*map).nb_l + 1);
	ft_show_map(square, *map, str_map);
	free(map);
	free(t);
	free(str_map);
	return (1);
}
