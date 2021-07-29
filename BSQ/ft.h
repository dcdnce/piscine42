/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 22:40:11 by pforesti          #+#    #+#             */
/*   Updated: 2021/07/28 22:40:13 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# define FERR "file error\n"
# define MERR "map error\n"
# define TAILLE_BUFFER 2048

typedef struct s_map
{
	int		nb_l;
	int		len_l;
	char	v;
	char	o;
	char	p;
	int		error;
}				t_map;

typedef struct s_square
{
	int	l;
	int	c;
	int	size;
	int	maxl;
	int	maxc;
}				t_square;

t_square	ft_find_square(int **t, int maxc, int maxl);
void		ft_show_map(t_square square, t_map map, char *str_map);
int			sqr(int **t, int l, int c, int size);
void		ft_init(int *c, int *l, int *size);
t_square	ft_update_square(t_square square, int l, int c, int size);

int			ft_verif_firstline(char *str);
char		*ft_verif_lines(int fd, t_map *map);
t_map		*ft_p_firstline(int fd);

void		ft_read_to_file(int	fd);
int			ft_parsing_stdin(char *path);
int			ft_parsing(char *path);

int			**ft_p_map_obst(int **t, t_map map, char *str_map);
int			**ft_p_map(t_map map, char *str_map);

int			ft_strlen(char *str);
int			ft_atoi_firstline(char *str);
int			ft_getcharunt(int fd, char unt, char *str, int f);

#endif
/* ************************************************************************ */
/*        /\																*/
/*       /^^\										jprieux					*/
/*      /^^*^\   /\									pforesti				*/
/*     /      \ /^^\														*/
/*    /  /\    /    \        /\    /\  /\      /\            /\/\/\  /\		*/
/*   /  /  \  /      \      /  \/\/  \/  \  /\/  \/\  /\  /\/ / /  \/  \	*/
/*  /  /    \/ /\     \    /    \ \  /    \/ /   /  \/  \/  \  /    \   \	*/
/* /  /      \/  \/\   \  /      \    /   /    \							*/
/*/__/_______/___/__\___\__________________________________________________	*/
/* ************************************************************************ */