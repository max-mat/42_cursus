/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsego <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:34:19 by mmatsego          #+#    #+#             */
/*   Updated: 2021/02/05 17:06:22 by mmatsego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_c(t_struct *list, char c)
{
	if (list->width < 0)
	{
		list->width *= -1;
		list->flags_min = 1;
	}
	if (list->flags_min)
	{
		ft_putchar(c);
		print_width(list, list->width - 1);
	}
	else
	{
		print_width(list, list->width - 1);
		ft_putchar(c);
	}
}

void	print_s(t_struct *list, char *str)
{
	int	len;

	len = ft_strlen(str);
	if (list->width < 0)
	{
		list->width *= -1;
		list->flags_min = 1;
	}
	if (list->prec < len)
	{
		str = ft_strcut(str, 0, list->prec - 1);
		len = ft_strlen(str);
	}
	if (list->flags_min)
	{
		ft_putstr(str);
		print_width(list, list->width - len);
	}
	else
	{
		print_width(list, list->width - len);
		ft_putstr(str);
	}
}
