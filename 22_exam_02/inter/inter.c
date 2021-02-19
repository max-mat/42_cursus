/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsego <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:16:24 by mmatsego          #+#    #+#             */
/*   Updated: 2021/02/17 11:22:43 by mmatsego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_both(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

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

void	ft_inter(char *str1, char *str2)
{
	int i;

	i = 0;
	while (str1[i])
	{
		if (!is_before(str1, i, str1[i]) && is_both(str2, str1[i]))
			write(1, &str1[i], 1);
		i++;
	}
}

int	main (int argc, char **argv)
{
	if (argc == 3)
		ft_inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
