/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 14:16:32 by ismail            #+#    #+#             */
/*   Updated: 2020/02/01 11:48:30 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_putchar_count(t_all *env, char c)
{
	ft_putchar(c);
	env->printed++;
}

void	ft_putstr_count(t_all *env, char const *s)
{
	if (s)
	{
		while (*s)
		{
			ft_putchar_count(env, *s);
			s++;
		}
	}
}
