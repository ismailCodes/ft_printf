/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wr_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 14:16:52 by nathan            #+#    #+#             */
/*   Updated: 2020/02/02 11:24:25 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void		add_prefix(t_all *env, char **input)
{
	if (env->conv == 'o')
		*input = ft_strjoin("0", *input);
	if (env->conv == 'x')
		*input = ft_strjoin("0x", *input);
	if (env->conv == 'X')
		*input = ft_strjoin("0X", *input);
}

char		*get_base(char conv)
{
	if (conv == 'o')
		return (OCT);
	else if (conv == 'X')
		return (HEX_UPP);
	else if (conv == 'x')
		return (HEX_LOW);
	else
		exit_free_all();
	return (NULL);
}

int			hash(t_all *env)
{
	if (env->conv == 'o')
		env->printed += write(1, "0", 1);
	if (env->conv == 'x')
		env->printed += write(1, "0x", 2);
	if (env->conv == 'X')
		env->printed += write(1, "0X", 2);
	return (1);
}

static void	wr_x_h(t_all *env, int *mw, int *prec, unsigned long long input)
{
	if (!(env->flags & F_MINUS) && (env->prec_ex || !(env->flags & F_ZERO)))
		while ((*mw)-- > 0)
			env->printed += write(1, " ", 1);
	(env->flags & F_HASH && input) ? hash(env) : 0;
	if (env->prec_ex)
		while ((*prec)-- > 0)
			env->printed += write(1, "0", 1);
	else if (!(env->flags & F_MINUS) && (env->flags & F_ZERO))
		while ((*mw)-- > 0)
			env->printed += write(1, "0", 1);
}

void		wr_x(t_all *env)
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
	prec = ((int)env->prec_val > len) ? env->prec_val - len : 0;
	minwidth = ((int)env->width - prec - len > 0)
		? env->width - prec - len : 0;
	minwidth -= (env->flags & F_HASH && input) ? 2 : 0;
	wr_x_h(env, &minwidth, &prec, input);
	ft_putstr_count(env, input_str);
	while (minwidth-- > 0)
		env->printed += write(1, " ", 1);
	safe_free(input_str);
}
