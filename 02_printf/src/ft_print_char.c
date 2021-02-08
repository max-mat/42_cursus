/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsego <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:34:19 by mmatsego          #+#    #+#             */
/*   Updated: 2021/02/08 12:08:03 by mmatsego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putchar_len(t_struct *list, char c)
{
	write(1, &c, 1);
	list->len++;
}

void	ft_putstr_len(t_struct *list, char *str, int len)
{
	while (*str != '\0' && len > 0)
	{
		ft_putchar_len(list, *str);
		str++;
		len--;
	}
}

void	print_percent(t_struct *list, char c)
{
	if (list->width < 0)
	{
		list->width *= -1;
		list->flags_min = 1;
	}
	if (list->flags_min)
	{
		ft_putchar_len(list, c);
		print_zero_space(list, list->width - 1, ' ');
	}
	else
	{
		if (list->flags_zero)
			print_zero_space(list, list->width - 1, '0');
		else
			print_zero_space(list, list->width - 1, ' ');
		ft_putchar_len(list, c);
	}
}
void	print_c(t_struct *list, char c)
{
	if (list->width < 0)
	{
		list->width *= -1;
		list->flags_min = 1;
	}
	if (list->flags_min)
	{
		ft_putchar_len(list, c);
		print_width(list, list->width - 1);
	}
	else
	{
		print_width(list, list->width - 1);
		ft_putchar_len(list, c);
	}
}

void	print_s(t_struct *list, char *str)
{
	int	len;
	if (str == NULL)
		str = ft_strdup("(null)");
	len = ft_strlen(str);
	if (list->width < 0)
	{
		list->width *= -1;
		list->flags_min = 1;
	}
	if (list->prec == 0)
		len = 0;
	else if (list->prec > 0 && list->prec < len)
		len = list->prec;
	if (list->flags_min)
	{
		ft_putstr_len(list, str, len);
		print_width(list, list->width - len);
	}
	else
	{
		print_width(list, list->width - len);
		ft_putstr_len(list, str, len);
	}
}
