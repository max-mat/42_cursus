/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsego <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:48:12 by mmatsego          #+#    #+#             */
/*   Updated: 2021/02/05 14:48:46 by mmatsego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getnumlen(long long num, int base)
{
	size_t	len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num *= -1;
		len++;
	}
	while (num > 0)
	{
		num /= base;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(unsigned long nbr, int base, char c)
{
	size_t			len;
	char			*str;

	len = ft_getnumlen(nbr, base);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	if (nbr == 0)
		str[0] = '0';
	while (len > 0)
	{
		str[len - 1] = nbr % base;
		if (str[len - 1] > 9)
		{
			if (c == 'x')
				str[len - 1] += 'a' - 10;
			else
				str[len - 1] += 'A' - 10;
		}
		else
			str[len - 1] += '0';
		nbr /= base;
		len--;
	}
	return (str);
}
