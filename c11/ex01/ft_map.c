/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 14:28:14 by pforesti          #+#    #+#             */
/*   Updated: 2021/07/24 14:45:27 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int	*fooled;
	int	i;

	fooled = malloc(sizeof(*fooled) * length);
	i = -1;
	while (++i < length)
		fooled[i] = (*f)(tab[i]);
	return (fooled);
}
