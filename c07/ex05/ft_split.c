/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 03:48:14 by pforesti          #+#    #+#             */
/*   Updated: 2021/07/19 18:49:43 by pforesti         ###   ########.fr       */
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

int	ft_is_charset(unsigned char	c, char *charset)
{
	int	i;

	i = -1;
	while (charset[++i])
		if (c == charset[i])
			return (1);
	return (0);
}

int	ft_strs_count(char *str, char *charset)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	while (str[i])
	{
		if (!(ft_is_charset(str[i], charset)))
			n += 1;
		while (!(ft_is_charset(str[i], charset)) && str[i])
			i++;
		while (ft_is_charset(str[i], charset) && str[i])
			i++;
	}
	return (n);
}

char	*ft_strnup(char *dest, char *src, unsigned int len)
{
	unsigned int	i;

	dest = malloc(sizeof(*dest) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] != '\0' && i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		word;
	int		len;

	split = malloc(sizeof(*split) * (ft_strs_count(str, charset) + 1));
	if (!split)
		return (NULL);
	word = 0;
	while (*str)
	{
		len = 0;
		while (!(ft_is_charset(str[len], charset)) && str[len])
			len++;
		if (len)
		{
			split[word] = ft_strnup(split[word], str, len);
			word += 1;
			str += len;
		}
		while (ft_is_charset(*str, charset) && *str)
			str++;
	}
	split[word] = 0;
	return (split);
}
