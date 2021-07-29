/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 15:35:03 by pforesti          #+#    #+#             */
/*   Updated: 2021/07/28 19:44:10 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	c_sort;
	int	d_sort;

	c_sort = 1;
	d_sort = 1;
	i = -1;
	while (++i < (length - 1))
		if ((*f)(tab[i], tab[i + 1]) > 0)
			c_sort = 0;
	i = -1;
	while (++i < (length - 1))
		if ((*f)(tab[i], tab[i + 1]) < 0)
			d_sort = 0;
	if (c_sort + d_sort == 2)
		return (1);
	return (d_sort + c_sort);
}
