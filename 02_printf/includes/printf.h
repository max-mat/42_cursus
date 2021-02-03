/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsego <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 10:32:34 by mmatsego          #+#    #+#             */
/*   Updated: 2021/02/02 17:16:50 by mmatsego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

#include "libft.h"

typedef struct	s_list
{
	int		flags_min;
	int		flags_0;
	int		width;
	int		prec;
	char	type;
	int		len;
}				t_list;

int	ft_printf(const char *str, ...);

/*
** parse_flags.c
*/
void	parse_flags(int *i, const char *str, va_list args, int *p);

/*
** flags_align.c
*/
void	parse_rightalign(int *i, const char *str, va_list args, int *p);
void	parse_leftalign(int *i, const char *str, va_list args, int *p);

/*
** flags_zero.c
*/
void	parse_zero(int *i, const char *str, va_list args, int *p);

/*
** flags_int.c
*/
void	flags_int(va_list args, int *p);
void	flags_uint(va_list args, int *p);
void	flags_hex(va_list args, int *p);
void	flags_uhex(va_list args, int *p);

/*
** flags_adr.c
*/
void	flags_adr(va_list args, int *p);
void	flags_per(int *p);

/*
** flags_str.c
*/
void	flags_str(va_list args, int *p);
void	flags_char(va_list args, int *p);

#endif
