/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsego <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:34:15 by mmatsego          #+#    #+#             */
/*   Updated: 2021/03/04 18:27:58 by mmatsego         ###   ########.fr       */
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
		//		plr->x = x;
		//		plr->y = y;
				if (map[y][x] == 'N')
					plr->dir = 3 * PI / 2;
				else if (map[y][x] == 'E')
					plr->dir = PI_2;
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

void	ft_draw_line (t_all *all, float final_dist, int ray_num, t_plr ray)
{
	int		w_heignt;
	size_t		column;
	int		i;
	size_t 	dif;

	int ceiling = (float)(1080 / 2.0) -	1080 / ((float)final_dist);
	int floor = 1080 - ceiling;

	printf("ceiling - %d. floor - %d\n", ceiling, floor);

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
}

float	get_horiz_distance(t_all *all, t_plr ray)
{
	printf("test horiz\n");
	float dist;
	angle = ray.dir - ray.start;

	float aTan = -1 / tan(ray.start);
	if (ray.start > PI) // if ray goes up
	{
		ray.Ay = (int)(ray.y / SCALE) * SCALE - 0.0001;
		ray.Ax = (ray.y - ray.Ay) * aTan + ray.x;
		ray.Ya = SCALE * -1;
		ray.Xa = -Ya * aTan;
	}
	if (ray.start < PI) //if ray goes down
	{
		ray.Ay = (int)(ray.y / SCALE) * SCALE + SCALE;
		ray.Ax = (ray.y - ray.Ay) * aTan + ray.x;
		ray.Ya = SCALE;
		ray.Xa = -Ya * aTan;
	}
	if (ray.start == 2 * PI || ray.start == PI)
	{
		ray.Ay = ray.y;
		ray.Ax = ray.x;
	while (all->map[(int)(ray.Ay / SCALE)][(int)(ray.Ax / SCALE)] != '1')
	{
		ray.Ax += ray.Xa;
		ray.Ay += ray.Ya;
	}
	dist = sqrt((ray.Ax - ray.x) * (ray.Ax - ray.x) + (ray.Ay - ray.y) * (ray.Ay - ray.y));
	printf("%f\n", dist);
	return (dist);
}

float	get_vert_distance(t_all *all, t_plr ray)
{
	printf("test vert\n");
	float dist;

	if (ray.start > PI_3 || ray.start < PI_2) // if ray goes right
	{
		ray.Bx = (int)(ray.x / SCALE) * SCALE + SCALE;
		ray.Xa = SCALE;;
	} 
	else if (ray.start < PI_3 && ray.start > PI_2) //if ray goes left
	{
		ray.Bx = (int)(ray.x / SCALE) * SCALE - 1;
		ray.Xa = SCALE * -1;;
	}
	ray.By = ray.y + (ray.x - ray.Bx) * tan(ray.start);
	ray.Ya = SCALE * tan(ray.start);
	while (all->map[(int)(ray.By / SCALE)][(int)(ray.Bx / SCALE)] != '1')
	{
		ray.Bx += ray.Xa;
		ray.By += ray.Ya;
	}
	dist = sqrt((ray.Bx - ray.x) * (ray.Bx - ray.x) + (ray.By - ray.y) * (ray.By - ray.y));
	printf("%f\n", dist);
	return (dist);
}


void	ft_put_player(t_all *all, t_plr *plr)
{
	t_plr	ray;
	float ray_length;
	int		ray_num;
	float horiz_dist; // distance between player and final point
	float vert_dist;
	float final_dist;

	ray_num = 0;
	ray = *all->plr;
	ray.start = ray.dir - FOV / 2; // start point of rays = position of view - 45 \|

	while (ray_num < 1920) 
	{
		ray.x = plr->x; 
		ray.y = plr->y;
		ray_length = 0; 

		// horiz intersections
		horiz_dist = get_horiz_distance(all, ray);

		// vertical intersections
		vert_dist = get_vert_distance(all, ray);

		printf("hor_dist - %f, vert_dist - %f\n", horiz_dist, vert_dist);
	
		if (horiz_dist > vert_dist)
			final_dist = vert_dist;
		else
			final_dist = horiz_dist;

		ft_draw_line(all, final_dist, ray_num, ray);
		ray.start += FOV / 1920; // 90 (angle of view) / 40 (number of rays inside)
		ray_num++;
	}
}
