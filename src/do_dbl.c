/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_dbl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 10:59:05 by ismail            #+#    #+#             */
/*   Updated: 2020/02/02 11:24:25 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_printf_ld(t_all *env)
{
	t_ldouble_u		var;
	size_t			*table_float;

	var.val = va_arg(env->arglist, long double);
	if (var.ldbl.e == 32767)
		put_nan(env, var.ldbl.s, var.ldbl.f);
	else
	{
		table_float = new_table(514);
		table_float[256] = var.ldbl.q;
		table_float[257] = ((size_t)(var.ldbl.f)) << 1;
		bit_shift(&table_float, var.ldbl.e - 16383, 514);
		dsp_float(env, var.ldbl.s, table_float, 514);
		safe_free(table_float);
	}
}

void	ft_printf_dbl(t_all *env)
{
	t_double_u	var;
	size_t		*table_float;

	var.val = va_arg(env->arglist, double);
	if (var.dbl.e == 2047)
		put_nan(env, var.dbl.s, var.dbl.f);
	else
	{
		table_float = new_table(66);
		table_float[32] = var.dbl.e != 0;
		table_float[33] = ((size_t)(var.dbl.f)) << 12;
		bit_shift(&table_float, var.dbl.e - ((!var.dbl.e && var.dbl.f) ?
			1022 : 1023), 66);
		dsp_float(env, var.dbl.s, table_float, 66);
		safe_free(table_float);
	}
}
