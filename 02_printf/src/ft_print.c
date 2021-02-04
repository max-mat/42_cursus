/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsego <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 17:52:14 by mmatsego          #+#    #+#             */
/*   Updated: 2021/02/04 18:27:50 by mmatsego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_int(t_struct *list, int num)
{
	char	*tmp;
	int		len;

	is_int_neg(list, &num);
	tmp = ft_itoa(num);
	len = ft_strlen(tmp);
	if (list->prec > len)
	{
		if (list->width > list->prec)
			print_width(list, list->width - list->prec);
		if (list->is_int_neg)
			ft_putchar('-');
		print_zero(list->prec - len);
	}
	else if (list->width > len)
	{
		if (list->is_int_neg)
			ft_putchar('-');
		print_width(list, list->width - len);
	}
	ft_putstr(tmp);
	free(tmp);
}
	
void	print_list(t_struct *list, va_list args)
{
	if (list->type == 'd' || list->type == 'i')
	{
		print_int(list, va_arg(args, int));
	}
}
