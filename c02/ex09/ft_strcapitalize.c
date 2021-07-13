/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 21:43:47 by pforesti          #+#    #+#             */
/*   Updated: 2021/07/12 21:54:09 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_alpha(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	cap;

	i = 0;
	cap = 0;
	while (str[i] != '\0')
	{
		if (ft_is_alpha(str[i]))
		{
			if (cap == 0 && (str[i] >= 'a' && str[i] <= 'z'))
				str[i] -= 32;
			else if (cap == 1 && (str[i] >= 'A' && str[i] <= 'Z'))
				str[i] += 32;
			cap = 1;
		}
		else
			cap = 0;
		i++;
	}
	return (str);
}
