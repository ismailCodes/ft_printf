/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wr_addr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 18:28:25 by ismail            #+#    #+#             */
/*   Updated: 2020/02/01 12:18:43 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	wr_addr(t_all *env)
{
	size_t		addr;
	char		*result;

	result = NULL;
	addr = va_arg(env->arglist, unsigned long);
	result = putnbr_base(addr, "0123456789abcdef");
	if (env->flags & F_MINUS)
	{
		ft_putstr_count(env, "0x");
		ft_putstr_count(env, result);
		print_sp(env, (env->width - putnbr_base_count(addr, 16) - 2), ' ');
	}
	else
	{
		print_sp(env, (env->width - putnbr_base_count(addr, 16) - 2), ' ');
		ft_putstr_count(env, "0x");
		ft_putstr_count(env, result);
	}
}
