/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 16:11:33 by ismail            #+#    #+#             */
/*   Updated: 2020/02/02 11:18:36 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		putnbr_base_count(unsigned long long num, int base)
{
	int		counter;

	counter = 1;
	if (num == 0)
		return (1);
	while (num / base > 0)
	{
		num /= base;
		counter++;
	}
	return (counter);
}

char	*putnbr_base(unsigned long long num, char *base)
{
	int		base_len;
	int		output_len;
	char	*output;
	int		i;

	base_len = ft_strlen(base);
	output_len = putnbr_base_count(num, base_len) + 1;
	if (!(output = (char*)safe_malloc(output_len)))
		exit_free_all();
	i = output_len - 2;
	while (i >= 0)
	{
		output[i] = base[num % base_len];
		num = num / base_len;
		i--;
	}
	output[output_len - 1] = '\0';
	return (output);
}
