/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 11:50:20 by nathan            #+#    #+#             */
/*   Updated: 2020/02/07 15:24:13 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void	get_conv(t_all *env, char conv_char)
{
	env->conv = conv_char;
	(conv_char == '%') ? percent_char(env) : 1;
	(conv_char == 'c') ? wr_char(env) : 1;
	(conv_char == 's') ? wr_str(env) : 1;
	(conv_char == 'p') ? wr_addr(env) : 1;
	(conv_char == 'd' || conv_char == 'i') ? wr_int(env) : 1;
	(conv_char == 'x' || conv_char == 'X') ? wr_x(env) : 1;
	(conv_char == 'o') ? wr_o(env) : 1;
	(conv_char == 'u') ? wr_u(env) : 1;
	(conv_char == 'f') ? wr_float(env) : 1;
}

void		p_conversion(t_all *env)
{
	size_t	i;

	i = 0;
	while (CONVERSION[i] != '\0')
	{
		if (CONVERSION[i] == CUR_CHAR(0))
		{
			get_conv(env, CONVERSION[i]);
			break ;
		}
		i++;
	}
}
