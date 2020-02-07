/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 14:11:01 by ismail            #+#    #+#             */
/*   Updated: 2020/02/07 15:28:17 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		dp_parser(t_all *env)
{
	if (CUR_CHAR(0) == '%')
	{
		ft_putchar_count(env, '%');
		env->pos++;
		return (1);
	}
	else
		return (0);
}

void	spec_parser(t_all *env)
{
	is_flag(env) ? p_flag(env) : 1;
	(ft_isdigit(CUR_CHAR(0)) && CUR_CHAR(0) != '0') ?
		p_min_width(env) : 1;
	if (is_precision(env))
		p_precision(env);
	is_len_mod(env) ? p_len_mod(env) : 1;
}

void	percent_char(t_all *env)
{
	char	c;
	char	field;

	c = '%';
	field = ((env->flags & F_ZERO && !(env->flags & F_MINUS)) ? '0' : ' ');
	if (env->flags & F_MINUS)
	{
		ft_putchar_count(env, c);
		print_sp(env, env->width - 1, field);
	}
	else
	{
		print_sp(env, env->width - 1, field);
		ft_putchar_count(env, c);
	}
}

void	format_parser(t_all *env)
{
	if (CUR_CHAR(0) == '\0')
		return ;
	while (is_flag(env) || is_len_mod(env) || is_precision(env) ||
			(ft_isdigit(CUR_CHAR(0)) && CUR_CHAR(0) != '\0'))
		spec_parser(env);
	p_conversion(env);
	reinit_flags(env);
}
