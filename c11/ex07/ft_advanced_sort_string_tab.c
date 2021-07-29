/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 21:57:27 by pforesti          #+#    #+#             */
/*   Updated: 2021/07/24 22:48:37 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **a, char **b, int *boo)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
	*boo += 1;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	size;
	int	i;
	int	boo;

	size = 0;
	while (tab[size])
		size++;
	boo = 1;
	while (boo)
	{
		boo = 0;
		i = -1;
		while (++i < (size - 1))
			if ((*cmp)(tab[i], tab[i + 1]) > 0)
				ft_swap((tab + i), (tab + i + 1), &boo);
	}
}
