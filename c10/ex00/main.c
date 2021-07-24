/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 14:13:57 by pforesti          #+#    #+#             */
/*   Updated: 2021/07/21 20:23:17 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft.h"
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	int		fd;

	fd = open(av[1], 0);
	if (ac < 2 || ac > 2 || fd == -1)
	{
		if (ac < 2)
			write(STDERR_FILENO, ERR_FNAME, ft_strlen(ERR_FNAME));
		else if (ac > 2)
			write(STDERR_FILENO, ERR_TMAC, ft_strlen(ERR_TMAC));
		else if (fd == -1)
			write(STDERR_FILENO, ERR_FNR, ft_strlen(ERR_FNR));
		return (-1);
	}
	ft_display_file(fd);
	close(fd);
	return (0);
}
