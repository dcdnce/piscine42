#include "ft.h"

void	ft_is_fd_good(int arg, int offset)
{
	ft_offset(offset, (7 + arg), arg);
	write(1, "\n", 1);
}

int	ft_stdin(void)
{
	char	buffer[TAILLE_BUF];
	int		nb_read;
	int		fd;

	fd = open("tmp.stdin", O_WRONLY | O_CREAT, 0644);
	nb_read = 1;
	while (nb_read)
	{
		nb_read = read(STDIN_FILENO, buffer, TAILLE_BUF);
		if (nb_read)
			write(fd, buffer, nb_read);
	}
	close(fd);
	fd = open("tmp.stdin", O_RDONLY);
	return (fd);
}

void	ft_check_bfd(int is_fd_good, int ac, int i, char **av)
{
	if (is_fd_good == ac - 1 && ac != 1)
		ft_error(-1, av, i - 1, "Bad file descriptor");
}

int	main(int ac, char **av)
{
	int		i;
	t_prog	prog;

	prog.is_fd_good = ac - 1;
	prog.arg = 0;
	if (ac > 1 && ft_strcmp("-C", av[1]) == 0)
		prog.arg = 1;
	i = prog.arg;
	if (ac == 1)
		prog.offset = ft_hexdump(ft_stdin(), ac - i, prog.arg);
	while (++i < ac)
	{
		prog.fd = open(av[i], O_RDONLY);
		if (prog.fd != -1)
			prog.is_fd_good -= 1;
		if ((ft_error(prog.fd, av, i, strerror(errno)) != -1))
			prog.offset = ft_hexdump(prog.fd, ac - i, prog.arg);
		if (prog.fd == -1 && !(ac - i > 1) && prog.is_fd_good != ac - 1)
			prog.offset = ft_hexdump(prog.fd, ac - i, prog.arg);
		close(prog.fd);
	}
	if ((prog.is_fd_good != ac - 1 || ac == 1) && (i - prog.arg != 0))
		ft_is_fd_good(prog.arg, prog.offset);
	ft_check_bfd(prog.is_fd_good, ac, i, av);
	return (0);
}
