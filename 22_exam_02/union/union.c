/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsego <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 10:48:41 by mmatsego          #+#    #+#             */
/*   Updated: 2021/02/17 10:54:44 by mmatsego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_before(char *str, int i, char c)
{
	int j;

	j = 0;
	while (j < i)
	{
		if (str[j] == c)
			return (1);
		j++;
	}
	return (0);
}

void	ft_union(char *str1, char *str2)
{
	int i;
	int j;

	i = 0;
	while (str1[i])
	{
		if (!is_before(str1, i, str1[i]))
			write(1, &str1[i], 1);
		i++;
	}
	j = 0;
	while (str2[j])
	{
		if (!is_before(str1, i, str2[j]) && !is_before(str2, j, str2[j]))
			write(1, &str2[j], 1);
		j++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
