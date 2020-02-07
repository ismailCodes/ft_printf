/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wr_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 12:04:12 by ismail            #+#    #+#             */
/*   Updated: 2020/02/02 11:24:25 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void		app_width(t_all *env, char **int_str)
{
	int		len;
	char	*ifzero;

	if (env->flags & F_ZERO && !(env->flags & F_MINUS) && !(env->prec_ex))
		ifzero = "0";
	else
		ifzero = " ";
	len = ft_strlen(*int_str);
	if ((int)env->width > len)
	{
		if (!(env->flags & F_MINUS) && ifzero[0] != '0')
			append(int_str, ifzero, env->width - len, 'b');
		else if (env->flags & F_MINUS)
			append(int_str, ifzero, env->width - len, 'e');
		else if (env->flags & F_ZERO && !(env->prec_val))
			append(int_str, ifzero, env->width - len, 'e');
	}
}

void		wr_int_helper2(t_all *env, int *minwidth, int *prec)
{
	if (!(env->flags & F_MINUS) && (env->prec_ex || !(env->flags & F_ZERO)))
		while ((*minwidth)-- > 0)
			env->printed += write(1, " ", 1);
	if (env->is_neg)
		env->printed += write(1, "-", 1);
	else if (env->flags & F_PLUS)
		env->printed += write(1, "+", 1);
	else if (env->flags & F_SPACE)
		env->printed += write(1, " ", 1);
	if (env->prec_ex)
		while ((*prec)-- > 0)
			env->printed += write(1, "0", 1);
	else if (!(env->flags & F_MINUS) && (env->flags & F_ZERO))
		while ((*minwidth)-- > 0)
			env->printed += write(1, "0", 1);
}

void		wr_int(t_all *env)
{
	intmax_t	integer;
	char		*int_str;
	int			len;
	int			prec;
	int			minwidth;

	integer = wr_int_helper(env);
	if (integer < 0)
	{
		integer = integer * -1;
		env->is_neg = 1;
	}
	int_str = (env->prec_ex && !env->prec_val && !integer) ?
		ft_strdup("") : ft_itoa_u(integer);
	len = ft_strlen(int_str);
	prec = ((int)env->prec_val > len) ? env->prec_val - len : 0;
	minwidth = ((int)env->width - prec - len > 0) ? env->width - prec - len : 0;
	minwidth -= (env->flags & F_PLUS ||
		env->flags & F_SPACE || env->is_neg) ? 1 : 0;
	wr_int_helper2(env, &minwidth, &prec);
	ft_putstr_count(env, int_str);
	while (minwidth-- > 0)
		env->printed += write(1, " ", 1);
	safe_free(int_str);
}
