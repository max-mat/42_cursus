/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsego <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 15:43:03 by mmatsego          #+#    #+#             */
/*   Updated: 2021/02/04 18:11:37 by mmatsego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_zero(int num)
{
	while (num > 0)
	{
		ft_putchar('0');
		num--;
	}
}

void	print_width(t_struct *list, int num)
{
	char c;

	if (list->flags_zero == 1 && !list->prec)
		c = '0';
	else
		c = ' ';
	while (num > 0)
	{
		ft_putchar(c);
		num--;
	}
}

void	is_int_neg(t_struct *list, int *num)
{
	if (*num < 0)
	{
		list->is_int_neg = 1;
		*num *= -1;
		list->width--;
	}
}
