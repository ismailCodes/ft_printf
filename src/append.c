/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 19:31:20 by ismail            #+#    #+#             */
/*   Updated: 2020/02/01 11:44:21 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_swap(char **a, char **b)
{
	char **tmp;

	tmp = a;
	a = b;
	b = tmp;
}

void	append(char **dest, char *add, int num, char beg_end)
{
	int		i;

	i = 0;
	if (beg_end == 'b')
	{
		while (i < num)
		{
			*dest = ft_strjoin(add, *dest);
			i++;
		}
	}
	if (beg_end == 'e')
	{
		while (i < num)
		{
			*dest = ft_strjoin(*dest, add);
			i++;
		}
	}
}
