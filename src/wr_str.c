/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wr_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 12:10:48 by ismail            #+#    #+#             */
/*   Updated: 2020/02/20 23:34:27 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_printlen(t_all *env, char *str, int len)
{
	int		i;

	i = 0;
	while (i < len && *str)
	{
		ft_putchar_count(env, *str);
		str++;
		i++;
	}
}

void	wr_str_prec(t_all *env, char *str, size_t len)
{
	if (env->width > len && (env->flags & F_MINUS))
	{
		ft_printlen(env, str, len);
		if (env->width < 2147483647)
			print_sp(env, (env->width - len), ' ');
	}
	else
	{
		if (env->width < 2147483647)
			print_sp(env, (env->width - len), ' ');
		ft_printlen(env, str, len);
	}
}

void	wr_str_noprec(t_all *env, char *str, size_t len, int min)
{
	if (env->width > len && (env->flags & F_MINUS))
	{
		ft_printlen(env, str, min);
		if (env->width < 2147483647)
			print_sp(env, env->width - min, ' ');
	}
	else
	{
		if (env->width < 2147483647)
			print_sp(env, env->width - min, ' ');
		ft_printlen(env, str, min);
	}
}

void	wr_str(t_all *env)
{
	char	*str;
	size_t	len;
	int		min;

	str = (char*)va_arg(env->arglist, char*);
	if (!str)
		str = ft_strdup("(null)");
	len = ft_strlen(str);
	min = (env->prec_ex && (size_t)env->prec_val < len) ?
		(size_t)env->prec_val : len;
	if (!env->prec_ex)
		wr_str_prec(env, str, min);
	else
		wr_str_noprec(env, str, min, min);
}
