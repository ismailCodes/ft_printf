/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 15:50:42 by ismail            #+#    #+#             */
/*   Updated: 2020/02/02 11:24:25 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	reinit_flags(t_all *env)
{
	env->flags = 0;
	env->len_mod = 0;
	env->width = 0;
	env->prec_ex = 0;
	env->prec_val = 0;
	if (env->int_help != NULL)
	{
		safe_free(env->int_help);
		env->int_help = NULL;
	}
	env->is_neg = 0;
	env->o_backup = 0;
	env->conv = '0';
}

t_all	*init_flags(char *copy)
{
	t_all	*env;

	env = (t_all*)safe_malloc(sizeof(t_all));
	if (!FT_CHECK(env))
		exit_free_all();
	env->cp = copy;
	env->pos = 0;
	env->printed = 0;
	env->flags = 0;
	env->len_mod = 0;
	env->width = 0;
	env->prec_ex = 0;
	env->prec_val = 0;
	env->int_help = NULL;
	env->is_neg = 0;
	env->o_backup = 0;
	env->conv = '0';
	return (env);
}
