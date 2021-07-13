/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 13:36:05 by pforesti          #+#    #+#             */
/*   Updated: 2021/07/08 09:42:12 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	int		alias;
	int		i;
	int		j;
	char	str[6];

	i = 0;
	if (nb < 0)
		write(1, "-", 1);
	if (nb < 0)
		nb *= -1;
	alias = nb;
	while (alias != 0)
	{
		alias /= 10;
		i++;
	}
	if (!(i))
		i++;
	j = i;
	while (i--)
	{
		str[i] = '0' + nb % 10;
		nb /= 10;
	}
	write(1, str, j * sizeof(char));
}

void	ft_print_comb2(void)
{
	int		a;
	int		b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			if (a < 10)
				write(1, "0", 1);
			ft_putnbr(a);
			write(1, " ", 1);
			if (b < 10)
				write(1, "0", 1);
			ft_putnbr(b);
			if (!(a == 98 && b == 99))
				write(1, ", ", 2);
			b++;
		}
		a++;
	}
}
