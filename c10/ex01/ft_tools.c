/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:11:20 by pforesti          #+#    #+#             */
/*   Updated: 2021/07/23 22:55:43 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] == s2[i]) && s1[i] && s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_putstr(char *str, int descriptor)
{
	int	i;

	i = -1;
	while (str[++i])
		write(descriptor, &str[i], 1);
}

int	ft_error(int source, char **av, int i, char *error)
{
	if (source == -1)
	{
		ft_putstr(basename(av[0]), STDERR_FILENO);
		ft_putstr(": ", STDERR_FILENO);
		ft_putstr(basename(av[i]), STDERR_FILENO);
		ft_putstr(": ", STDERR_FILENO);
		ft_putstr(error, STDERR_FILENO);
		write(STDERR_FILENO, "\n", 1);
	}
	return (source);
}
