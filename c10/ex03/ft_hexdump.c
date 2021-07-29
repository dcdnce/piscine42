#include "ft.h"

void	ft_cutter_str(int nb_read, int arg, char *line)
{
	if (nb_read)
		ft_str_hex(line, arg, nb_read);
	if (arg && nb_read)
		ft_str_p(line, nb_read);
}

void	ft_cutter_offset(int nb_read, int offset, int arg, int other_files)
{
	if (nb_read == 16)
		ft_offset(offset, (7 + arg), arg);
	if (nb_read != 16 && !(other_files > 1))
		ft_offset(offset, (7 + arg), arg);
}

int	ft_cutter_fderror(int nb_read, int *offset, int arg, char *line)
{
	ft_cutter_offset(nb_read, *offset, arg, 0);
	ft_cutter_str(nb_read, arg, line);
	write(1, "\n", 1);
	*offset += nb_read;
	return (*offset);
}

int	ft_getline(int fd, char *line, int *same)
{
	char				c;
	static int			i = -1;
	int					nb_read;
	static char			last[17];

	if (i == 16)
		i = -1;
	else if (i > 0)
		i -= 1;
	nb_read = 1;
	while (++i < 16)
	{
		nb_read = read(fd, &c, 1);
		if (!nb_read)
			break ;
		line[i] = c;
	}
	if (!(ft_strcmp(line, last)))
		*same = 1;
	else
		*same = 0;
	ft_strcpy(last, line);
	return (i);
}

int	ft_hexdump(int fd, int other_files, int arg)
{
	static char	line[17];
	static int	nb_read = 0;
	static int	offset = 0;
	static int	same = 0;

	if (fd == -1)
		return (ft_cutter_fderror(nb_read, &offset, arg, line));
	nb_read = 16;
	while (nb_read == 16)
	{
		nb_read = ft_getline(fd, line, &same);
		if (!(same))
		{
			ft_cutter_offset(nb_read, offset, arg, other_files);
			if (nb_read != 16 && other_files > 1)
				break ;
			ft_cutter_str(nb_read, arg, line);
			write(1, "\n", 1);
		}
		else if (nb_read)
			write(1, "*\n", 2);
		offset += nb_read;
	}
	return (offset);
}
