/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsego <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 17:52:14 by mmatsego          #+#    #+#             */
/*   Updated: 2021/02/03 14:09:51 by mmatsego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_int(char *output, int num, int len, t_list *list)
{
	char *tmp;

	if (len >= list->prec)
	{
		if (len >= list->width)
		{
			tmp = ft_itoa(num);
			ft_putstr(tmp);
		}
		else
		{
			if (

void	print_list(t_list *list, const char *str, va_list args)
{
	char	*output;

	if (list->type == 'd' || list->type == 'i')
	{
		malloc_int(&list, str, args);
	}
