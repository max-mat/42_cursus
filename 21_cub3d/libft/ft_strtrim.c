/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsego <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:06:36 by mmatsego          #+#    #+#             */
/*   Updated: 2021/01/15 14:11:05 by mmatsego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		start;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return (0);
	while (set[i] && s1[j])
		if (s1[j] == set[i++])
			i = 0 * j++;
	start = j;
	while (s1[j] && s1[j + 1])
		i = 0 * j++;
	while (set[i] && s1[j])
		if (s1[j] == set[i++])
			i = 0 * j--;
	if (!(i *= 0) && !(str = malloc((j - start + 2) * sizeof(char))))
		return (0);
	while (start <= j)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
