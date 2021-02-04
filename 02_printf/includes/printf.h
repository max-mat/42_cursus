/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsego <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 10:32:34 by mmatsego          #+#    #+#             */
/*   Updated: 2021/02/04 17:15:10 by mmatsego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>



#include <stdio.h>



#include "libft.h"

typedef struct	s_struct
{
	int		flags_min;
	int		flags_zero;
	int		width;
	int		prec;
	char	type;
	int		len;
	int		is_int_neg;
}				t_struct;

int		ft_printf(const char *str, ...);
void	init_list(t_struct *list);

/*
** parse_flags.c
*/
void	parse_flags(int *i, const char *str, va_list args, t_struct *list);
void	parse_width(int *i, const char *str, t_struct *list);
void	parse_prec(int *i, const char *str, t_struct *list, va_list args);

/*
** print.c
*/
void	print_list(t_struct *list, va_list args);
void	print_int(t_struct *list, int num);

/*
** utils.c
*/
void	print_zero(int num);
void	print_space(int num);
void	is_int_neg(t_struct *list, int *num);
void	print_width(t_struct *list, int num);

#endif
