/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wr_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 14:29:45 by ismail            #+#    #+#             */
/*   Updated: 2020/02/02 11:24:25 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ft_int(size_t *t_fl, int dim, int carry)
{
	char	*ret;
	int		len;
	size_t	*part_i;
	size_t	*carry_table;

	len = (64 * ((dim / 2) * 7) / 23) / 18 + 1;
	part_i = new_table(len);
	get_part_int(t_fl, &part_i, dim / 2, len);
	carry_table = new_table(len);
	carry_table[len - 1] = carry;
	ft_add_int(&part_i, carry_table, len);
	safe_free(carry_table);
	ret = int_to_str(part_i, len);
	safe_free(part_i);
	return (ret);
}

void	dsp_float_h(t_all *env, int *minwidth, char *int_part, unsigned char s)
{
	if (!(env->flags & F_MINUS) && !(env->flags & F_ZERO))
		while ((*minwidth)-- > 0)
			env->printed += write(1, " ", 1);
	if (s == 1)
		env->printed += write(1, "-", 1);
	else if (env->flags & F_PLUS)
		env->printed += write(1, "+", 1);
	else if (env->flags & F_SPACE)
		env->printed += write(1, " ", 1);
	if (!(env->flags & F_MINUS) && (env->flags & F_ZERO))
		while ((*minwidth)-- > 0)
			env->printed += write(1, "0", 1);
	ft_putstr_count(env, int_part);
	while ((*minwidth)-- > 0)
		env->printed += write(1, " ", 1);
	safe_free(int_part);
}

char	*dsp_fl_h(t_all *env, char **fl_part, size_t *t_fl, int dim)
{
	int carry;

	if (env->prec_ex == 0 || (env->prec_val < 0))
		env->prec_val = 6;
	*fl_part = ft_strnew(env->prec_val + 1);
	carry = ft_float(env, t_fl, fl_part, dim);
	return (ft_int(t_fl, dim, carry));
}

void	dsp_float(t_all *env, unsigned char s, size_t *t_fl, int dim)
{
	char	*int_part;
	char	*fl_part;
	char	*tmp;
	int		len;
	int		minwidth;

	int_part = dsp_fl_h(env, &fl_part, t_fl, dim);
	tmp = int_part;
	if (!(env->prec_ex != 0 && env->prec_val == 0))
	{
		int_part = ft_strjoin(int_part, ".");
		safe_free(tmp);
	}
	tmp = int_part;
	int_part = ft_strjoin(int_part, fl_part);
	safe_free(tmp);
	((env->flags & F_HASH) && (env->prec_ex != 0) &&
	(env->prec_val == 0) && (int_part[ft_strlen(int_part) - 1] != '.')) ?
	append(&int_part, ".", 1, 'e') : 1;
	len = ft_strlen(int_part);
	minwidth = (env->width < __INT32_MAX__ && (int)env->width - len > 0)
		? env->width - len : 0;
	minwidth -= (env->flags & F_PLUS || env->flags & F_SPACE || s) ? 1 : 0;
	dsp_float_h(env, &minwidth, int_part, s);
	safe_free(fl_part);
}

void	wr_float(t_all *env)
{
	if (env->len_mod == 16)
		ft_printf_ld(env);
	else
		ft_printf_dbl(env);
}
