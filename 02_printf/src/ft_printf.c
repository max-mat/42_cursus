/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsego <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:50:24 by mmatsego          #+#    #+#             */
/*   Updated: 2021/02/03 14:08:35 by mmatsego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	g_res;

void	init_list(t_list *list)
{
	list->flags_min = 0;
	list->flags_zero = 0;
	list->width = 0;
	list->prec = 0;
	list->type = '0';
	list->len = 0;
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_list	*list;
	int		i;

	g_res = 0;
	i = -1;
	va_start(args, str);
	while (str[++i] != 0)
	{
		if (str[i] == '%')
			init_list(list);
			parse_flags(&i, str, args, list);
		else
		{
			write(1, &str[i], 1);
			g_res++;
		}
	}
	va_end(args);
	return (g_res);
}
