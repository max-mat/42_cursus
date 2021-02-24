/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsego <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 16:53:47 by mmatsego          #+#    #+#             */
/*   Updated: 2021/02/05 16:53:59 by mmatsego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcut(const char *str, int start, int end)
{
	char	*ret;
	int		i;

	i = 0;
	if (start < 0 || (end - start) < 0)
		return (NULL);
	if (end > (int)ft_strlen(str))
		end = ft_strlen(str);
	ret = (char *)malloc(sizeof(char) * (end - start) + 1);
	while (start <= end)
	{
		ret[i] = str[start];
		start++;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
