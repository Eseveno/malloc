/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 10:35:48 by eseveno           #+#    #+#             */
/*   Updated: 2015/02/17 12:58:47 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;
	int		i;

	new = (char *)malloc(sizeof(size) * (size + 1));
	if (!new)
		return (0);
	i = 0;
	while (new[i])
	{
		new[i] = '\0';
		i++;
	}
	new[i] = '\0';
	return (new);
}
