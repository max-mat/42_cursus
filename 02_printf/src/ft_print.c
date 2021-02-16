/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsego <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 17:52:14 by mmatsego          #+#    #+#             */
/*   Updated: 2021/02/08 17:08:23 by mmatsego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_int(t_struct *list, long num)
{
	char	*tmp;
	int		len;

	if (num == INT_MIN)
		tmp = ft_strdup("-2147483648");
	else
	{
		is_int_neg(list, &num);
		tmp = ft_itoa(num);
	}
	len = ft_strlen(tmp);
	if (list->prec == 0 && num == 0)
		len = 0;
	if (list->flags_min)
		print_left_justified(list, len, tmp);
	else
		print_right_justified(list, len, tmp);
	free(tmp);
}

void	print_u(t_struct *list, unsigned int num)
{
	char	*tmp;
	int		len;

	tmp = ft_itoa(num);
	len = ft_strlen(tmp);
	if (list->prec == 0 && num == 0)
		len = 0;
	if (list->flags_min)
		print_left_justified(list, len, tmp);
	else
		print_right_justified(list, len, tmp);
	free(tmp);
}

void	print_x(t_struct *list, unsigned int num)
{
	char	*tmp;
	int		len;

	if (list->type == 'x')
		tmp = ft_itoa_base(num, 16, 'x');
	else
		tmp = ft_itoa_base(num, 16, 'X');
	len = ft_strlen(tmp);
	if (list->prec == 0 && num == 0)
		len = 0;
	if (list->flags_min)
		print_left_justified(list, len, tmp);
	else
		print_right_justified(list, len, tmp);
	free(tmp);
}

void	print_p(t_struct *list, size_t num)
{
	char	*tmp;
	int		len;

	tmp = ft_strjoin("0x", ft_itoa_base(num, 16, 'x'));
	len = ft_strlen(tmp);
	if (list->flags_min)
		print_left_justified(list, len, tmp);
	else
		print_right_justified(list, len, tmp);
	free(tmp);
}

void	print_list(t_struct *list, va_list args)
{
	if (list->type == 'd' || list->type == 'i')
		print_int(list, va_arg(args, int));
	else if (list->type == 'u')
		print_u(list, va_arg(args, unsigned int));
	else if (list->type == 'x' || list->type == 'X')
		print_x(list, va_arg(args, unsigned int));
	else if (list->type == 'p')
		print_p(list, va_arg(args, size_t));
	else if (list->type == 'c')
		print_c(list, va_arg(args, int));
	else if (list->type == 's')
		print_s(list, va_arg(args, char *));
	else if (list->type == '%')
		print_percent(list, '%');
}
