/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsego <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:22:22 by mmatsego          #+#    #+#             */
/*   Updated: 2021/02/26 15:23:56 by mmatsego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub3D.h"

int		key_press(int key, t_all *all)
{
	mlx_clear_window(all->win->mlx, all->win->win);
	if (key == 13)
	{
		all->plr->y += sin(all->plr->dir) * 4;
		all->plr->x += cos(all->plr->dir) * 4;
		
	}
	if (key == 1)
	{
		all->plr->y -= sin(all->plr->dir) * 4;
		all->plr->x -= cos(all->plr->dir) * 4;
	}
	if (key == 0)
	{
//		all->plr->y -= sin(all->plr->dir) * 4;
		all->plr->x -= cos(all->plr->dir) * 4;
	}
	if (key == 2)
		all->plr->x += cos(all->plr->dir) * 4;
	if (key == 123)
		all->plr->dir -= 0.1;
	if (key == 124)
		all->plr->dir += 0.1;
	if (key == 53)
		exit(0);
	ft_get_image(all);
	return (0);
}

void	ft_get_events(t_all *all, t_win *win)
{
	mlx_hook(win->win, 2, (1L << 0), &key_press, all);
}
