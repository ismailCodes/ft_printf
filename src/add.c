/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 19:48:20 by nathan            #+#    #+#             */
/*   Updated: 2020/02/02 11:23:51 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_copy(size_t *src, size_t **dest, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		(*dest)[i] = src[i];
		i++;
	}
}

void	ft_and(size_t *a, size_t *b, size_t **c, int l)
{
	int i;

	i = 0;
	while (i < l)
	{
		(*c)[i] = a[i] & b[i];
		i++;
	}
}

void	ft_xor(size_t **a, size_t *b, int l)
{
	int i;

	i = 0;
	while (i < l)
	{
		(*a)[i] = (*a)[i] ^ b[i];
		i++;
	}
}

void	ft_add(size_t **a, size_t **b, int l)
{
	size_t *carry;

	if (!(carry = (size_t*)safe_malloc(sizeof(size_t) * l)))
		exit_free_all();
	while (verify_carry(*b, l) == 1)
	{
		ft_and(*a, *b, &carry, l);
		ft_xor(a, *b, l);
		ft_copy(carry, b, l);
		bit_shift_left(b, 1, l);
	}
	safe_free(carry);
}
