/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 11:44:30 by eseveno           #+#    #+#             */
/*   Updated: 2015/02/17 12:59:22 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_hex_ptr(unsigned long i, int *n)
{
	char	c;

	if (i >= 16)
	{
		ft_print_hex_ptr(i / 16, n);
		ft_print_hex_ptr(i % 16, n);
	}
	else
	{
		if (i < 10)
		{
			c = 48 + i;
			write(1, &c, 1);
			(*n)++;
		}
		else
		{
			c = 87 + i;
			write(1, &c, 1);
			(*n)++;
		}
	}
}

void	ft_print_ptr(va_list *arg, int *n)
{
	unsigned long	i;

	i = va_arg((*arg), unsigned long);
	write(1, "0x", 2);
	(*n) = (*n) + 2;
	ft_print_hex_ptr(i, n);
}

void	ft_print_hex_nbr(unsigned int i, int *n, char x)
{
	char	c;

	if (i >= 16)
	{
		ft_print_hex_nbr(i / 16, n, x);
		ft_print_hex_nbr(i % 16, n, x);
	}
	else
	{
		if (i < 10)
		{
			c = 48 + i;
			write(1, &c, 1);
			(*n)++;
		}
		else
		{
			if (x == 'x')
				c = 87 + i;
			else if (x == 'X')
				c = 55 + i;
			write(1, &c, 1);
			(*n)++;
		}
	}
}

void	ft_print_hex(va_list *arg, int *n, char x)
{
	unsigned int	i;

	i = va_arg((*arg), unsigned int);
	ft_print_hex_nbr(i, n, x);
}
