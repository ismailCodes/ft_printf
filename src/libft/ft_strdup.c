/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 15:10:00 by ielmoudn          #+#    #+#             */
/*   Updated: 2020/02/02 11:16:40 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;

	str = (char*)safe_malloc(ft_strlen(s1) + 1);
	if (str == NULL)
		exit_free_all();
	ft_strcpy(str, s1);
	return (str);
}
