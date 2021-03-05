/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsego <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 13:49:32 by mmatsego          #+#    #+#             */
/*   Updated: 2021/03/05 17:46:27 by mmatsego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub3D.h"

void	ft_load_image(t_win *win, int *texture, char *path)
{
	int x;
	int y;

	win->img = mlx_xpm_file_to_image(win->mlx, path, &win->img_width, &win->img_height);
    win->addr = mlx_get_data_addr(win->img, &win->bpp, &win->line_l, &win->endian);
    y = 0;
	while (y < win->img_height)
    {
		x = 0;
        while (x < win->img_width)
        {
            texture[win->img_width * y + x] = win->addr[win->img_width * y + x];
        }
    }
    mlx_destroy_image(win->mlx, win->img);
}

void	ft_load_texture(t_all *all)
{
	t_win	win;

	win = all->win;

	ft_load_image(win, all->texture[0], "textures/eagle.xpm");
    ft_load_image(win, all->texture[1], "textures/redbrick.xpm");
    ft_load_image(win, all->texture[2], "textures/purplestone.xpm");
    ft_load_image(win, all->texture[3], "textures/greystone.xpm");
    ft_load_image(win, all->texture[4], "textures/bluestone.xpm");
    ft_load_image(win, all->texture[5], "textures/mossy.xpm");
    ft_load_image(win, all->texture[6], "textures/wood.xpm");
    ft_load_image(win, all->texture[7], "textures/colorstone.xpm");
}

void	ft_get_texture(t_all *all)
{
	int		i;
	int 	j;

	if (!(all->texture = (int **)malloc(sizeof(int *) * 8)))
		return (NULL);
	i = 0;
	while (i < 8)
	{
		if (!(all->texture[i] = (int *)malloc(sizeof(int) * (texHeight * texWidth))))
			return (NULL);
		i++;
	}
	i = 0;
	j = 0;
	while (i < 8)
	{
		while (j < texHeight * texWidth)
		{
			all->texture[i][j] = 0;
			j++;
		}
		i++;
	}
	ft_load_texture(all);
}
