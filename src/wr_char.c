/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wr_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 22:51:53 by ismail            #+#    #+#             */
/*   Updated: 2020/02/01 12:19:37 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	print_sp(t_all *env, int spaces, char to_be_appended)
{
	int		i;

	i = 0;
	while (i < spaces)
	{
		ft_putchar_count(env, to_be_appended);
		i++;
	}
}

void	wr_char(t_all *env)
{
	char	c;

	c = (char)va_arg(env->arglist, int);
	if (env->flags & F_MINUS)
	{
		ft_putchar_count(env, c);
		print_sp(env, env->width - 1, ' ');
	}
	else
	{
		print_sp(env, env->width - 1, ' ');
		ft_putchar_count(env, c);
	}
}
