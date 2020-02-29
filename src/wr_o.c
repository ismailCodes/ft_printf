/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wr_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 12:35:03 by ismail            #+#    #+#             */
/*   Updated: 2020/02/29 13:01:01 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void	wr_o_helper_i(t_all *env, int *minwidth, int *prec, int len)
{
	*prec = ((int)env->prec_val > len) ? env->prec_val - len : 0;
	*minwidth = ((int)env->width - *prec - len > 0)
		? env->width - *prec - len : 0;
	if (!(env->flags & F_MINUS) && (env->prec_ex || !(env->flags & F_ZERO)))
	{
		if (env->flags & F_HASH && !((int)env->prec_val > len))
			*minwidth -= 1;
		while ((*minwidth)-- > 0 && (++env->o_backup))
			env->printed += write(1, " ", 1);
	}
	if (env->prec_ex)
		while ((*prec)-- > 0)
			env->printed += write(1, "0", 1);
	else if (!(env->flags & F_MINUS) && (env->flags & F_ZERO))
		while ((*minwidth)-- > 0 && (++env->o_backup))
			env->printed += write(1, "0", 1);
}

static void	wr_o_helper_ii(t_all *env, char *input_str, int *minwidth)
{
	ft_putstr_count(env, input_str);
	while ((*minwidth)-- > 0)
		env->printed += write(1, " ", 1);
	safe_free(input_str);
}

void		wr_o(t_all *env)
{
	unsigned long long	input;
	char				*input_str;
	int					len;
	int					prec;
	int					minwidth;

	input = wr_u_helper(env);
	input_str = (env->prec_ex && !env->prec_val && !input) ?
		ft_strdup("") : putnbr_base(input, get_base(env->conv));
	len = ft_strlen(input_str);
	wr_o_helper_i(env, &minwidth, &prec, len);
	if (env->flags & F_HASH && !((int)env->prec_val > len))
	{
		if (!(!input && ((env->width <= (size_t)len && !env->prec_ex))) &&
			!((size_t)(len + env->o_backup) == env->width))
			ft_putchar_count(env, '0');
		else if (!input && !env->width && env->prec_ex && !env->prec_val)
			ft_putchar_count(env, '0');
		minwidth--;
		if ((env->flags & F_MINUS) && env->width > 1 && !env->prec_ex && !input)
			ft_memcpy(input_str, " ", 2);
	}
	wr_o_helper_ii(env, input_str, &minwidth);
}
