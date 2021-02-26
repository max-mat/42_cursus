/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsego <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 14:59:08 by mmatsego          #+#    #+#             */
/*   Updated: 2021/02/26 18:11:37 by mmatsego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub3D.h"

void	ft_put_pixel(t_win *win, int x, int y, int color)
{
	char	*dst;

	dst = win->addr + (x * (win->bpp / 8) + y * win->line_l);
	*(int *)dst = color;
}

void	ft_scale_img(t_win *win, t_point point, int color)
{
	t_point end;

	end.x = (point.x + 1) * SCALE;
	end.y = (point.y + 1) * SCALE;
	point.y *= SCALE;
	point.x *= SCALE;
	while (point.y < end.y)
	{
		while (point.x < end.x)
		{
			ft_put_pixel(win, point.x, point.y, color);
			point.x++;
		}
		point.x -= SCALE;
		point.y++;
	}
}

void	ft_get_image(t_all *all)
{
	t_point		point;
	t_win		*win;

	win = all->win;
	win->img = mlx_new_image(win->mlx, 1920, 1080);
	win->addr = mlx_get_data_addr(win->img, &win->bpp, &win->line_l, &win->endian);
/*	ft_bzero(&point, sizeof(t_point));
	while (all->map[point.y])
	{
		point.x = 0;
		while (all->map[point.y][point.x])
		{
			if (all->map[point.y][point.x] == '1')
				ft_scale_img(all->win, point, 0x00FFFFFF);
			point.x++;
		}
		point.y++;
	}*/
	ft_put_player(all, all->plr);
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
	mlx_destroy_image(win->mlx, win->img);
}

void	ft_get_window(t_plr *plr, t_win *win, t_all *all)
{
	win->mlx = NULL;
	win->win = NULL;
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, 1920, 1080, "Cub  2D");
	win->img = mlx_new_image(win->mlx, 1920, 1080);
	win->addr = mlx_get_data_addr(win->img, &win->bpp, &win->line_l, &win->endian);
	all->win = win;
	ft_get_player(all->map, plr);
	all->plr = plr;
	ft_get_image(all);
	ft_get_events(all, win);
	mlx_loop(win->mlx);
}
