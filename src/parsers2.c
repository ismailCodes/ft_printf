/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 22:50:08 by ismail            #+#    #+#             */
/*   Updated: 2020/02/02 11:24:25 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	p_len_mod(t_all *env)
{
	if (CUR_CHAR(0) == 'h' && CUR_CHAR(1) == 'h')
	{
		env->len_mod |= LM_HH;
		env->pos += 1;
	}
	else if (CUR_CHAR(0) == 'h')
		env->len_mod |= LM_H;
	else if (CUR_CHAR(0) == 'l' && CUR_CHAR(1) == 'l')
	{
		env->len_mod |= LM_LL;
		env->pos += 1;
	}
	else if (CUR_CHAR(0) == 'L')
		env->len_mod |= LM_LUP;
	else if (CUR_CHAR(0) == 'l')
		env->len_mod |= LM_L;
	env->pos++;
}

void	p_precision(t_all *env)
{
	env->pos++;
	env->prec_ex = 1;
	if (CUR_CHAR(0) == '-')
	{
		env->pos++;
		env->prec_ex = 0;
	}
	while (CUR_CHAR(0) >= '0' && CUR_CHAR(0) <= '9')
	{
		env->prec_val *= 10;
		env->prec_val += (CUR_CHAR(0) - 48);
		env->pos++;
	}
	(env->prec_ex == 0) ? (env->prec_val = 0) : 1;
}

char	*get_min_width(t_all *env, int len)
{
	char	*holder;
	int		i;

	i = 0;
	holder = ft_strnew(len);
	if (!FT_CHECK(holder))
		exit_free_all();
	i = 0;
	while (ft_isdigit(CUR_CHAR(0)))
	{
		holder[i] = CUR_CHAR(0);
		env->pos++;
		i++;
	}
	holder[i] = '\0';
	return (holder);
}

void	p_min_width(t_all *env)
{
	int		i;
	char	*holder;

	i = 0;
	while (ft_isdigit(env->cp[i]))
		i++;
	holder = get_min_width(env, i);
	env->width = ft_atoi(holder);
	safe_free(holder);
}

void	p_flag(t_all *env)
{
	if (CUR_CHAR(0) == '#')
	{
		env->flags |= F_HASH;
		env->pos++;
	}
	else if (CUR_CHAR(0) == '0')
	{
		env->flags |= F_ZERO;
		env->pos++;
	}
	else if (CUR_CHAR(0) == '-')
	{
		env->flags |= F_MINUS;
		env->pos++;
	}
	else if (CUR_CHAR(0) == '+')
	{
		env->flags |= F_PLUS;
		env->pos++;
	}
	else if (CUR_CHAR(0) == ' ')
	{
		env->flags |= F_SPACE;
		env->pos++;
	}
}
