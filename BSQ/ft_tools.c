/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 22:40:40 by pforesti          #+#    #+#             */
/*   Updated: 2021/07/28 22:40:41 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_atoi_firstline(char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (i < (ft_strlen(str) - 3) && (str[i] >= '0' && str[i] <= '9'))
	{		
		nb *= 10;
		nb += (int)(str[i] - '0');
		i++;
	}
	return (nb);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_getcharunt(int fd, char unt, char *str, int f)
{
	char	c;
	int		i;
	int		n;
	int		value_read;

	c = 1;
	n = 0;
	i = 0;
	value_read = 1;
	while (c != unt && value_read)
	{
		value_read = read(fd, &c, 1);
		if (f == 1)
			str[i] = (unsigned char)c;
		if (f == 2 && c == '\n')
			n += 1;
		i++;
	}
	if (f == 2)
		return (n);
	return (i - 1);
}

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
