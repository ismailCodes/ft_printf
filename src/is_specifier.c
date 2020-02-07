/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 12:53:51 by ismail            #+#    #+#             */
/*   Updated: 2020/02/01 11:43:38 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		is_flag(t_all *env)
{
	if (CUR_CHAR(0) == '#' || CUR_CHAR(0) == '0' ||
		CUR_CHAR(0) == '-' || CUR_CHAR(0) == '+' ||
		CUR_CHAR(0) == ' ')
		return (1);
	return (0);
}

int		is_len_mod(t_all *env)
{
	if (CUR_CHAR(0) == 'h' || CUR_CHAR(0) == 'l' ||
		CUR_CHAR(0) == 'L')
		return (1);
	return (0);
}

int		is_precision(t_all *env)
{
	if (CUR_CHAR(0) == '.')
		return (1);
	return (0);
}
