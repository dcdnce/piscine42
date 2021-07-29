/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 22:40:01 by pforesti          #+#    #+#             */
/*   Updated: 2021/07/28 22:40:06 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	main(int ac, char **av)
{
	int	i;
	int	retv;

	i = 0;
	if (ac == 1)
	{
		retv = ft_parsing_stdin("stdin.bsq.tmp");
		if (retv == -1)
			write(1, FERR, ft_strlen(FERR));
	}
	while (++i < ac)
	{
		retv = ft_parsing(av[i]);
		if (retv == -2)
			write(1, MERR, ft_strlen(MERR));
		else if (retv == -1)
			write(1, FERR, ft_strlen(FERR));
		if (i < ac - 1)
			write(1, "\n", 1);
	}
	return (0);
}
