/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 10:13:22 by pforesti          #+#    #+#             */
/*   Updated: 2021/07/13 17:54:34 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	boo;

	if (!*to_find)
		return (str);
	while (*str)
	{
		boo = 0;
		i = 0;
		while (to_find[i])
		{
			if (to_find[i] != str[i])
				boo++;
			i++;
		}
		if (!(boo))
			return (str);
		str++;
	}
	return (0);
}
