/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_shift.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:05:18 by ismail            #+#    #+#             */
/*   Updated: 2020/02/01 11:44:44 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	bit_shift_right(size_t **table, int shift, int dim_st)
{
	int				i;
	size_t			res1;
	size_t			res2;
	unsigned int	a;

	shift = -1 * shift;
	while (shift != 0)
	{
		shift--;
		a = shift % 64 + 1;
		shift = (shift / 64) * 64;
		i = 0;
		res1 = 0;
		while (i < dim_st)
		{
			res2 = ((*table)[i] << (64 - a));
			(*table)[i] = ((*table)[i] >> a) * (a != 64) + res1;
			res1 = res2;
			i++;
		}
	}
}

void	bit_shift_left(size_t **table, int shift, int dim_st)
{
	size_t			res1;
	size_t			res2;
	int				i;
	unsigned int	a;

	while (shift != 0)
	{
		shift--;
		a = shift % 64 + 1;
		shift = (shift / 64) * 64;
		i = dim_st - 1;
		res1 = 0;
		res2 = 0;
		while (i >= 0)
		{
			res2 = ((*table)[i] >> (64 - a));
			(*table)[i] = (((*table)[i]) << a) * (a != 64) + res1;
			res1 = res2;
			i--;
		}
	}
}

void	bit_shift(size_t **t, int shift, int l)
{
	if (shift < 0)
		bit_shift_right(t, shift, l);
	else if (shift > 0)
		bit_shift_left(t, shift, l);
}
