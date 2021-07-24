/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 09:59:15 by pforesti          #+#    #+#             */
/*   Updated: 2021/07/23 22:32:55 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft.h"

int	ft_file_opener(char **av, int i)
{
	int	fd;

	fd = open(basename(av[i]), O_RDONLY);
	if ((ft_error(fd, av, i, strerror(errno))) == -1)
		return (-1);
	return (fd);
}

char	*ft_to_EOF(int fd)
{
	char	*buffer;
	int		nb_read;

	nb_read = 1;
	while (nb_read)
	{
		buffer = malloc(TAILLE_BUF * sizeof(char));
		if (!buffer)
			return (NULL);
		nb_read = read(fd, buffer, TAILLE_BUF);
		if (ft_strlen(buffer) < (TAILLE_BUF - 1))
			break ;
		ft_empty_string(buffer, TAILLE_BUF);
		free(buffer);
	}
	return (buffer);
}

void	ft_tail(char *buffer, char *path, int nb_bytes, int ac)
{
	int	i;

	i = ft_strlen(buffer) - nb_bytes - 1;
	if (i < 0)
		i = 0;
	if (ac > 4)
	{
		write(1, "==> ", 4);
		write(1, path, ft_strlen(path));
		write(1, " <==\n", 5);
	}
	while (buffer[++i])
		write(STDOUT_FILENO, &buffer[i], sizeof(char));
	ft_empty_string(buffer, ft_strlen(buffer));
	free(buffer);
}

int	main(int ac, char **av)
{
	int		fd;
	char	*path;
	int		i;
	int		nb_bytes;

	if (ac <= 3 || ft_strcmp("-c", av[1]))
		return (-1);
	nb_bytes = ft_atoi(av[2]);
	i = 2;
	while (ac >= 4 && ++i < ac)
	{
		path = basename(av[i]);
		fd = ft_file_opener(av, i);
		if (fd == -1)
			return (1);
		ft_tail(ft_to_EOF(fd), path, nb_bytes, ac);
		if (i != ac - 1)
			write(1, "\n", 1);
		close(fd);
	}
	return (0);
}
