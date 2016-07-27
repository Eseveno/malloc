/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 15:38:41 by eseveno           #+#    #+#             */
/*   Updated: 2015/12/02 15:38:42 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		*ft_creat(size_t i, int type, void *prevaddr)
{
	t_header *header;

	g_e.tmp = mmap(0, type * getpagesize(),
		PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	header = g_e.tmp;
	header->size = i;
	if (prevaddr == NULL)
		header->prev = NULL;
	else
		header->prev = prevaddr;
	header->next = (void*)g_e.tmp + i + sizeof(t_header);
	header->writable = false;
	((t_header*)header->next)->writable = true;
	((t_header*)header->next)->size =
		type * getpagesize() - i - 2 * sizeof(t_header);
	((t_header*)header->next)->next = NULL;
	((t_header*)header->next)->prev = header;
	return ((void*)g_e.tmp + sizeof(t_header));
}

void		*ft_creatlarge(size_t i)
{
	t_header *tmp;
	t_header *data;

	tmp = mmap(0, (int)i + sizeof(t_header),
		PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if ((void*)tmp == (void*)-1)
		return (NULL);
	((t_header*)tmp)->size = i;
	((t_header*)tmp)->writable = false;
	((t_header*)tmp)->next = (void*)tmp + (int)i + sizeof(t_header);
	((t_header*)tmp)->prev = NULL;
	((t_header*)((t_header*)tmp)->next)->next = NULL;
	((t_header*)((t_header*)tmp)->next)->size = 0;
	((t_header*)((t_header*)tmp)->next)->writable = true;
	((t_header*)((t_header*)tmp)->next)->prev = tmp;
	data = (void *)tmp + sizeof(t_header);
	return (data);
}

void		print_header(t_header *header)
{
	int i;

	i = 0;
	while (header)
	{
		printf("size : %d\n", (int)header->size);
		printf("ptr : %x\n", (int)header);
		printf("ptr next : %x\n", (int)header->next);
		printf("ptr prev : %x\n", (int)header->prev);
		printf("writable : %s\n", header->writable ? "true" : "false");
		printf("\n %d\n", i);
		header = header->next;
		i++;
	}
}

bool		findinheader(void *addr)
{
	t_header	*header;

	header = g_e.ptrtiny;
	while (header && header->next)
	{
		if ((void*)header + sizeof(t_header) == addr)
			return (true);
		header = header->next;
	}
	header = g_e.ptrsmall;
	while (header && header->next)
	{
		if ((void*)header + sizeof(t_header) == addr)
			return (true);
		header = header->next;
	}
	header = g_e.ptrlarge;
	while (header && header->next)
	{
		if ((void*)header + sizeof(t_header) == addr)
			return (true);
		header = header->next;
	}
	return (false);
}
