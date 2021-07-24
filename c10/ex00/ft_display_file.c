/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 15:07:02 by pforesti          #+#    #+#             */
/*   Updated: 2021/07/21 15:28:19 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft.h"

int	ft_display_file(int fd)
{
	int		readValue;
	char	c;

	readValue = 1;
	while (readValue)
	{
		readValue = read(fd, &c, 1);
		c = (unsigned char)c;
		if (!readValue)
			break ;
		write(1, &c, 1);
	}
	return (readValue);
}
