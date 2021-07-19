/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:27:00 by pforesti          #+#    #+#             */
/*   Updated: 2021/07/15 15:28:47 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h> 
int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if ((max - min) < 1)
	{
		*range = NULL;
		return (0);
	}
	*range = malloc((max - min) * sizeof(*range));
	if (!*range)
		return (-1);
	i = -1;
	while (++i < (max - min))
		*range[i] = min + i;
	return (max - min);
}
