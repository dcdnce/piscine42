/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 11:10:14 by pforesti          #+#    #+#             */
/*   Updated: 2021/07/19 11:10:29 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putnbr(int nb)
{
	char	*digits;

	digits = "0123456789";
	if (nb > 10)
		ft_putnbr(nb / 10);
	write(1, &digits[nb % 10], 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;
	int	s;

	if (!par)
		return ;
	i = 0;
	while (par[i].str != 0)
	{
		s = -1;
		while (par[i].str[++s] != '\0')
			write(1, &par[i].str[s], 1);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		s = -1;
		while (par[i].str[++s] != '\0')
			write(1, &par[i].copy[s], 1);
		write(1, "\n", 1);
		i++;
	}
}
