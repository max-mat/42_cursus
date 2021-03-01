/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsego <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:34:15 by mmatsego          #+#    #+#             */
/*   Updated: 2021/03/01 18:14:40 by mmatsego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub3D.h"

void	ft_get_player(char **map, t_plr *plr)
{
	int x;
	int y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'E' || map[y][x] == 'W')
			{
				plr->x = x * SCALE;
				plr->y = y * SCALE;
			//	plr->x = x;
			//	plr->y = y;
				if (map[y][x] == 'N')
					plr->dir = 3 * PI / 2;
				else if (map[y][x] == 'E')
					plr->dir = 2 * PI;
				else if (map[y][x] == 'S')
					plr->dir = PI / 2;
				else if (map[y][x] == 'W')
					plr->dir = PI;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	ft_draw_line (t_all *all, float ray_length, int ray_num, t_plr ray)
{
	int		w_heignt;
	size_t		column;
	int		i;
	size_t 	dif;

	int ceiling = (float)(1080 / 2.0) - 1080 / ((float)ray_length);
	int floor = 1080 - ceiling;

	i = 0;
	while (i < 1080)
	{
		if (i < ceiling)
			ft_put_pixel(all->win, ray_num, i, 0x00FFFFFF);
		else if (i > ceiling && i <= floor)
			ft_put_pixel(all->win, ray_num, i, 0x00808080);
		else
			ft_put_pixel(all->win, ray_num, i, 0x00654321);
		i++;
	}




/*	w_heignt = 1080;
//	column = w_heignt / ray_length;
	column = w_heignt / (ray_length / 2 * cos(ray.dir - ray.start));
	dif = (w_heignt - column) / 2;
	i = 0;
	printf("column - %zu\n, dif - %zu\n", column, dif);
	while (i < dif)
	{
		ft_put_pixel(all->win, ray_num, i, 0x000000FF);
		i++;
	}
	while (i < (column + dif))
	{
		ft_put_pixel(all->win, ray_num, i, 0x0000FF00);
		i++;
	}
	while (i < w_heignt)
	{
		ft_put_pixel(all->win, ray_num, i, 0x00FFFFFF);
		i++;
	}*/
}

void	ft_put_player(t_all *all, t_plr *plr)
{
	t_plr	ray;
//	int	ray_length;
	float ray_length;
	int		ray_num;

	ray_num = 0;
	ray = *all->plr;
	ray.start = ray.dir - FOV / 2; // start point of rays = position of view - 45 \|
	ray.end = ray.dir + FOV / 2;  // end point of rays = position of view + 45     |/
/*	while (ray.start < ray.end) // inside start and end points we cast rays
	{
		ray.x = plr->x; // at each iteration ray must be at the  initial point of the player
		ray.y = plr->y;
		ray_length = 0; // length of ray

		while (all->map[(int)(ray.y / SCALE)][(int)(ray.x / SCALE)] != '1') // cast one ray till intersection with wall
		{
			ray.x = ray.x + cos(ray.start);
			ray.y = ray.y + sin(ray.start);
	//		ft_put_pixel(all->win, ray.x, ray.y, 0x00FF0000);
			ray_length ++;
		}
		printf("%d\n", ray_length);
//		pix_x = ray.x * SCALE; // point of intersection with wall
//		pix_y = ray.y * SCALE;
		ft_draw_line(all, ray_length, ray_num, ray);
		ray.start += FOV / 1920; // 90 (angle of view) / 40 (number of rays inside)
		ray_num++;
	}*/

	while (ray.start < ray.end) 
	{
		ray.x = plr->x; 
		ray.y = plr->y;
		ray_length = 0; 

		while (all->map[(int)(ray.y / SCALE)][(int)(ray.x / SCALE)] != '1')
		{
			ray.x = ray.x + cos(ray.start);
			ray.y = ray.y + sin(ray.start);
			ray_length += 0.1;
		}
		ft_draw_line(all, ray_length, ray_num, ray);
		ray.start += FOV / 1920; // 90 (angle of view) / 40 (number of rays inside)
		ray_num++;
	}




}
