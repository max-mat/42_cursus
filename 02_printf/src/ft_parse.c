/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsego <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 12:12:06 by mmatsego          #+#    #+#             */
/*   Updated: 2021/02/05 18:02:54 by mmatsego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	parse_zero_minus(int *i, const char *str, t_struct *list)
{
	while (str[*i] == '-' || str[*i] == '0')
	{
		if (str[*i] == '-')
			list->flags_min = 1;
		else if (str[*i] == '0')
			list->flags_zero = 1;
		(*i)++;
	}
}

void	parse_flags(int *i, const char *str, va_list args, t_struct *list)
{
	while (str[*i] != '\0' && list->type == '0')
	{
		if (str[*i] == '*')
		{
			list->width = va_arg(args, int);
			if (list->width < 0)
			{
				list->width *= -1;
				list->flags_min = 1;
			}
		}
		else if (str[*i] >= '0' && str[*i] <= '9')
			parse_width(i, str, list);
		else if (str[*i] == '.')
			parse_prec(i, str, list, args);
		else if (str[*i] == 'd' || str[*i] == 'i' || str[*i] == 'u'
				|| str[*i] == 'c' || str[*i] == 's' || str[*i] == 'p'
				|| str[*i] == 'x' || str[*i] == 'X' || str[*i] == '%')
			list->type = str[*i];
		(*i)++;
	}
}

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

void	parse(int *i, const char *str, va_list args, t_struct *list)
{
	(*i)++;
	if (str[*i] == '-' || str[*i] == '0')
		parse_zero_minus(i, str, list);
	parse_flags(i, str, args, list);
	(*i)--;
	print_list(list, args);
}
