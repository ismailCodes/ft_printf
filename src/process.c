/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 23:35:49 by ismail            #+#    #+#             */
/*   Updated: 2020/02/01 11:38:30 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	process(t_all *env)
{
	while (CUR_CHAR(0) != '\0')
	{
		if (CUR_CHAR(0) == '%')
		{
			env->pos++;
			format_parser(env);
		}
		else
			ft_putchar_count(env, CUR_CHAR(0));
		env->pos++;
	}
}
