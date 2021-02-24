/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsego <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:34:15 by mmatsego          #+#    #+#             */
/*   Updated: 2021/02/24 17:37:00 by mmatsego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub3D.h"

void	ft_get_player(t_all *all)
{
	int x;
	int y;

	y = 0;
	while (all->map[y])
	{
		x = 0;
		while (all->map[y][x])
		{
			if (all->map[y][x] == 'N' || all->map[y][x] == 'S' || all->map[y][x] == 'E' || all->map[y][x] == 'W')
			{
				all->plr->x = x;
				all->plr->y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	ft_put_player(t_all *all, int x, int y)
{
	int end_x;
	int end_y;

	end_x = (x + 1) * SCALE;
	end_y = (y + 1) * SCALE;
	y *= SCALE;
	x *= SCALE;
	while (y < end_y)
	{
		while (x < end_x)
		{
			mlx_pixel_put(all->win->mlx, all->win->win, x, y, 0x00FF0000);
			x++;
		}
		x -= SCALE;
		y++;
	}
}

