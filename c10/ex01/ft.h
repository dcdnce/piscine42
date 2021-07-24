/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:11:04 by pforesti          #+#    #+#             */
/*   Updated: 2021/07/23 22:51:20 by pforesti         ###   ########.fr       */
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

int		ft_strcmp(char *s1, char *s2);
int		ft_error(int source, char **av, int i, char *error);
void	ft_putstr(char *str, int descriptor);
int		ft_display_file(int fd_in, int fd_out);

# define TAILLE_BUF 30000 

#endif
