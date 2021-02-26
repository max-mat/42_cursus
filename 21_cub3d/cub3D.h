/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsego <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 10:14:06 by mmatsego          #+#    #+#             */
/*   Updated: 2021/02/26 17:43:28 by mmatsego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>

#include "./libft/libft.h"
#include "./minilibx/mlx.h"

#define SCALE 24
#define PI 3.1415926535

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
	float		x; // player's position
	float		y;
	float		dir; // angle between Ox and player's direction
	float		start; // ray's left end
	float		end; // ray's right end
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
void			ft_get_window(t_plr *plr, t_win *win, t_all *all);
void			ft_get_image(t_all *all);
void			ft_scale_img(t_win *win, t_point point, int color);
void			ft_put_pixel(t_win *win, int x, int y, int color);

/* mlx_events.c */
void			ft_get_events(t_all *all, t_win *win);
int				key_press(int key, t_all *all);

/* player.c */
void			ft_get_player(char **map, t_plr *plr);
void			ft_put_player(t_all *all, t_plr *plr);
void			ft_draw_line (t_all *all, int ray_length, int ray_num);


#endif
