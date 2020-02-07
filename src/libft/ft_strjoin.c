/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 16:56:23 by ielmoudn          #+#    #+#             */
/*   Updated: 2020/02/02 11:22:24 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		i;

	new_str = NULL;
	i = 0;
	if (!(s1 && s2))
		exit_free_all();
	if (s1 || s2)
	{
		new_str = (char*)safe_malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (!new_str)
			exit_free_all();
		while (*s1)
			new_str[i++] = *s1++;
		while (*s2)
			new_str[i++] = *s2++;
		new_str[i] = '\0';
	}
	return (new_str);
}
