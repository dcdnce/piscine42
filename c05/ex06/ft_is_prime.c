/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 10:26:00 by pforesti          #+#    #+#             */
/*   Updated: 2021/07/19 10:26:15 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int	nb)
{
	int	i;

	i = 2;
	if (nb < 2)
		return (0);
	while (i * i < nb)
	{
		if (!(nb % i))
			return (0);
		i++;
	}
	return (1);
}