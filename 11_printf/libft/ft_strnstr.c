/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsego <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 11:03:39 by mmatsego          #+#    #+#             */
/*   Updated: 2021/01/15 14:08:53 by mmatsego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;
	size_t	needle_len;

	needle_len = 0;
	while (needle[needle_len])
		needle_len++;
	if (!needle_len)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		k = 0;
		while (needle[k] && haystack[i + k] == needle[k] && i + k < len)
			k++;
		if (needle[k] == '\0')
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
