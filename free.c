/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 15:34:14 by eseveno           #+#    #+#             */
/*   Updated: 2015/12/02 15:34:42 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		ft_defrag(void *pointer)
{
	t_header *header;

	header = pointer;
	if (header->next && ((t_header*)header->next)->writable == true)
		merge_header(header, header->next);
	if (header->prev && ((t_header*)header->prev)->writable == true)
		merge_header(header->prev, header);
}

void		merge_header(t_header *current, t_header *after)
{
	current->size += sizeof(t_header) + after->size;
	if (after->next)
	{
		current->next = after->next;
		((t_header*)after->next)->prev = current;
	}
	else
		current->next = NULL;
}

void		freeforlarge(t_header *data)
{
	if (!data->prev)
	{
		if (!(((t_header*)data->next)->next))
			g_e.ptrlarge = NULL;
		else
		{
			((t_header*)((t_header*)data->next)->next)->prev = NULL;
			g_e.ptrlarge = ((t_header*)data->next)->next;
		}
	}
	else if (!((t_header*)data->next)->next)
		((t_header*)data->prev)->next = NULL;
	else
	{
		((t_header*)data->prev)->next = ((t_header*)data->next)->next;
		((t_header*)((t_header*)data->next)->next)->prev = data->prev;
	}
}

void		free(void *pointer)
{
	t_header *test;

	if (pointer && findinheader(pointer))
	{
		test = pointer - sizeof(t_header);
		if (test->size > SMALL)
		{
			freeforlarge(test);
			munmap(test, test->size + sizeof(t_header));
			pointer = NULL;
			return ;
		}
		else if (test->writable == false)
		{
			test->writable = true;
			ft_defrag(test);
		}
	}
}
