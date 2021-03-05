/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsego <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:34:15 by mmatsego          #+#    #+#             */
/*   Updated: 2021/03/05 16:37:35 by mmatsego         ###   ########.fr       */
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
				if (map[y][x] == 'N')
					plr->dir = PI_3;
				else if (map[y][x] == 'E')
					plr->dir = 2 *  PI;
				else if (map[y][x] == 'S')
					plr->dir = PI_2;
				else if (map[y][x] == 'W')
					plr->dir = PI;
				return ;
			}
			x++;
		}
		y++;
	}
}

/*void	ft_draw_texture(t_plr ray)
{
	double wallX; //where exactly the wall was hit
	int texX; //x coordinate on the texture

	wallX = ray.x % SCALE;
	texX = int(wallX * double(texWidth));*/

void	ft_draw_line (t_all *all, float ray_length, int ray_num, t_plr ray)
{
	int		w_heignt;
	float	distance;
	int		i;
	float 	dif;
	
	distance = (float)ray_length * cos(ray.dir - ray.start);
	int ceiling = (float)(1080 / 2) - 1080 / distance;
	int floor = 1080 - ceiling;

	i = 0;
	while (i < 1080)
	{
		if (i < ceiling)
			ft_put_pixel(all->win, ray_num, i, 0x00FFFFFF);
		else if (i > ceiling && i <= floor)
			ft_put_pixel(all->win, ray_num, i, 0x00808080);
			//ft_draw_texture(ray);
		else
			ft_put_pixel(all->win, ray_num, i, 0x00654321);
		i++;
	}
}

void	ft_put_player(t_all *all, t_plr *plr)
{
	t_plr	ray;
	float ray_length;
	int		ray_num;

	ray_num = 0;
	ray = *all->plr;
	ray.start = ray.dir - FOV / 2; // start point of rays = position of view - 45 \|
	while (ray_num < 1920) 
	{
		ray.x = plr->x; 
		ray.y = plr->y;
		ray_length = 0; 
		while (all->map[(int)(ray.y / SCALE)][(int)(ray.x / SCALE)] != '1')
		{
			ray.x = ray.x + cos(ray.start);
			ray.y = ray.y + sin(ray.start);
			ray_length += 0.01;
		}
		ft_draw_line(all, ray_length, ray_num, ray);
		ray.start += FOV / 1920; // 90 (angle of view) / 40 (number of rays inside)
		ray_num++;
	}
}
