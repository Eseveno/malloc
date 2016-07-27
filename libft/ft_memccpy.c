/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:09:09 by eseveno           #+#    #+#             */
/*   Updated: 2015/02/17 12:59:16 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t		i;
	char		*ss1;
	const char	*ss2;

	ss1 = s1;
	ss2 = s2;
	i = 0;
	while (i < n)
	{
		if (ss2[i] == c)
		{
			ss1[i] = c;
			i++;
			return (&(ss1[i]));
		}
		ss1[i] = ss2[i];
		i++;
	}
	return (0);
}
