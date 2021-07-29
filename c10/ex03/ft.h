#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <libgen.h>
# include <stdio.h>

# define TAILLE_BUF 30000

typedef struct s_prog
{
	int	arg;
	int	fd;
	int	is_fd_good;
	int	offset;
}				t_prog;

int		ft_strcmp(char *s1, char *s2);
void	ft_empty_string(char *buffer, int	len_buffer);
int		ft_strlen(char *str);
int		ft_error(int source, char **av, int i, char *error);
void	ft_putstr(char *str, int descriptor);
char	*ft_strcpy(char *dest, char *src);

void	ft_cutter_str(int nb_read, int arg, char *line);
void	ft_cutter_offset(int nb_read, int offset, int arg, int other_files);
int		ft_cutter_fderror(int nb_read, int *offset, int arg, char *line);
int		ft_getline(int fd, char *line, int *same);
int		ft_hexdump(int fd, int other_files, int arg);

void	ft_offset(int offset, int zero, int arg);
void	ft_str_hex(char *line, int arg, int nb_read);
void	ft_str_p(char *line, int nb_read);

void	ft_check_bfd(int is_fd_good, int ac, int i, char **av);
int		ft_stdin(void);
void	ft_is_fd_good(int arg, int offset);

#endif