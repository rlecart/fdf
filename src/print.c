/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 10:09:26 by rlecart           #+#    #+#             */
/*   Updated: 2017/04/18 10:17:53 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	printx(t_key *k, int **map, int i, int j)
{
	int		st[2];
	int		end[2];

	st[0] = k->ox + (j - i) * k->ax;
	st[1] = k->oy + (j + i) * k->ax / 2 - map[i][j] * k->add;
	end[0] = k->ox + (j + 1 - i) * k->ax;
	end[1] = k->oy + (j + 1 + i) * k->ax / 2 - map[i][j + 1] * k->add;
	ft_drawline(st, end, k);
}

void	printy(t_key *k, int **map, int i, int j)
{
	int		st[2];
	int		end[2];

	st[0] = k->ox + (i - j) * -k->ax;
	st[1] = k->oy + (i + j) * k->ax / 2 - map[i][j] * k->add;
	end[0] = k->ox + (i + 1 - j) * -k->ax;
	end[1] = k->oy + (i + 1 + j) * k->ax / 2 - (map[i + 1][j] * k->add);
	ft_drawline(st, end, k);
}

void	print(t_key *k, int **map)
{
	int		i;
	int		j;

	i = -1;
	while (k->tab_more[++i])
	{
		j = -1;
		while (k->tab_more[i][++j])
		{
			if (k->tab_more[i][j + 1])
				printx(k, map, i, j);
			if (k->tab_more[i + 1])
				printy(k, map, i, j);
		}
	}
}

void	black_screen(t_key *k)
{
	mlx_put_image_to_window(k->mlx, k->win, k->img, 0, 0);
}
