/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 10:59:56 by rlecart           #+#    #+#             */
/*   Updated: 2017/04/18 10:24:15 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		fdf(int **map, char ***tab_more)
{
	int		i;
	int		j;
	t_key	k;

	i = 0;
	j = 0;
	k.i = 1;
	k.j = 1;
	k.ax = 30;
	k.ay = 30;
	k.ox = WIN_W / 2;
	k.oy = WIN_H / 10;
	k.add = 0.5;
	k.color = 0x003D8751;
	k.map = map;
	k.tab_more = tab_more;
	k.mlx = mlx_init();
	k.win = mlx_new_window(k.mlx, WIN_W, WIN_H, "fdf");
	k.img = mlx_new_image(k.mlx, WIN_W, WIN_H);
	print(&k, k.map);
	mlx_key_hook(k.win, hook, &k);
	mlx_loop(k.mlx);
	return (1);
}
