/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 00:45:25 by rlecart           #+#    #+#             */
/*   Updated: 2017/05/13 13:54:29 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>

# define WIN_H 600
# define WIN_W 1200
# define ADD 0.1

typedef struct		s_rec
{
	int				i;
	int				ret;
	char			*line;
	char			*keep;
}					t_rec;

typedef struct		s_rt
{
	int				i;
	int				j;
	int				k;
	int				neg;
}					t_rt;

typedef struct		s_key
{
	int				i;
	int				j;
	int				ox;
	int				oy;
	int				ax;
	int				ay;
	float			add;
	int				color;
	int				**map;
	char			***tab_more;
	void			*mlx;
	void			*win;
	void			*img;
}					t_key;

typedef struct		s_linker
{
	int				i;
	int				x;
	int				y;
	int				dx;
	int				dy;
	int				ex;
	int				ey;
	int				xd;
	int				yd;
	int				xi;
	int				yi;
}					t_lk;

int					**map_rec(int fd, char ****tab_more);
int					*ft_verif(int fd, char ***tmp, t_rec **t);
int					ft_check_valid(int *inti, int len);
int					tablen(void **tab);
int					fdf(int **map, char ***tab_more);
void				ft_drawline(int st[2], int end[2], t_key *k);
void				print(t_key *k, int **map);
void				black_screen(t_key *k);
int					hook(int key, void *param);

#endif
