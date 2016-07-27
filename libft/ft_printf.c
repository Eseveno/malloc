/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 16:51:38 by eseveno           #+#    #+#             */
/*   Updated: 2015/02/17 12:58:12 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printf(const char *str, ...)
{
	va_list		arg;
	int			i;

	va_start(arg, str);
	i = ft_str_print(str, &arg);
	va_end(arg);
	return (i);
}

int		ft_str_print(const char *str, va_list *arg)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	(void)arg;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] == '%')
		{
			write(1, "%", 1);
			i = i + 2;
			n++;
		}
		else if (str[i] == '%' && str[i + 1] != '%')
			ft_read_prc(str, &i, arg, &n);
		else
		{
			ft_write_str(str[i], &n);
			i++;
		}
	}
	return (n);
}

void	ft_write_str(char c, int *n)
{
	write(1, &c, 1);
	(*n)++;
}

void	ft_read_prc(const char *str, int *i, va_list *arg, int *n)
{
	int		j;
	int		o;

	(*i)++;
	if (str[(*i)] == 'c')
		ft_print_char(arg, n);
	else if (str[(*i)] == 's')
		ft_print_str(arg, n);
	else if (str[(*i)] == 'd' || str[(*i)] == 'i')
		ft_print_int(arg, n);
	else if (str[(*i)] == 'u')
		ft_print_uns(arg, n);
	else if (str[(*i)] == 'o')
		ft_print_oct(arg, n);
	else if (str[(*i)] == 'x' || str[(*i)] == 'X')
		ft_print_hex(arg, n, str[(*i)]);
	else if (str[(*i)] == 'p')
		ft_print_ptr(arg, n);
	else
		ft_write_str(str[(*i)], n);
	(*i)++;
}
