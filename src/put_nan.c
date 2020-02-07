/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nan.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 09:16:43 by ismail            #+#    #+#             */
/*   Updated: 2020/02/02 11:24:25 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	nan_app_width(t_all *env, char **nan_str)
{
	int		len;
	char	*ifzero;

	ifzero = " ";
	len = ft_strlen(*nan_str);
	if ((int)env->width > len)
	{
		(env->flags & F_MINUS) ?
		append(nan_str, ifzero, env->width - len, 'e') :
		append(nan_str, ifzero, env->width - len, 'b');
	}
}

void	nan_app_flag(t_all *env, unsigned char s, char **int_str, char begend)
{
	if (env->flags & F_PLUS)
		(s == 0) ? append(int_str, "+", 1, begend) : 1;
	(!(env->flags & F_PLUS) && (env->flags & F_SPACE) && !s) ?
	append(int_str, " ", 1, begend) : 1;
}

void	nan_app_sign(unsigned char sign, char **int_str)
{
	if (sign == 1)
		*int_str = ft_strjoin("-", *int_str);
}

void	put_nan(t_all *env, unsigned char sign, unsigned long frac)
{
	char		*nan_str;

	if (frac != 0)
		nan_str = "nan";
	else
	{
		nan_str = "inf";
		nan_app_sign(sign, &nan_str);
		nan_app_flag(env, sign, &nan_str, 'b');
	}
	nan_app_width(env, &nan_str);
	ft_putstr_count(env, nan_str);
	if (sign == 1)
		safe_free(nan_str);
}
