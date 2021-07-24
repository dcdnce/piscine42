/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 13:45:08 by pforesti          #+#    #+#             */
/*   Updated: 2021/07/19 19:14:12 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;

	i = -1;
	if ((max - min) < 1)
		return (NULL);
	tab = malloc((max - min) * sizeof(tab));
	if (!tab)
		return (NULL);
	while (++i < (max - min))
		tab[i] = min + i;
	return (tab);
}
