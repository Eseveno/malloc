/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:19:32 by eseveno           #+#    #+#             */
/*   Updated: 2015/06/01 17:44:47 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char		*ss1;
	const char	*ss2;

	ss1 = s1;
	ss2 = s2;
	if (ss1 >= ss2)
	{
		ss1 += n - 1;
		ss2 += n - 1;
		while (n > 0)
		{
			*ss1 = *ss2;
			ss1--;
			ss2--;
			n--;
		}
	}
	else
		ft_memcpy(s1, s2, n);
	return (s1);
}
