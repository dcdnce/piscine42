/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 09:17:50 by ozeng             #+#    #+#             */
/*   Updated: 2021/07/11 11:43:03 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	rushX(const int x)
{
	int	i;

	i = 1;
	if (x > 0)
	{
		ft_putchar('o');
	}
	else
		return (0);
	if (x > 2)
	{
		while (i < x - 1)
		{
			ft_putchar('-');
			i++;
		}
	}
	if (x != 1)
	{
		ft_putchar('o');
	}
	ft_putchar('\n');
	return (1);
}

int	rushY(const int x, const int y)
{
	int	i;
	int	j;

	j = 1;
	if (y > 2 && !(y < 1))
	{
		while (j < y - 1)
		{
			i = 1;
			ft_putchar('|');
			if (x > 2)
			{
				while (i++ < x - 1)
					ft_putchar(' ');
			}
			if (x != 1)
				ft_putchar('|');
			ft_putchar('\n');
			j++;
		}
	}
	else
		return (0);
	return (1);
}

int	rush(const int x, const int y)
{
	if (y > 0)
	{
		if (rushX(x) == 0 )
			return (0);
	}
	rushY(x, y);
	if (y > 1)
	{
		rushX(x);
	}
	return (1);
}
