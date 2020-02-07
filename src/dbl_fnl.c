/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_fnl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 10:49:43 by ismail            #+#    #+#             */
/*   Updated: 2020/02/02 11:24:25 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	fl_app_sign(unsigned char sign, char **int_str)
{
	char *temp;

	temp = *int_str;
	if (sign == 1)
	{
		*int_str = ft_strjoin("-", *int_str);
		safe_free(temp);
	}
}

void	fl_app_flag(t_all *env, unsigned char s, char **int_str, char begend)
{
	if (env->flags & F_PLUS)
		(s == 0) ? append(int_str, "+", 1, 'b') : 1;
	if (!(env->flags & F_PLUS) && (env->flags & F_SPACE) &&
		!(env->flags & F_MINUS))
		append(int_str, " ", 1, begend);
	else if (!(env->flags & F_PLUS) &&
		(env->flags & F_SPACE) && (env->flags & F_MINUS))
		append(int_str, " ", 1, 'b');
}

void	fl_app_width(t_all *env, char **nan_str)
{
	int		len;
	char	*ifzero;

	if (env->flags & F_ZERO)
		ifzero = "0";
	else
		ifzero = " ";
	len = ft_strlen(*nan_str);
	if ((int)env->width > len)
	{
		(env->flags & F_MINUS) ?
		append(nan_str, ifzero, env->width - len, 'e') :
		append(nan_str, ifzero, env->width - len, 'b');
	}
}
