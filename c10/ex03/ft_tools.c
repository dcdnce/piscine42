#include "ft.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_empty_string(char *buffer, int	len_buffer)
{
	int	i;

	i = -1;
	while (++i < len_buffer - 1)
		buffer[i] = 0;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] == s2[i]) && s1[i] && s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

int	ft_error(int source, char **av, int i, char *error)
{
	if (source == -1)
	{
		ft_putstr(basename(av[0]), STDERR_FILENO);
		ft_putstr(": ", STDERR_FILENO);
		ft_putstr(basename(av[i]), STDERR_FILENO);
		ft_putstr(": ", STDERR_FILENO);
		ft_putstr(error, STDERR_FILENO);
		write(STDERR_FILENO, "\n", 1);
	}
	return (source);
}

void	ft_putstr(char *str, int descriptor)
{
	int	i;

	i = -1;
	while (str[++i])
		write(descriptor, &str[i], 1);
}
