/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 09:41:58 by pforesti          #+#    #+#             */
/*   Updated: 2021/07/12 09:49:40 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
unsigned int	ft_strlen(char *str)
{
	unsigned int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	n;

	n = ft_strlen(src);
	i = -1;
	if (n + 1 < size)
	{
		while (++i < n + 1)
			dest[i] = src[i];
	}
	else if (size)
	{
		while (++i < size - 1)
			dest[i] = src[i];
		dest[i] = 0;
	}
	return (n);
}
