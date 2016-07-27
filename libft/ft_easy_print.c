/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_easy_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 11:42:30 by eseveno           #+#    #+#             */
/*   Updated: 2015/02/17 12:59:20 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_neg_limit(int *n)
{
	write(1, "-2147483648", 11);
	(*n) = (*n) + 11;
}

void	ft_print_nbr(int i, int *n)
{
	char	c;

	if (i == -2147483648)
		ft_neg_limit(n);
	else
	{
		if (i < 0)
		{
			write(1, "-", 1);
			i = -i;
			(*n)++;
		}
		if (i >= 10)
		{
			ft_print_nbr(i / 10, n);
			ft_print_nbr(i % 10, n);
		}
		else
		{
			c = 48 + i;
			write(1, &c, 1);
			(*n)++;
		}
	}
}

void	ft_print_int(va_list *arg, int *n)
{
	int		i;
	char	*s;

	i = va_arg((*arg), int);
	ft_print_nbr(i, n);
}

void	ft_print_char(va_list *arg, int *n)
{
	char	c;

	c = va_arg((*arg), int);
	write(1, &c, 1);
	(*n)++;
}

void	ft_print_str(va_list *arg, int *n)
{
	char	*s;
	int		j;

	j = 0;
	s = va_arg((*arg), char *);
	if (s == NULL)
	{
		write(1, "(null)", 6);
		(*n) = (*n) + 6;
		return ;
	}
	while (s[j] != '\0')
	{
		j++;
		(*n)++;
	}
	write(1, s, j);
}
