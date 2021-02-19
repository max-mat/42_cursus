# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

# include <stdio.h>

typedef struct	s_struct
{
	int		width;
	int		prec;
	char	type;
	int		len;
	int		is_int_neg;
}				t_struct;

void	init_list(t_struct *list)
{
	list->width = 0;
	list->prec = -1;
	list->type = '0';
	list->len = 0;
	list->is_int_neg = 0;
}

int	ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int	i;
	char	*ptr;

	i = 0;
	if (!(ptr = malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

void	ft_putchar_len(t_struct *list, int num, char c)
{
	while (num > 0)
	{
		write(1, &c, 1);
		list->len++;
		num--;
	}
}

void	ft_putstr_len(t_struct *list, char *str, int len)
{
	while (*str != '\0' && len > 0)
	{
		ft_putchar_len(list, 1, *str);
		str++;
		len--;
	}
}

static size_t	ft_getnumlen(long long num, int base)
{
	size_t	len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num *= -1;
		len++;
	}
	while (num > 0)
	{
		num /= base;
		len++;
	}
	return (len);
}

char			*ft_itoa_base(unsigned long nbr, int base, char c)
{
	size_t	len;
	char	*str;

	len = ft_getnumlen(nbr, base);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	if (nbr == 0)
		str[0] = '0';
	while (len > 0)
	{
		str[len - 1] = nbr % base;
		if (str[len - 1] > 9)
		{
			if (c == 'x')
				str[len - 1] += 'a' - 10;
			else
				str[len - 1] += 'A' - 10;
		}
		else
			str[len - 1] += '0';
		nbr /= base;
		len--;
	}
	return (str);
}

void	print_result(t_struct *list, int len, char *tmp)
{
	if (list->width > list->prec && list->width > len)
	{
		if (list->prec > len)
			ft_putchar_len(list, list->width - list->prec, ' ');
		else
			ft_putchar_len(list, list->width - len, ' ');
	}
	if (list->is_int_neg)
		ft_putchar_len(list, 1, '-');
	if (list->prec > len)
		ft_putchar_len(list, list->prec - len, '0');
	ft_putstr_len(list, tmp, len);
}

void	print_int(t_struct *list, long num)
{
	char	*tmp;
	int		len;

	if (num == INT_MIN)
		tmp = ft_strdup("-2147483648");
	if (num < 0)
	{
		list->is_int_neg = 1;
		num *= -1;
		list->width--;
	}
	tmp = ft_itoa_base(num, 10, 'x');
	len = ft_strlen(tmp);
	if (list->prec == 0 && num == 0)
		len = 0;
	print_result(list, len, tmp);
	free(tmp);
}

void	print_x(t_struct *list, unsigned int num)
{
	char	*tmp;
	int		len;

	tmp = ft_itoa_base(num, 16, 'x');
	len = ft_strlen(tmp);
	if (list->prec == 0 && num == 0)
		len = 0;
	print_result(list, len, tmp);
	free(tmp);
}

void	print_s(t_struct *list, char *str)
{
	int	len;

	if (str == NULL)
		str = ft_strdup("(null)");
	if (list->prec > -1 && list->prec < ft_strlen(str))
		len = list->prec;
	else
		len = ft_strlen(str);
	ft_putchar_len(list, list->width - len, ' ');
	ft_putstr_len(list, str, len);
}

void	print_list(t_struct *list, va_list args)
{
	if (list->type == 'd')
		print_int(list, va_arg(args, int));
	else if (list->type == 'x')
		print_x(list, va_arg(args, unsigned int));
	else if (list->type == 's')
		print_s(list, va_arg(args, char *));
}

void	parse(int *i, const char *str, va_list args, t_struct *list)
{
	(*i)++;
	while (str[*i] != '\0' && list->type == '0')
	{
		if (str[*i] >= '0' && str[*i] <= '9')
		{
			int width;

			width = 0;
			while (str[*i] >= '0' && str[*i] <= '9')
			{
				width = width * 10 + (str[*i] - '0');
				(*i)++;
			}
			list->width = width;
		}
		if (str[*i] == '.')
		{
			int res;

			(*i)++;
			list->prec = 0;
			res = 0;
			if (str[*i] >= '0' && str[*i] <= '9')
			{
				while (str[*i] >= '0' && str[*i] <= '9')
				{
					res = res * 10 + (str[*i] - '0');
					(*i)++;
				}
				list->prec = res;
			}
		}
		if (str[*i] == 'd' || str[*i] == 's' || str[*i] == 'x')
			list->type = str[*i];
		(*i)++;
	}
	(*i)--;
	print_list(list, args);
}

int		ft_printf(const char *str, ...)
{
	va_list		args;
	t_struct	list;
	int			res;
	int			i;

	res = 0;
	i = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			init_list(&list);
			parse(&i, str, args, &list);
			res += list.len;
		}
		else
		{
			write(1, &str[i], 1);
			res++;
		}
		i++;
	}
	va_end(args);
	return (res);
}

int	main(void)
{
	printf("Magic %s is %5d", "number", 42);
	ft_printf("Magic %s is %5d", "number", 42);
}
