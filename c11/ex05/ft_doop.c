/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 16:00:35 by pforesti          #+#    #+#             */
/*   Updated: 2021/07/24 18:36:29 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft.h"

void	ft_doop(char **av, int (**op)(int, int))
{
	int		n1;
	int		n2;

	n1 = ft_atoi(av[1]);
	n2 = ft_atoi(av[3]);
	if (!(ft_strcmp("%", av[2])) && !(n2))
		write(1, MOD0, ft_strlen(MOD0));
	else if (!(ft_strcmp("/", av[2])) && !(n2))
		write(1, DIV0, ft_strlen(DIV0));
	else if (!(ft_strcmp("+", av[2])))
		ft_putnbr((*op[op_sum])(n1, n2));
	else if (!(ft_strcmp("-", av[2])))
		ft_putnbr((*op[op_min])(n1, n2));
	else if (!(ft_strcmp("/", av[2])))
		ft_putnbr((*op[op_div])(n1, n2));
	else if (!(ft_strcmp("*", av[2])))
		ft_putnbr((*op[op_mul])(n1, n2));
	else if (!(ft_strcmp("%", av[2])))
		ft_putnbr((*op[op_mod])(n1, n2));
	else
		ft_putnbr(0);
}

int	main(int ac, char **av)
{
	int	(*op[5])(int, int);

	op[0] = &sum;
	op[1] = &min;
	op[2] = &div;
	op[3] = &mul;
	op[4] = &mod;
	if (ac != 4)
		return (-1);
	ft_doop(av, op);
	write(1, "\n", 1);
	return (0);
}
