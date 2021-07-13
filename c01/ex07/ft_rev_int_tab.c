/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <pforesti@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 21:30:33 by pforesti          #+#    #+#             */
/*   Updated: 2021/07/08 09:52:28 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int		l;
	int		temp;

	l = 0;
	while (l < size)
	{
		temp = tab[l];
		tab[l] = tab[size - 1];
		tab[size - 1] = temp;
		l++;
		size--;
	}
}
