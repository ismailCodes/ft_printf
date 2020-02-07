/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 23:11:27 by ismail            #+#    #+#             */
/*   Updated: 2020/02/07 18:18:14 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include "../src/libft/libft.h"

# define FT_CHECK(x) x
# define CUR_CHAR(x) env->cp[env->pos + x]
# define CONVERSION "cspdiouXxf%"
# define OCT "01234567"
# define HEX_LOW "0123456789abcdef"
# define HEX_UPP "0123456789ABCDEF"
# define DEC "0123456789"

typedef struct		s_double
{
	unsigned long	f:52;
	unsigned		e:11;
	unsigned char	s:1;
}					t_double;

typedef union		u_double_u
{
	double			val;
	t_double		dbl;
}					t_double_u;

typedef struct		s_ldouble
{
	size_t					f:63;
	unsigned int			q:1;
	unsigned int			e:15;
	unsigned int			s:1;
}					t_ldouble;

typedef union		u_ldouble_u
{
	long double		val;
	t_ldouble		ldbl;
}					t_ldouble_u;

typedef struct		s_all
{
	va_list			arglist;
	char			*cp;
	size_t			pos;
	size_t			printed;
	int				flags;
	short			len_mod;
	size_t			width;
	int				prec_ex;
	int				prec_val;
	char			*int_help;
	int				is_neg;
	int				o_backup;
	char			conv;
}					t_all;

typedef enum		e_flags
{
	F_HASH = 1, F_ZERO = 2, F_MINUS = 4, F_PLUS = 8, F_SPACE = 16
}					t_flags;

typedef enum		e_lenmod
{
	LM_H = 1, LM_HH = 2, LM_L = 4, LM_LL = 8, LM_LUP = 16
}					t_lenmod;

int					ft_printf(const char *format, ...);
t_all				*init_flags(char *cp);
void				process(t_all *env);
int					is_flag(t_all *env);
int					is_len_mod(t_all *env);
void				format_parser(t_all *env);
int					is_precision(t_all *env);
void				p_flag(t_all *env);
int					dp_parser(t_all *env);
void				spec_parser(t_all *env);
void				p_len_mod(t_all *env);
void				p_precision(t_all *env);
char				*get_min_width(t_all *env, int len);
void				p_min_width(t_all *env);
void				p_flag(t_all *env);
void				printini(t_all *env);
void				p_conversion(t_all *env);
void				wr_char(t_all *env);
void				print_sp(t_all *env, int spaces, char to_be_appended);
void				wr_str(t_all *env);
char				*putnbr_base(unsigned long long num, char *base);
int					putnbr_base_count(unsigned long long num, int base);
void				wr_addr(t_all *env);
void				reinit_flags(t_all *env);
void				ft_putchar_count(t_all *env, char c);
void				wr_int(t_all *env);
void				ft_putstr_count(t_all *env, char const *s);
void				append(char **dest, char *add, int num, char beg_end);
void				wr_x(t_all *env);
void				wr_o(t_all *env);
void				app_prec(t_all *env, char **int_str, char beg_end);
void				app_flag(t_all *env, char **int_str, char begend);
void				app_width(t_all *env, char **int_str);
void				wr_u(t_all *env);
void				wr_float(t_all *env);
int					ver_carry(size_t *carry, int l);
void				bit_shift(size_t **t, int shift, int l);
void				ft_printf_dbl(t_all *env);
void				bit_shift_left(size_t **table, int shift, int dim_st);
void				bit_shift_right(size_t **table, int shift, int dim_st);
void				ft_dsp_float(t_all *env, size_t *t_float, int dim);
size_t				*new_table(int len);
int					verify_carry(size_t *carry, int len);
void				dsp_float(t_all *env, unsigned char s,
					size_t *t_fl, int dim);
void				put_nan(t_all *env, unsigned char s, unsigned long frac);
void				fl_app_sign(unsigned char sign, char **int_str);
void				fl_app_flag(t_all *env, unsigned char s,
					char **int_str, char begend);
void				fl_app_width(t_all *env, char **nan_str);
intmax_t			wr_int_helper(t_all *env);
void				app_sign(t_all *env, char **int_str);
void				app_prec(t_all *env, char **int_str, char beg_end);
void				app_flag(t_all *env, char **int_str, char begend);
void				ft_printf_ld(t_all *env);
unsigned long long	wr_u_helper(t_all *env);
void				percent_char(t_all *env);
void				p_conversion(t_all *env);
int					hash(t_all *env);
char				*get_base(char conv);
void				add_prefix(t_all *env, char **input);
void				get_part_int(size_t *fl_table, size_t **part_i,
					int dim, int len);
void				ft_add_int(size_t **a, size_t *b, unsigned int l);
char				*int_to_str(size_t *part_i, int l);
int					ft_float(t_all *env, size_t *tbl_fl,
					char **part_fl, int dim);
void				ft_copy(size_t *src, size_t **dest, int len);
void				ft_add(size_t **a, size_t **b, int l);
#endif
