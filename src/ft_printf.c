/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 23:00:20 by ismail            #+#    #+#             */
/*   Updated: 2020/02/07 17:33:12 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_all		*env;
	char		*copy;

	if (!format)
		return (-1);
	copy = (char*)format;
	env = init_flags(copy);
	va_start(env->arglist, format);
	process(env);
	va_end(env->arglist);
	free_all();
	return (env->printed);
}
