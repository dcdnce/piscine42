/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 00:53:28 by pforesti          #+#    #+#             */
/*   Updated: 2021/07/21 17:15:14 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
int				ft_check(unsigned char c, char *base);
int				ft_nbrlen(unsigned int n, char *base_to);
unsigned int	ft_strlen(char *str);

unsigned int	ft_atoi_base(char *nbr, char *base_from, int *sign)
{
	unsigned int	n;
	int				i;

	n = 0;
	while (*nbr && ((*nbr >= 9 && *nbr <= 13) || *nbr == ' '))
		nbr++;
	while (*nbr && (ft_check(*nbr, base_from) == 2
			|| ft_check(*nbr, base_from) == 1))
	{
		if (ft_check(*nbr, base_from) == 2)
			*sign += 1;
		nbr++;
	}
	while (*nbr && ft_check(*nbr, base_from) == 3)
	{
		i = -1;
		n *= ft_strlen(base_from);
		while (base_from[++i])
			if (*nbr == base_from[i])
				break ;
		n += i;
		nbr++;
	}
	return (n);
}

int	ft_check_base(char *base)
{
	int	i;
	int	k;

	i = -1;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[++i])
	{
		k = 1;
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| (base[i] >= 9 && base[i] <= 13))
			return (0);
		while (base[i + k])
		{
			if (base[i] == base[i + k])
				return (0);
			k++;
		}
	}
	return (1);
}

char	*ft_putnbr_base(char *dest, unsigned int n, char *base_to, int len)
{
	unsigned int	len_bt;

	len_bt = ft_strlen(base_to);
	dest[len] = base_to[n % len_bt];
	if (n < (len_bt - 1))
		return (dest);
	return (ft_putnbr_base(dest, (n / len_bt), base_to, len - 1));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int				sign;
	unsigned int	n;	
	int				len;
	char			*dest;

	sign = 0;
	if (!(ft_check_base(base_from)) || !(ft_check_base(base_to)))
		return (NULL);
	n = ft_atoi_base(nbr, base_from, &sign);
	len = ft_nbrlen(n, base_to) + 1;
	if (n != 0)
		len += sign % 2;
	dest = malloc(sizeof(*dest) * len);
	if (!dest)
		return (NULL);
	if ((sign % 2) && n != 0)
		dest[0] = '-';
	dest[len - 1] = '\0';
	ft_putnbr_base(dest, n, base_to, (len - 2));
	return (dest);
}
