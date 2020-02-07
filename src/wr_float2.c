/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wr_float2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 19:46:55 by nathan            #+#    #+#             */
/*   Updated: 2020/02/02 11:24:25 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_add_int(size_t **a, size_t *b, unsigned int l)
{
	size_t			k;
	unsigned int	i;

	i = 0;
	k = 0;
	while (i < l)
	{
		(*a)[l - 1 - i] = (*a)[l - 1 - i] + b[l - 1 - i] + k;
		k = (*a)[l - 1 - i] / 1000000000000000000;
		(*a)[l - 1 - i++] -= 1000000000000000000 * k;
	}
}

void	get_part_int(size_t *fl_table, size_t **part_i, int dim, int len)
{
	size_t			*add;
	unsigned int	i;
	size_t			*int_table;

	add = new_table(len);
	add[len - 1] = 1;
	int_table = new_table(dim);
	ft_copy(fl_table, &int_table, dim);
	i = 0;
	while (i < (unsigned int)len * 64)
	{
		if ((int_table)[dim - 1] % 2 == 1)
			ft_add_int(part_i, add, len);
		ft_add_int(&add, add, len);
		bit_shift(&int_table, -1, dim);
		i++;
	}
	safe_free(add);
	safe_free(int_table);
}

int		ft_count(size_t n)
{
	int nbr;

	nbr = 0;
	while (n != 0)
	{
		n = n / 10;
		nbr++;
	}
	return (nbr);
}

char	*ft_itoa1(size_t n, int i)
{
	char			*str;
	int				l;

	if (i == 0)
		l = ft_count(n);
	else
		l = 18;
	if (!(str = (char *)safe_malloc(sizeof(char) * (l + 1))))
		exit_free_all();
	str[l--] = '\0';
	str[l--] = '0' + n % 10;
	n = n / 10;
	while (l != -1)
	{
		str[l--] = '0' + n % 10;
		n = n / 10;
	}
	return (str);
}

char	*int_to_str(size_t *part_i, int l)
{
	char	*ret;
	char	*a1;
	char	*a2;
	int		i;

	i = 0;
	while (part_i[i] == 0 && i < l)
		i++;
	if (i == l)
		return (ft_strdup("0"));
	ret = ft_itoa1(part_i[i++], 0);
	while (i < l)
	{
		a1 = ft_itoa1(part_i[i++], 1);
		a2 = ret;
		ret = ft_strjoin(ret, a1);
		safe_free(a1);
		safe_free(a2);
	}
	return (ret);
}
