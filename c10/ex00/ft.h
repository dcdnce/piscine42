#ifndef FT_H
# define FT_H

# include <fcntl.h>
# include <unistd.h>

# define ERR_FNAME "File name missing.\n"
# define ERR_TMAC "Too many arguments.\n"
# define ERR_FNR "Cannot read file.\n"

int	ft_display_file(int fd);

#endif
