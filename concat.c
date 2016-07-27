/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 15:19:39 by eseveno           #+#    #+#             */
/*   Updated: 2015/12/02 15:19:40 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		ft_concat_large(void *data)
{
	t_header *header;

	header = g_e.ptrlarge;
	data = (void*)data - sizeof(t_header);
	while (header->next)
		header = header->next;
	((t_header*)data)->prev = header;
	header->next = (t_header*)data;
}

void		ft_concattiny(int memory, int i, t_header *header)
{
	header->next = mmap(0, TINY * getpagesize(),
		PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	((t_header*)header->next)->prev = header;
	((t_header*)header->next)->next = NULL;
	((t_header*)header->next)->size =
		memory - i - sizeof(t_header) + TINY * getpagesize();
	((t_header*)header->next)->writable = true;
}

void		ft_concat2(int memory, int i, t_header *header)
{
	if (memory - i - sizeof(t_header) < TINY && i <= TINY)
		ft_concattiny(memory, i, header);
	else if (memory - i - sizeof(t_header) < SMALL && i > TINY)
	{
		header->next = mmap(0, SMALL * getpagesize(),
			PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
		((t_header*)header->next)->prev = header;
		((t_header*)header->next)->next = NULL;
		((t_header*)header->next)->size =
			memory - i - sizeof(t_header) + SMALL * getpagesize();
		((t_header*)header->next)->writable = true;
	}
	else
	{
		header->next = (void *)header + header->size + sizeof(t_header);
		((t_header*)header->next)->writable = true;
		((t_header*)header->next)->size = memory - i - sizeof(t_header);
		((t_header*)header->next)->next = NULL;
		((t_header*)header->next)->prev = header;
	}
}

void		*ft_concat(size_t i)
{
	t_header	*header;
	t_header	*tmp;
	int			memory;
	void		*prev;

	header = g_e.tmp;
	tmp = NULL;
	while (header && !(header->writable == true && header->size >= i))
	{
		prev = header;
		header = header->next;
	}
	if (header)
	{
		memory = header->size;
		header->size = i;
		header->prev = prev;
		header->writable = false;
		tmp = (void*)header + sizeof(t_header);
		if (!header->next)
			ft_concat2(memory, i, header);
	}
	return (tmp);
}
