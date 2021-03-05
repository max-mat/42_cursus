/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsego <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 09:50:19 by mmatsego          #+#    #+#             */
/*   Updated: 2021/03/05 14:23:42 by mmatsego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub3D.h"

char	**ft_make_map(t_list **head, int size)
{
	int i;
	char **map;
	t_list *tmp;

	if (!(map = (char **)malloc((size + 1) * sizeof(char *))))
		return (NULL);
	tmp = *head;
	i = 0;
	while (tmp)
	{
		map[i] = ft_strdup(tmp->content);
		tmp = tmp->next;
		i++;
	}
	map[i] = NULL;
	ft_lstclear(head, &free);
	return (map);
}

char	**ft_read_map(char *argv1)
{
	int		fd;
	int		size;
	char	*line;
	t_list	*head;
	char 	**map;

	line = NULL;
	head = NULL;
	size = 0;
	fd = open(argv1, O_RDONLY);
	while (ft_get_next_line(fd, &line))
	{
		ft_lstadd_back(&head, ft_lstnew(line));
		size++;
		line = NULL;
	}
	close(fd);
	ft_lstadd_back(&head, ft_lstnew(line));
	size++;
	return (ft_make_map(&head, size));
}


int	main(int argc, char **argv)
{
	t_win		win;
	t_plr		plr;
	t_texture	texture;
	t_all 		all;

	if (argc == 2)
		all.map = ft_read_map(argv[1]);
	else
	{
		ft_putendl_fd("Insert a map", 2);
		return (1);
	}
	ft_get_window(&plr, &win, &all);
	free(all.map);
	return (0);
}
