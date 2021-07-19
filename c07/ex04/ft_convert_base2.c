/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 01:18:45 by pforesti          #+#    #+#             */
/*   Updated: 2021/07/18 03:45:43 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_strlen(char *str);

int	ft_nbrlen(int n, char *base_to)
{
	if (n < ft_strlen(base_to))
		return (1);
	return (1 + ft_nbrlen(n / ft_strlen(base_to), base_to));
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_check(unsigned char c, char *base)
{
	int	i;

	i = -1;
	if (c == '+')
		return (1);
	else if (c == '-')
		return (2);
	while (base[++i])
		if (c == base[i])
			return (3);
	return (0);
}
