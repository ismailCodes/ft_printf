/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wr_float3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 19:49:49 by nathan            #+#    #+#             */
/*   Updated: 2020/02/20 22:54:28 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

size_t	*new_table(int len)
{
	size_t	*ret;
	int		i;

	if (!(ret = (size_t*)safe_malloc(sizeof(size_t) * len)))
		exit_free_all();
	i = 0;
	while (i < len)
		ret[i++] = 0;
	return (ret);
}

int		verify_carry(size_t *carry, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (carry[i] != 0)
			return (1);
		i++;
	}
	return (0);
}

int		regulate_fl(char **fl_part, size_t k, int precision)
{
	size_t	borrow;
	char	c;

	if (k > 4)
	{
		borrow = 1;
		while (borrow != 0 && precision != 0)
		{
			c = (*fl_part)[precision - 1];
			(*fl_part)[precision - 1] = (c - '0' + borrow) % 10 + '0';
			borrow = (c - '0' + borrow) / 10;
			precision--;
		}
	}
	else
		borrow = 0;
	return (borrow);
}

void	ft_multiply_ten(size_t **table, int len)
{
	size_t	*b;
	int		i;

	i = 0;
	if (!(b = (size_t *)safe_malloc(sizeof(size_t) * len)))
		exit_free_all();
	while (i < len)
	{
		b[i] = (*table)[i];
		i++;
	}
	bit_shift_left(table, 3, len);
	bit_shift_left(&b, 1, len);
	ft_add(table, &b, len);
	safe_free(b);
}

int		ft_float(t_all *env, size_t *tbl_fl, char **part_fl, int dim)
{
	int		borrow;
	size_t	i;
	size_t	*table;
	size_t	*t;

	table = new_table(dim / 2 + 1);
	t = table + 1;
	ft_copy(tbl_fl + (dim / 2), &t, dim / 2);
	i = 0;
	while (i < env->prec_val)
	{
		ft_multiply_ten(&table, dim / 2);
		(*part_fl)[i++] = table[0] + '0';
		table[0] = 0;
	}
	ft_multiply_ten(&table, dim / 2);
	if (env->prec_val != 0)
		borrow = regulate_fl(part_fl, table[0], env->prec_val);
	else if ((tbl_fl[dim / 2 - 1] % 2 == 0 &&
				verify_carry(table + 1, dim / 2) == 0) || table[0] < 5)
		borrow = 0;
	else
		borrow = 1;
	safe_free(table);
	return (borrow);
}
