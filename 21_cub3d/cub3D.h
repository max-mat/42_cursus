/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsego <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 10:14:06 by mmatsego          #+#    #+#             */
/*   Updated: 2021/02/24 17:36:44 by mmatsego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#include "./libft/libft.h"
#include "./minilibx/mlx.h"

#define SCALE 30

typedef struct	s_win
{
	void	*mlx;
	void	*win;
	void 	*img;
	void	*addr;
	int		line_l;
	int		bpp;
	int		endian;
}				t_win;

typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct	s_plr
{
	int		x;
	int		y;
	float		dir;
	float		start;
	float		end;
}				t_plr;

typedef struct	s_all
{
	t_win	*win;
	t_plr	*plr;
	char	**map;
}				t_all;

/* main.c */
char			**ft_read_map(char *argv1);
char			**ft_make_map(t_list **head, int size);

/* mlx_window.c */
void			ft_get_window(t_win *win, t_all *all);
void			ft_renew_window(t_all *all);
void			ft_get_image(t_all *all);
void			ft_put_pixel(t_all *all, t_point point, int color);
int				ft_get_color(char **map, int y, int x);

/* mlx_events.c */
void			ft_get_events(t_all *all, t_win *win);

/* player.c */
void			ft_get_player(t_all *all);
void			ft_put_player(t_all *all, int x, int y);


#endif
