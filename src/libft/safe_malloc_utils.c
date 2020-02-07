/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_malloc_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfarini <yfarini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 01:19:33 by yfarini           #+#    #+#             */
/*   Updated: 2020/01/25 03:53:20 by yfarini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "safe_malloc.h"

t_lst	**global_list_allocation(void)
{
	static t_lst *lst;

	return (&lst);
}

t_lst	*lstnew_m(void *content)
{
	t_lst *t_l;

	t_l = (t_lst *)malloc(sizeof(t_lst));
	if (!t_l)
		return (NULL);
	t_l->ptr = content;
	t_l->next = NULL;
	return (t_l);
}

int		lstdelone_m(t_lst *lst, void (*del)(void*))
{
	if (lst && del)
	{
		del(lst->ptr);
		free(lst);
	}
	return (1);
}

void	lstclear_m(t_lst **lst, void (*del)(void*))
{
	t_lst *next;

	while (*lst && del)
	{
		next = (*lst)->next;
		lstdelone_m(*lst, del);
		*lst = next;
	}
}

void	lstadd_front_m(t_lst **alst, t_lst *new)
{
	if (*alst && new)
		new->next = *alst;
	*alst = new;
}
