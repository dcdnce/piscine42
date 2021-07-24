/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 10:26:27 by pforesti          #+#    #+#             */
/*   Updated: 2021/07/19 14:19:12 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int	nb)
{
	int	d1;
	int	d2;

	d1 = 2;
	d2 = nb / 2;
	if (nb <= 1)
		return (0);
	while (d1 <= d2)
	{
		if (!(nb % d1))
			return (0);
		if (!(nb % d2))
			return (0);
		d1 += 1;
		d2 -= 1;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 1)
		return (0);
	while (!(ft_is_prime(nb)))
		nb += 1;
	return (nb);
}
