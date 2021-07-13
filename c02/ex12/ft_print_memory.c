/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 11:54:21 by pforesti          #+#    #+#             */
/*   Updated: 2021/07/13 18:35:35 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_printaddr(char *str)
{
	int		l;
	int		temp;
	int		os;
	int		len;
	int		len_alias;

	len = 0;
	while (str[len])
		len++;
	len_alias = len;
	l = 0;
	os = 16 - len;
	while (os--)
		write(1, "0", 1);
	while (l < len)
	{
		temp = str[l];
		str[l] = str[len - 1];
		str[len - 1] = temp;
		l++;
		len--;
	}
	write(1, str, len_alias * sizeof(char));
	write(1, ": ", 2);
}

void	ft_puthexa_nbr(unsigned long nb, char *hexaddr, int i)
{
	char	*digits;

	digits = "0123456789abcdef";
	if (nb > 15)
		ft_puthexa_nbr((nb / 16), hexaddr, (i + 1));
	hexaddr[i] = digits[nb % 16];
	if (nb < 15)
	{
		hexaddr[i + 1] = '\0';
	}
}

void	ft_puthexa_str(void	*addr, unsigned int size)
{
	char				*p;
	char				*digits;
	unsigned int		i;

	digits = "0123456789abcdef";
	i = 0;
	p = addr;
	if (size > 15)
		size = 16;
	while (i++ < size)
	{
		write(1, &digits[(unsigned char)*p / 16], 1);
		write(1, &digits[(unsigned char)*p % 16], 1);
		if (!(i % 2))
			write(1, " ", 1);
		p++;
	}
	if ((size < 16) && (size % 2))
		write(1, " ", 1);
	while (size++ < 16)
	{
		write(1, "  ", 2);
		if (size % 2)
			write(1, " ", 1);
	}
}

void	ft_putstr(void	*addr, unsigned int size)
{
	char				*p;
	unsigned int		i;

	p = addr;
	i = 0;
	if (size > 15)
		size = 16;
	while (i++ < size)
	{
		if (*p >= 32 && *p <= 126)
			write(1, p, 1);
		else
			write(1, ".", 1);
		p++;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned long	uiaddr;
	char			hexaddr[17];
	int				l;
	int				t;

	if (size)
	{
		size += 16;
		t = (size / 16);
		while (t--)
		{
			if ((size / 16))
				size -= 16;
			else
				size %= 16;
			l = 0;
			uiaddr = (unsigned long)addr;
			ft_puthexa_nbr(uiaddr, hexaddr, 0);
			ft_printaddr(hexaddr);
			ft_puthexa_str(addr, size);
			ft_putstr(addr, size);
			addr += 16;
		}
	}
	return (addr);
}
