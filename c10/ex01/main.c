/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 09:28:54 by pforesti          #+#    #+#             */
/*   Updated: 2021/07/23 22:52:29 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft.h"

int	main(int ac, char **av)
{
	int		fd;
	int		read_return;
	char	*bin;
	int		i;

	bin = av[0];
	while (ac == 1)
		ft_display_file(STDIN_FILENO, STDOUT_FILENO);
	i = 1;
	while (ac > 1 && i < ac)
	{
		while (ft_strcmp("-", av[i]) == 0)
			ft_display_file(STDIN_FILENO, STDOUT_FILENO);
		fd = open(av[i], O_RDONLY);
		if (ft_error(fd, av, i, strerror(errno)) == -1)
			return (-1);
		read_return = ft_display_file(fd, STDOUT_FILENO);
		if (ft_error(read_return, av, i, strerror(errno)) == -1)
			return (-1);
		close(fd);
		i++;
	}
	return (0);
}
