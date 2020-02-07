/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 21:10:38 by ielmoudn          #+#    #+#             */
/*   Updated: 2020/02/07 17:25:33 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(intmax_t n)
{
	char		*fraiche;
	intmax_t	nb;

	nb = n;
	if (!(fraiche = (char *)safe_malloc(sizeof(char))))
		exit_free_all();
	if (nb == -2147483648)
		return (ft_strcpy(fraiche, "-2147483648"));
	if (nb < 0)
	{
		fraiche[0] = '-';
		fraiche[1] = '\0';
		fraiche = ft_strjoin(fraiche, ft_itoa(-nb));
	}
	if (nb >= 10)
		fraiche = ft_strjoin(ft_itoa(nb / 10), ft_itoa(nb % 10));
	if (nb >= 0 && nb < 10)
	{
		fraiche[0] = nb + 48;
		fraiche[1] = '\0';
	}
	return (fraiche);
}

static size_t	ft_digits(intmax_t n)
{
	size_t i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa_u(intmax_t n)
{
	char		*fraiche;
	size_t		i;
	uintmax_t	nb;

	if (n == LLONG_MIN)
		return (ft_strdup("9223372036854775808"));
	i = ft_digits(n);
	if (!(fraiche = (char *)safe_malloc(sizeof(char) * (i + 1))))
		exit_free_all();
	fraiche[i--] = '\0';
	if (n < 0)
	{
		nb = n * -1;
		fraiche[0] = '+';
	}
	else
		nb = n;
	while (nb / 10)
	{
		fraiche[i--] = nb % 10 + 48;
		nb /= 10;
	}
	fraiche[i--] = nb % 10 + 48;
	return (fraiche);
}
