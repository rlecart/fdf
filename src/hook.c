/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 10:10:16 by rlecart           #+#    #+#             */
/*   Updated: 2017/04/18 10:14:17 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	h2(int key, t_key *k)
{
	if (key == 124)
		k->add += ADD;
	else if (key == 123)
		k->add -= ADD;
	else if (key == 116)
	{
		k->ax++;
		k->ay++;
	}
	else if (key == 121)
	{
		k->ax--;
		k->ay--;
	}
}

int		hook(int key, void *param)
{
	t_key	*k;

	k = (t_key*)param;
	if (key == 53)
		exit(0);
	else if (key == 126)
	{
		k->ax++;
		k->ay--;
	}
	else if (key == 125)
	{
		k->ax--;
		k->ay++;
	}
	else if (key == 69)
		k->color += 10;
	else if (key == 78)
		k->color -= 10;
	h2(key, k);
	black_screen(k);
	print(k, k->map);
	return (0);
}
