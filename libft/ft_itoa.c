/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 16:56:47 by eseveno           #+#    #+#             */
/*   Updated: 2015/02/17 12:59:07 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_reverse_nbr(int save, char *c, char *end)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (c[j + 1] != '\0')
		j++;
	if (save < 0)
	{
		end[i] = '-';
		i++;
	}
	while (j >= 0)
	{
		end[i] = c[j];
		i++;
		j--;
	}
	end[i] = '\0';
	return (end);
}

static char		*ft_setnbr(int n, char *c)
{
	int		i;

	i = 0;
	if (n < 0)
		n = n * -1;
	while (n >= 10)
	{
		c[i] = (48 + (n % 10));
		n = n / 10;
		i++;
	}
	c[i] = (48 + (n));
	c[i + 1] = '\0';
	return (c);
}

static int		ft_count_nbr(int n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	i++;
	return (i);
}

static char		*ft_limit(void)
{
	char	*limit;
	char	*manual;

	limit = (char *)malloc(13);
	if (!limit)
		return (NULL);
	manual = "-2147483648";
	ft_strcpy(limit, manual);
	return (limit);
}

char			*ft_itoa(int n)
{
	int		nbr;
	char	*c;
	int		save;
	char	*end;
	char	*limit;

	if (n == -2147483648)
	{
		limit = ft_limit();
		return (limit);
	}
	save = n;
	nbr = ft_count_nbr(n);
	c = (char *)malloc(sizeof(nbr) * (nbr));
	if (c == NULL)
		return (NULL);
	c = ft_setnbr(n, c);
	end = (char *)malloc(sizeof(nbr) * (nbr));
	if (!end)
		return (NULL);
	end = ft_reverse_nbr(save, c, end);
	return (end);
}
