/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsego <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 12:13:38 by mmatsego          #+#    #+#             */
/*   Updated: 2021/02/19 11:36:42 by mmatsego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char *ft_strjoin(char *remains, char *buffer)
{
	char *str;
	int i;
	int j;

	i = 0;
	j = 0;
	if (!remains && !buffer)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * ft_strlen(remains) + ft_strlen(buffer) + 1)))
		return (NULL);
	if (remains)
	{
		while (remains[i])
		{
			str[i] = remains[i];
			i++;
		}
	}
	while (buffer[j])
	{
		str[i] = buffer[j];
		i++;
		j++;
	}
	str[i] = '\0';
	if (remains != NULL)
		free(remains);
	return (str);
}

char *push_line(char *remains)
{
	char *str;
	int i;

	i = 0;
	while (remains[i] && remains[i] != '\n')
		i++;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (remains[i] && remains[i] != '\n')
	{
		str[i] = remains[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	get_next_line(char **line)
{
	char buffer[BUFFER_SIZE + 1];
	char *remains;
	int res;
	int fd;

	remains = NULL;
	res = 1;
	fd = 0;
	if (!line)
		return (-1);
	while (buffer[0] != '\n' && res != 0)
	{
		if ((res = read(fd, buffer, BUFFER_SIZE)) == -1)
			return (-1);
		buffer[res] = '\0';
		remains = ft_strjoin(remains, buffer);
	}
	*line = push_line(remains);
	free(remains);
	return ((res == 0) ? 0 : 1);
}
