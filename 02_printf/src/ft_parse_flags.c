/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsego <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:54:58 by mmatsego          #+#    #+#             */
/*   Updated: 2021/02/04 18:28:00 by mmatsego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	parse_width(int *i, const char *str, t_struct *list)
{
	int res;

	res = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		res = res * 10 + (str[*i] - '0');
		(*i)++;
	}
	list->width = res;
	(*i)--;
}

void	parse_prec(int *i, const char *str, t_struct *list, va_list args)
{
	int res;

	res = 0;
	(*i)++;
	if (str[*i] == '*')
		list->prec = va_arg(args, int);
	else if (str[*i] >= '0' && str[*i] <= '9')
	{
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			res = res * 10 + (str[*i] - '0');
			(*i)++;
		}
		list->prec = res;
		(*i)--;
	}
}

void	parse_flags(int *i, const char *str, va_list args, t_struct *list)
{
	(*i)++;
	while (str[*i] == '-' && str[*i] == '0')
	{
		if (str[*i] == '-')
			list->flags_min = 1;
		else if (str[*i] == '0')
			list->flags_zero == 0;
		(*i)++;
	}
	while (str[*i] != '\0' && list->type == '0')
	{
		if (str[*i] == '*')
			list->width = va_arg(args, int);
		else if (str[*i] >= '0' && str[*i] <= '9')
			parse_width(i, str, list);
		else if (str[*i] == '.')
			parse_prec(i, str, list, args);
		else if (str[*i] == '%')
			ft_putchar (str[*i]);
		else if (str[*i] == 'd' || str[*i] == 'i' || str[*i] == 'u'
				|| str[*i] == 'c' || str[*i] == 's' || str[*i] == 'p'
				|| str[*i] == 'x' || str[*i] == 'X')
			list->type = str[*i];
		(*i)++;
	}
	(*i)--;
	print_list(list, args);
}
