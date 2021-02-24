/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsego <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 14:59:08 by mmatsego          #+#    #+#             */
/*   Updated: 2021/02/24 17:39:00 by mmatsego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub3D.h"

int		ft_get_color(char **map, int y, int x)
{
	int color;

	color = 0;
	if (map[y][x] == ' ' || map[y][x] == '0')
		color = 0x00000000;
	else if (map[y][x] == '1')
		color = 0x00FFFFFF;
	else if (map[y][x] == '2')
		color = 0x0000FF00;
	else if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'E' || map[y][x] == 'W')
		color = 0x00000000;
	return (color);
}

void	ft_put_pixel(t_all *all, t_point point, int color)
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
			mlx_pixel_put(all->win->mlx, all->win->win, point.x, point.y, color);
			point.x++;
		}
		point.x -= SCALE;
		point.y++;
	}
}

void	ft_get_image(t_all *all)
{
	t_point		point;
	int			color;

	color = 0;
	ft_bzero(&point, sizeof(t_point));
	while (all->map[point.y])
	{
		point.x = 0;
		while (all->map[point.y][point.x])
		{
			color = ft_get_color(all->map, point.y, point.x);
			ft_put_pixel(all, point, color);
			point.x++;
		}
		point.y++;
	}
	ft_put_player(all, all->plr->x, all->plr->y);
}

void	ft_get_window(t_win *win, t_all *all)
{
	win->mlx = NULL;
	win->win = NULL;
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, 1920, 1080, "Cub  2D");
	win->img = mlx_new_image(win->mlx, 1920, 1080);
	win->addr = mlx_get_data_addr(win->img, &win->bpp, &win->line_l, &win->endian);
	all->win = win;
	ft_get_player(all);
	ft_get_image(all);
	ft_get_events(all, win);
	mlx_loop(win->mlx);
}

void	ft_renew_window(t_all *all)
{
	all->win->mlx = NULL;
	all->win->win = NULL;
	all->win->mlx = mlx_init();
	all->win->win = mlx_new_window(all->win->mlx, 1920, 1080, "Cub  2D");
	all->win->img = mlx_new_image(all->win->mlx, 1920, 1080);
	all->win->addr = mlx_get_data_addr(all->win->img, &all->win->bpp, &all->win->line_l, &all->win->endian);
	ft_get_image(all);
	ft_get_events(all, all->win);
	mlx_loop(all->win->mlx);
}

