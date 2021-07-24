/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:11:04 by pforesti          #+#    #+#             */
/*   Updated: 2021/07/23 22:33:22 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_H
# define FT_H

# include <libgen.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>

int		ft_atoi(char *str);

int		ft_strcmp(char *s1, char *s2);
int		ft_error(int source, char **av, int i, char *error);
void	ft_putstr(char *str, int descriptor);
int		ft_strlen(char *str);
void	ft_empty_string(char *buffer, int len_buffer);

int		ft_file_opener(char **av, int i);
char	*ft_to_EOF(int fd);
void	ft_tail(char *buffer, char *path, int nb_bytes, int ac);

# define TAILLE_BUF 2048

#endif
