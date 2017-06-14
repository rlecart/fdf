/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 10:08:38 by rlecart           #+#    #+#             */
/*   Updated: 2017/04/18 10:22:49 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_dlx(t_key *k, t_lk l)
{
	while (l.i <= l.xd)
	{
		mlx_pixel_put(k->mlx, k->win, l.x, l.y, k->color);
		l.i++;
		l.x += l.xi;
		l.ex -= l.dy;
		if (l.ex < 0)
		{
			l.y += l.yi;
			l.ex += l.dx;
		}
	}
}

void	ft_dly(t_key *k, t_lk l)
{
	while (l.i <= l.yd)
	{
		mlx_pixel_put(k->mlx, k->win, l.x, l.y, k->color);
		l.i++;
		l.y += l.yi;
		l.ey -= l.dx;
		if (l.ey < 0)
		{
			l.x += l.xi;
			l.ey += l.dy;
		}
	}
}

void	ft_drawline(int st[2], int end[2], t_key *k)
{
	t_lk	l;

	l.i = 0;
	l.x = st[0];
	l.y = st[1];
	l.ex = abs(end[0] - st[0]);
	l.ey = abs(end[1] - st[1]);
	l.dx = 2 * l.ex;
	l.dy = 2 * l.ey;
	l.xd = l.ex;
	l.yd = l.ey;
	l.xi = 1;
	l.yi = 1;
	if (st[0] > end[0])
		l.xi = -1;
	if (st[1] > end[1])
		l.yi = -1;
	if (l.xd > l.yd)
		ft_dlx(k, l);
	else
		ft_dly(k, l);
}
