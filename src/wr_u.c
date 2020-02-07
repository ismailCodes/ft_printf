/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wr_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 15:41:17 by ismail            #+#    #+#             */
/*   Updated: 2020/02/02 11:24:25 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

unsigned long long		wr_u_helper(t_all *env)
{
	unsigned long long	integer;

	integer = va_arg(env->arglist, unsigned long long);
	if (env->len_mod & LM_HH)
		integer = (unsigned char)integer;
	else if (env->len_mod & LM_H)
		integer = (unsigned short)integer;
	else if (env->len_mod & LM_L)
		integer = (unsigned long)integer;
	else if (env->len_mod & LM_LL)
		integer = (unsigned long long)integer;
	else
		integer = (unsigned int)integer;
	return (integer);
}

static size_t			ft_udigits(uintmax_t n)
{
	size_t i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

static char				*ft_utoa_u(uintmax_t n)
{
	char		*fraiche;
	size_t		i;
	uintmax_t	nb;

	i = ft_udigits(n);
	if (!(fraiche = (char *)safe_malloc(sizeof(char) * (i + 1))))
		exit_free_all();
	fraiche[i--] = '\0';
	nb = n;
	while (nb / 10)
	{
		fraiche[i--] = nb % 10 + 48;
		nb /= 10;
	}
	fraiche[i--] = nb % 10 + 48;
	return (fraiche);
}

void					wr_u(t_all *env)
{
	unsigned long long		input;
	char					*int_str;
	int						len;
	int						prec;
	int						minwidth;

	input = wr_u_helper(env);
	int_str = (env->prec_ex && !env->prec_val && !input) ?
		ft_strdup("") : ft_utoa_u(input);
	len = ft_strlen(int_str);
	prec = ((int)env->prec_val > len) ? env->prec_val - len : 0;
	minwidth = ((int)env->width - prec - len > 0) ? env->width - prec - len : 0;
	if (!(env->flags & F_MINUS) && (env->prec_ex || !(env->flags & F_ZERO)))
		while (minwidth-- > 0)
			env->printed += write(1, " ", 1);
	if (env->prec_ex)
		while (prec-- > 0)
			env->printed += write(1, "0", 1);
	else if (!(env->flags & F_MINUS) && (env->flags & F_ZERO))
		while (minwidth-- > 0)
			env->printed += write(1, "0", 1);
	ft_putstr_count(env, int_str);
	while (minwidth-- > 0)
		env->printed += write(1, " ", 1);
	safe_free(int_str);
}
