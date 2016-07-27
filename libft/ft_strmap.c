/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 12:01:00 by eseveno           #+#    #+#             */
/*   Updated: 2015/02/17 12:58:42 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		l;
	char	*map;
	char	*ss;

	ss = (char *)s;
	l = 0;
	if (ss != NULL)
	{
		while (ss[l])
			l++;
	}
	if ((map = (char *)malloc(l + 1)) == NULL)
		return (NULL);
	i = 0;
	if (ss != NULL && f != NULL)
	{
		while (ss[i])
		{
			map[i] = f(ss[i]);
			i++;
		}
	}
	map[i] = '\0';
	return (map);
}
