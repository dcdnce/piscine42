/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 22:43:02 by pforesti          #+#    #+#             */
/*   Updated: 2021/07/19 14:17:12 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_sqrt(int nb)
{
	unsigned int	n;
	unsigned int	nb_u;

	n = 1;
	nb_u = nb;
	if (nb_u <= 0)
		return (0);
	if (nb_u == 1)
		return (1);
	while (n * n < nb_u)
	{
		n++;
		if (n * n == nb_u)
			return (n);
	}
	return (0);
}
