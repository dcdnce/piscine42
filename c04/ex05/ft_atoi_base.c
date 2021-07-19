/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 22:13:06 by pforesti          #+#    #+#             */
/*   Updated: 2021/07/14 21:56:09 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check(char c, int *sign, unsigned int flag)
{
	if (flag == 1)
		if ((c >= 9 && c <= 13) || (c == ' '))
			return (1);
	if (flag == 2)
	{	
		if (c == '+')
			return (1);
		else if (c == '-')
		{
			*sign *= -1;
			return (1);
		}
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_nb_is_base(char c, char *base, int flag)
{
	int	i;
	int	j;

	i = 0;
	while (flag == 2 && (base[i]))
	{
		if (c == base[i])
			return (i);
		i++;
	}
	while (flag == 1 && (base[i]))
	{
		j = 1;
		if (ft_strlen(base) < 2)
			return (0);
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[i + j] && j++)
			if (base[i] == base[i + j])
				return (0);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	int		sign;
	int		nb;
	char	*digits;
	int		pInBase;

	i = 0;
	nb = 0;
	sign = 1;
	digits = "0123456789";
	if (!(ft_nb_is_base(str[i], base, 1)))
		return (0);
	while (ft_check(str[i], &sign, 1))
		i++;
	while (ft_check(str[i], &sign, 2))
		i++;
	while ((ft_nb_is_base(str[i], base, 2) >= 0))
	{
		nb *= ft_strlen(base);
		pInBase = ft_nb_is_base(str[i], base, 2);
		nb += (unsigned int)((digits[pInBase / 10] - 48) * 10);
		nb += (unsigned int)((digits[pInBase % 10]) - 48);
		i++;
	}
	return ((int)(nb * sign));
}
