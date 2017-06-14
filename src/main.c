/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 00:45:13 by rlecart           #+#    #+#             */
/*   Updated: 2017/04/18 10:18:07 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	int		i;
	int		j;
	int		fd;
	int		**map;
	char	***tab_more;

	i = 0;
	j = 0;
	tab_more = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (!(map = map_rec(fd, &tab_more)))
			return (-1);
		while (tab_more[i])
		{
			while (tab_more[i][j])
				j++;
			j = 0;
			i++;
		}
		if (!(fdf(map, tab_more)))
			return (-1);
	}
	return (0);
}
