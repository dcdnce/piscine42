/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 09:48:10 by pforesti          #+#    #+#             */
/*   Updated: 2021/07/15 09:56:28 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
	while (ac > 1)
	{
		write(1, av[ac - 1], ft_strlen(av[ac - 1]) * 1);
		ac--;
		write(1, "\n", 1);
	}
	return (0);
}
