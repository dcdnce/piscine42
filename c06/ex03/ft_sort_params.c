/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 09:56:55 by pforesti          #+#    #+#             */
/*   Updated: 2021/07/15 11:07:46 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] == s2[i]) && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort(int ac, char **av)
{
	int		i;	
	int		boo;
	char	*temp;

	boo = 1;
	while (boo)
	{
		i = 0;
		boo = 0;
		while (++i != (ac - 1))
		{
			if (ft_strcmp(av[i], av[i + 1]) > 0)
			{
				temp = av[i];
				av[i] = av[i + 1];
				av[i + 1] = temp;
				boo++;
			}
		}
	}
}

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
	int	i;

	i = 0;
	if (ac > 2)
		ft_sort(ac, av);
	while (++i != ac)
	{
		write(1, av[i], ft_strlen(av[i]) * sizeof(char));
		write(1, "\n", 1);
	}
	return (0);
}
