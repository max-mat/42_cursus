/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsego <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 11:53:05 by mmatsego          #+#    #+#             */
/*   Updated: 2021/02/03 14:09:36 by mmatsego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	malloc_int(t_list *list, const char *str, va_list args)
{
	int	num;
	int	len;
	char *output;

	num = va_arg(args, int);
	len = (int)ft_numlen(num);
	if (len >= list->prec)
	{
		if (len >= list->width)
		{
			if (!(output = (char *)malloc(sizeof(char) * (len + 1))))
				return (NULL);
		}
		else
		{
			if (!(output = (char *)malloc(sizeof(char) * (list->width + 1))))
				return (NULL);
		}
	}
	else
	{
		if (list->prec >= list->width)
		{
			if (!(output = (char *)malloc(sizeof(char) * (list->prec + 1))))
				return (NULL);
		}
		else
		{
			if(!(output = (char *)malloc(sizeof(char) * (list->width + 1))))
				return (NULL);
		}
	}
	print_int(output, num, len, list);
}
