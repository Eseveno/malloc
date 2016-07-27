/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 13:10:35 by eseveno           #+#    #+#             */
/*   Updated: 2015/10/30 16:12:13 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		showalloc_mem_tiny(t_header *header, int i)
{
	ft_printf("TINY : %p\n", header);
	while (header && header->next)
	{
		if (!header->writable)
		{
			i += ((int)header->next) - ((int)(header) + (int)sizeof(t_header));
			ft_printf("%p - %p : %d octets\n",
				(void*)header + sizeof(t_header), header->next,
				((int)header->next) - ((int)(header) + (int)sizeof(t_header)));
		}
		header = header->next;
	}
	return (i);
}

int		showalloc_mem_small(t_header *header, int i)
{
	ft_printf("SMALL : %p\n", header);
	while (header && header->next)
	{
		if (!header->writable)
		{
			i += ((int)header->next) - ((int)(header) + (int)sizeof(t_header));
			ft_printf("%p - %p : %d octets\n",
				(void*)header + sizeof(t_header), header->next,
				((int)header->next) - ((int)(header) + (int)sizeof(t_header)));
		}
		header = header->next;
	}
	return (i);
}

int		showalloc_mem_large(t_header *header, int i)
{
	ft_printf("LARGE : %p\n", header);
	while (header && header->next)
	{
		if (!header->writable)
		{
			i += ((int)header->next) - ((int)(header) + (int)sizeof(t_header));
			ft_printf("%p - %p : %d octets\n",
				(void*)header + sizeof(t_header), header->next,
				((int)header->next) - ((int)(header) + (int)sizeof(t_header)));
		}
		header = header->next;
	}
	return (i);
}

void	show_alloc_mem(void)
{
	t_header	*header;
	int			i;

	i = 0;
	header = g_e.ptrtiny;
	i = showalloc_mem_tiny(header, i);
	header = g_e.ptrsmall;
	i = i + showalloc_mem_small(header, i);
	header = g_e.ptrlarge;
	i = i + showalloc_mem_large(header, i);
	ft_printf("TOTAL = %d octets\n", i);
}
