/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 00:46:53 by rlecart           #+#    #+#             */
/*   Updated: 2017/04/18 10:17:12 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		init(t_rec **t, int ***tab, char ****tab_more, char ***tmp)
{
	if (!(*t = (t_rec*)malloc(sizeof(t_rec))))
		return (-1);
	(*t)->i = 0;
	(*t)->ret = 0;
	(*t)->line = ft_strnew(0);
	(*t)->keep = ft_strnew(0);
	*tab = NULL;
	*tab_more = NULL;
	*tmp = NULL;
	return (1);
}

static int		ft_while(char **tmp, int **tab, char ***tab_more, t_rt *s)
{
	while (tmp[s->i][++s->j])
	{
		if (tmp[s->i][s->j] >= '0' && tmp[s->i][s->j] <= '9')
		{
			tab[s->i][s->k] *= 10;
			tab[s->i][s->k] += tmp[s->i][s->j] - '0';
			if (tmp[s->i][s->j + 1] < '0' || tmp[s->i][s->j + 1] > '9')
				s->k++;
		}
		else if (tmp[s->i][s->j] == '-')
			s->neg++;
		if (tmp[s->i][s->j] == ',')
		{
			free(tab_more[s->i][s->k - 1]);
			if (!(tab_more[s->i][s->k - 1] = ft_strsub(tmp[s->i], s->j + 1, 8)))
				return (-1);
			s->j += 8;
		}
		if (s->neg != 0 && tmp[s->i][s->j + 1] == ' ')
		{
			tab[s->i][s->k - 1] *= -1;
			s->neg = 0;
		}
	}
	return (1);
}

static int		rec_tab(char **tmp, int **tab, char ***tab_more)
{
	t_rt	s;

	s.i = -1;
	s.j = -1;
	s.k = 0;
	s.neg = 0;
	while (tmp[++s.i])
	{
		if (!(ft_while(tmp, tab, tab_more, &s)))
			return (-1);
		s.j = -1;
		s.k = 0;
	}
	return (1);
}

int				**map_rec(int fd, char ****tab_more)
{
	int		*inti;
	int		**tab;
	char	**tmp;
	t_rec	*t;

	inti = NULL;
	if (!(init(&t, &tab, tab_more, &tmp)) || !(inti = ft_verif(fd, &tmp, &t)))
		return (NULL);
	if (!(*tab_more = (char***)malloc(sizeof(char**)
					* (tablen((void**)tmp) + 1))))
		return (NULL);
	t->i = 0;
	while (t->i < tablen((void**)tmp))
		if (!((*tab_more)[t->i++] = ft_strtabnew(inti[0], 8)))
			return (NULL);
	(*tab_more)[t->i] = NULL;
	if (!(tab = ft_inttabnew(tablen((void**)tmp), inti[0])))
		return (NULL);
	if (!(rec_tab(tmp, tab, *tab_more)))
		return (NULL);
	ft_memdel((void**)&inti);
	ft_strtabdel(&tmp);
	ft_memdel((void**)&t);
	return (tab);
}
