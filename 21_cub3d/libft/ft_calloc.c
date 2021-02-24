/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsego <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:13:03 by mmatsego          #+#    #+#             */
/*   Updated: 2021/01/15 13:44:42 by mmatsego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	sum;
	void	*ptr;

	sum = count * size;
	ptr = malloc(sum);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, sum);
	return (ptr);
}
