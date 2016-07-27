/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 13:01:49 by eseveno           #+#    #+#             */
/*   Updated: 2015/02/17 12:58:46 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (n == 0)
		return (1);
	if (s1 != NULL && s2 != NULL)
	{
		while (s1[i] == s2[i] && i < n)
		{
			if (s1[i + 1] == s2[i + 1] && s1[i + 1] == '\0')
				return (1);
			if (s1[i] == s2[i] && (i + 1) == n)
				return (1);
			i++;
		}
	}
	return (0);
}
