/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_malloc.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 01:27:34 by yfarini           #+#    #+#             */
/*   Updated: 2020/02/02 11:07:24 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAFE_MALLOC_H
# define SAFE_MALLOC_H

# include "../libft/libft.h"

typedef struct	s_lst
{
	void			*ptr;
	struct s_lst	*next;
}				t_lst;

t_lst			**global_list_allocation(void);
t_lst			*lstnew_m(void *content);
int				lstdelone_m(t_lst *lst, void (*del)(void*));
void			lstclear_m(t_lst **lst, void (*del)(void*));
void			lstadd_front_m(t_lst **alst, t_lst *new);
void			free_all(void);
void			exit_free_all(void);
void			*safe_malloc(size_t size);
void			safe_free(void *ptr);

#endif
