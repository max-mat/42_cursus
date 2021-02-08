/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsego <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 10:32:34 by mmatsego          #+#    #+#             */
/*   Updated: 2021/02/08 15:13:00 by mmatsego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>


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
** parse.c
*/
void	parse(int *i, const char *str, va_list args, t_struct *list);
void	parse_width(int *i, const char *str, t_struct *list);
void	parse_prec(int *i, const char *str, t_struct *list, va_list args);
void	parse_zero_minus(int *i, const char *str, t_struct *list);
void	parse_flags(int *i, const char *str, va_list args, t_struct *list);

/*
** print.c
*/
void	print_list(t_struct *list, va_list args);
void	print_int(t_struct *list, long num);
void	print_u(t_struct *list, unsigned int num);
void	print_x(t_struct *list, unsigned int num);
void	print_p(t_struct *list, size_t num);

/*
** print_char.c
*/
void	ft_putchar_len(t_struct *list, char c);
void	ft_putstr_len(t_struct *list, char *str, int len);
void	print_percent(t_struct *list, char c);
void	print_c(t_struct *list, char c);
void	print_s(t_struct *list, char *str);

/*
** utils_int.c
*/
void	print_zero_space(t_struct *list, int num, char c);
void	print_width(t_struct *list, int num);
void	is_int_neg(t_struct *list, long *num);
void	print_left_justified(t_struct *list, int len, char *tmp);
void	print_right_justified(t_struct *list, int len, char *tmp);

#endif
