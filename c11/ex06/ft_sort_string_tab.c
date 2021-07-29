/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 21:28:30 by pforesti          #+#    #+#             */
/*   Updated: 2021/07/24 21:55:51 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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

void	ft_swap(char **tab, int index1, int index2, int *boo)
{
	char	*temp;

	temp = tab[index1];
	tab[index1] = tab[index2];
	tab[index2] = temp;
	*boo += 1;
}

void	ft_sort_string_tab(char **tab)
{
	int	i;
	int	size;
	int	boo;

	size = 0;
	while (tab[size])
		size++;
	boo = 1;
	while (boo)
	{
		i = -1;
		boo = 0;
		while (++i < (size - 1))
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
				ft_swap(tab, i, i + 1, &boo);
	}
}
