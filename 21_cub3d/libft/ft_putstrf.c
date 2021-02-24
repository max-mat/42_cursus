/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsego <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 16:26:06 by mmatsego          #+#    #+#             */
/*   Updated: 2021/01/29 16:26:45 by mmatsego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrf(char const *s, int *p)
{
	int x;

	x = -1;
	while (s[++x] != '\0')
	{
		ft_putchar(s[x]);
		*p = *p + 1;
	}
}
