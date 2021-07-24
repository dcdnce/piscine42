/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 17:35:51 by pforesti          #+#    #+#             */
/*   Updated: 2021/07/19 12:51:16 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	n;

	n = 1;
	if (power < 0)
		return (0);
	if (!(power))
		return (n);
	return (nb * ft_recursive_power(nb, power - 1));
}
