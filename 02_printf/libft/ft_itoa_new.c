/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsego <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 13:39:18 by mmatsego          #+#    #+#             */
/*   Updated: 2021/02/04 14:11:01 by mmatsego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_new(unsigned long nbr, int base)
{
	unsigned long	temp_nbr;
	int				len;
	char			*str;

	temp_nbr = nbr;
	len = 0;
	str = NULL;
	if (nbr == 0)
		len++;
	while (temp_nbr > 0)
	{
		temp_nbr /= base;
		len++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = nbr % base;
		if (nbr % base > 9)
			str[len - 1] += 'a' - 10;
		else
			str[len - 1] += '0';
		nbr /= base;
		len--;
	}
	return (str);
}
