/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismail <ismail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 15:27:37 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/12/21 20:42:38 by ismail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*newdest;
	unsigned char	*newsrc;

	newdest = (unsigned char*)dst;
	newsrc = (unsigned char*)src;
	if (dst > src)
	{
		while (n)
		{
			n--;
			newdest[n] = newsrc[n];
		}
	}
	else
		ft_memcpy(newdest, newsrc, n);
	return (dst);
}
