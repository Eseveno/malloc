/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:12:30 by eseveno           #+#    #+#             */
/*   Updated: 2015/02/17 12:58:40 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		dst_len;
	size_t		src_len;
	size_t		i;
	size_t		c;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	c = 0;
	if (size <= dst_len)
		return (size + src_len);
	while (dst[i] != '\0')
		i++;
	while (src[c] != '\0' && i < (size - 1))
	{
		dst[i] = src[c];
		i++;
		c++;
	}
	dst[i] = '\0';
	return (dst_len + src_len);
}
