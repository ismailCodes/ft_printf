/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 22:14:07 by yfarini           #+#    #+#             */
/*   Updated: 2020/02/02 11:07:21 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "safe_malloc.h"

void	free_all(void)
{
	lstclear_m(global_list_allocation(), free);
	*global_list_allocation() = NULL;
}

void	exit_free_all(void)
{
	free_all();
	exit(-1);
}

void	*safe_malloc(size_t size)
{
	t_lst	**lst;
	void	*data;

	lst = global_list_allocation();
	data = malloc(size);
	if (!data)
		exit_free_all();
	lstadd_front_m(lst, lstnew_m(data));
	return (data);
}

void	safe_free(void *ptr)
{
	t_lst	**lst;
	t_lst	*tmp;
	t_lst	*prev;

	lst = global_list_allocation();
	tmp = *lst;
	prev = NULL;
	while (tmp && tmp->ptr != ptr)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp)
	{
		if (prev == NULL)
			((tmp = (*lst)->next) || 1) &&
			lstdelone_m((*lst), free) && (*lst = tmp);
		else
		{
			prev->next = tmp->next;
			lstdelone_m((tmp), free);
		}
	}
	else
		free(ptr);
}
