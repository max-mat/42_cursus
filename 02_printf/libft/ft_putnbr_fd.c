/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsego <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:40:15 by mmatsego          #+#    #+#             */
/*   Updated: 2021/01/15 16:22:04 by mmatsego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char c;
	long nbr;

	nbr = n;
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr *= -1;
	}
	if (nbr != 0)
	{
		if (nbr / 10 > 0)
			ft_putnbr_fd(nbr / 10, fd);
		c = nbr % 10 + 48;
		write(fd, &c, 1);
	}
	if (n == 0)
		write(fd, "0", 1);
}
