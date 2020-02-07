/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 12:06:16 by ismail            #+#    #+#             */
/*   Updated: 2020/02/01 12:25:51 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

intmax_t		wr_int_helper(t_all *env)
{
	intmax_t	integer;

	integer = va_arg(env->arglist, intmax_t);
	if (env->len_mod & LM_HH)
		integer = (char)integer;
	else if (env->len_mod & LM_H)
		integer = (short int)integer;
	else if (env->len_mod & LM_L)
		integer = (long int)integer;
	else if (env->len_mod & LM_LL)
		integer = (long long int)integer;
	else
		integer = (int)integer;
	return (integer);
}

void			app_sign(t_all *env, char **int_str)
{
	if (env->is_neg)
		ft_strcat("-", *int_str);
}

void			app_prec(t_all *env, char **int_str, char beg_end)
{
	int			len;

	len = ft_strlen(*int_str);
	if (env->prec_ex)
	{
		if (env->prec_val > len)
			append(int_str, "0", env->prec_val - len, beg_end);
	}
}

void			app_flag(t_all *env, char **int_str, char begend)
{
	if (env->flags & F_PLUS)
		(!env->is_neg) ? append(int_str, "+", 1, 'b') : 1;
	if (!(env->flags & F_PLUS) && (env->flags & F_SPACE) &&
		!(env->flags & F_MINUS))
		append(int_str, " ", 1, begend);
	else if (!(env->flags & F_PLUS) && (env->flags & F_SPACE) &&
		(env->flags & F_MINUS))
		append(int_str, " ", 1, 'b');
}
