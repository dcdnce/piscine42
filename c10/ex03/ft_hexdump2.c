#include "ft.h"

void	ft_offset(int offset, int zero, int arg)
{
	static char			*digits = "0123456789abcdef";
	unsigned int		n;
	int					i;
	char				hex_offset[9];
	int					hm;

	n = offset;
	while (n && --zero)
		n /= 16;
	i = (7 + arg) - zero;
	hm = i;
	hex_offset[i] = '\0';
	while (zero--)
		write(1, "0", 1);
	n = offset;
	while (--i >= 0)
	{
		hex_offset[i] = digits[n % 16];
		n /= 16;
	}
	write(1, hex_offset, hm);
}

void	ft_str_hex(char *line, int arg, int nb_read)
{
	static char	*digits = "0123456789abcdef";
	int			i;

	if (arg)
		write(1, " ", 1);
	i = -1;
	while (++i < nb_read)
	{
		write(1, " ", 1);
		write(1, &digits[(unsigned char)line[i] / 16], 1);
		write(1, &digits[(unsigned char)line[i] % 16], 1);
		if (i == 7 && arg)
			write(1, " ", 1);
	}
	while (nb_read++ < 16)
	{
		write(1, "   ", 3);
		if (nb_read == 8 && arg)
			write(1, " ", 1);
	}
}

void	ft_str_p(char *line, int nb_read)
{
	int				i;
	unsigned char	c;

	write(1, "  |", 3);
	i = -1;
	while (++i < nb_read)
	{
		c = (unsigned char)line[i];
		if ((c >= 32 && c <= 126))
			write(1, &c, 1);
		else
			write(1, ".", 1);
	}
	write(1, "|", 1);
}
