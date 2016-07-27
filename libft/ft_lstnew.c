/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 10:22:39 by eseveno           #+#    #+#             */
/*   Updated: 2015/02/17 12:59:14 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*chain;

	chain = (t_list *)malloc(sizeof(t_list));
	if (chain == NULL)
		return (NULL);
	chain->content = (void *)malloc(sizeof(size_t) * (content_size));
	if (chain->content == NULL)
		return (NULL);
	if (content == NULL)
	{
		chain->content = NULL;
		chain->content_size = 0;
	}
	else
	{
		chain->content = ft_memcpy(chain->content, content, content_size);
		chain->content_size = content_size;
		chain->next = NULL;
	}
	return (chain);
}
