/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 21:01:20 by pforesti          #+#    #+#             */
/*   Updated: 2021/07/14 15:16:35 by pforesti         ###   ########.fr       */
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

int	ft_checkbase(char *base, char c, int i)
{
	while (base[i])
	{
		if (c == base[i + 1] || c == '+' || c == '-')
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	n_b;
	int				i;
	unsigned int	n;

	i = 0;
	n_b = ft_strlen(base);
	if (!(n_b > 1))
		return ;
	while (base[i])
	{
		if (!(ft_checkbase(base, base[i], i)))
			return ;
		i++;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		n = nbr * -1;
	}
	else
		n = nbr;
	if (n > (n_b - 1))
		ft_putnbr_base((n / n_b), base);
	write(1, &base[n % n_b], 1);
}
