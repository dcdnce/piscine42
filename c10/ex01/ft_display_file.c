/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:11:15 by pforesti          #+#    #+#             */
/*   Updated: 2021/07/23 22:55:25 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft.h"

int	ft_display_file(int fd_in, int fd_out)
{
	static char	buffer[TAILLE_BUF];
	int			nb_read;

	nb_read = 1;
	while (nb_read > 0)
	{
		nb_read = read(fd_in, buffer, TAILLE_BUF);
		write(fd_out, buffer, nb_read);
	}
	return (nb_read);
}
