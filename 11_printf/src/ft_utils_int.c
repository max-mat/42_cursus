/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsego <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 10:26:08 by mmatsego          #+#    #+#             */
/*   Updated: 2021/02/08 17:05:49 by mmatsego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_zero_space(t_struct *list, int num, char c)
{
	while (num > 0)
	{
		ft_putchar_len(list, c);
		num--;
	}
}

void	print_width(t_struct *list, int num)
{
	char c;

	if (list->flags_min)
		list->flags_zero = 0;
	if (list->flags_zero == 1 && list->prec <= -1)
		c = '0';
	else
		c = ' ';
	while (num > 0)
	{
		ft_putchar_len(list, c);
		num--;
	}
}

void	is_int_neg(t_struct *list, long *num)
{
	if (*num < 0)
	{
		list->is_int_neg = 1;
		*num *= -1;
		list->width--;
	}
}

void	print_left_justified(t_struct *list, int len, char *tmp)
{
	if (list->is_int_neg)
		ft_putchar_len(list, '-');
	if (list->prec > len)
		print_zero_space(list, list->prec - len, '0');
	ft_putstr_len(list, tmp, len);
	if (list->width > len)
	{
		if (list->prec > len)
			print_width(list, list->width - list->prec);
		else
			print_width(list, list->width - len);
	}
}

void	print_right_justified(t_struct *list, int len, char *tmp)
{
	if (list->flags_zero && list->prec <= -1)
	{
		if (list->is_int_neg)
			ft_putchar_len(list, '-');
		print_width(list, list->width - len);
	}
	else
	{
		if (list->prec > len)
		{
			if (list->width > list->prec)
				print_width(list, list->width - list->prec);
			if (list->is_int_neg)
				ft_putchar_len(list, '-');
			print_zero_space(list, list->prec - len, '0');
		}
		else
		{
			print_width(list, list->width - len);
			if (list->is_int_neg)
				ft_putchar_len(list, '-');
		}
	}
	ft_putstr_len(list, tmp, len);
}
