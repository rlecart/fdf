/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 10:53:13 by rlecart           #+#    #+#             */
/*   Updated: 2017/04/18 10:17:38 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		tablen(void **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int		*countnbr(char **tmp)
{
	int		i;
	int		j;
	int		bol;
	int		*counter;

	i = -1;
	j = 0;
	bol = 0;
	if (!(counter = ft_intnew(tablen((void**)tmp))))
		return (NULL);
	while (tmp[++i])
	{
		while (tmp[i][j])
		{
			if (tmp[i][j] >= '0' && tmp[i][j] <= '9' && bol++ == 0)
				counter[i]++;
			j++;
			if (tmp[i][j] == ' ' || !tmp[i][j])
				bol = 0;
		}
		j = 0;
	}
	return (counter);
}

int		ft_check_valid(int *inti, int len)
{
	int		i;
	int		mem;
	int		counter;

	i = -1;
	mem = inti[0];
	counter = 0;
	while (++i < len)
		if (inti[i] == mem)
			counter++;
	if (counter != len)
		return (-1);
	return (1);
}

int		*ft_verif(int fd, char ***tmp, t_rec **t)
{
	int		i;
	int		*inti;

	i = -1;
	while (((*t)->ret = get_next_line(fd, &((*t)->line))) > 0)
	{
		(*t)->keep = ft_strjoin_clean(&((*t)->keep), &((*t)->line));
		(*t)->keep = ft_strjoin_clean_char(&((*t)->keep), '\n');
	}
	if (!((*tmp) = ft_strsplit((*t)->keep, '\n')))
		return (NULL);
	ft_strdel(&((*t)->keep));
	if (!(inti = countnbr((*tmp))))
		return (NULL);
	while (++i < tablen((void**)(*tmp)))
		if (!(ft_check_valid(inti, tablen((void**)(*tmp)))))
			return (NULL);
	return (inti);
}
