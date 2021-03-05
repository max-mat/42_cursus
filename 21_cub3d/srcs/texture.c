/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsego <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:48:22 by mmatsego          #+#    #+#             */
/*   Updated: 2021/03/05 18:20:04 by mmatsego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub3D.h"

void	ft_parse_line(t_texture *texture, char *line)
{
	int	i;
	int	columns;
	int	rows;
	int	colors;

	columns = 0;
	rows = 0;
	colors = 0;
	i = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		columns = columns * 10 + (str[i] - '0');
		i++;
	}
	i++;
	while ('0' <= str[i] && str[i] <= '9')
	{
		rows = rows * 10 + (str[i] - '0');
		i++;
	}
	i++;
	while ('0' <= str[i] && str[i] <= '9')
	{
		colors = colors * 10 + (str[i] - '0');
		i++;
	}

	texture->columns = columns;
	texture->rows = rows;
	texture->colors = colors;
}

void	ft_parse_colors( t_texture *texture, char *line)
{

void	ft_get_texture(t_all *all)
{
	int			i;
	int			fd;
	char		*line;
	char 		**map;
	t_texture	*texture;

	line = NULL;
	fd = open("textures/bluestone.xpm", O_RDONLY);
	i = 0;
	while (ft_get_next_line(fd, &line) && i < 4)
	{
		if (i == 3)
			ft_parse_line(&texture, line);
		i++;
		line = NULL;
	}
	while (ft_get_next_line(fd, &line) && i <= 3 + texture.colors)
	{
		if (i > 3)
			ft_parse_colors(&texture, line);
		i++;
		line = NULL;
	}

	close(fd);
	ft_lstadd_back(&head, ft_lstnew(line));
	size++;
	all->texture = texture;
	return (ft_make_map(&head, size));

