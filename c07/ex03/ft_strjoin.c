/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 15:30:24 by pforesti          #+#    #+#             */
/*   Updated: 2021/07/15 18:20:38 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		i;
	int		len;

	i = -1;
	len = 0;
	while (++i < size)
		len += ft_strlen(strs[i]) - 1;
	if (size > 0)
		len += (size - 1) * ft_strlen(sep) - (size - 1);
	str = malloc((len + 2) * sizeof(str));
	if (!str)
		return (NULL);
	else
		str[0] = '\0';
	i = -1;
	while (++i < size)
	{
		ft_strcat(str, strs[i]);
		if (i < (size - 1))
			ft_strcat(str, sep);
	}
	return (str);
}
