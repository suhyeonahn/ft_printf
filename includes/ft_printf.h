/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:48:46 by suahn             #+#    #+#             */
/*   Updated: 2020/07/06 16:16:42 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <string.h>

typedef struct			s_struct
{
	int					prec;
	int					width;
	int					zero;
	int					minus;
	int					i;
	int					len;
	int					len2;
	int					neg;
	int					mod;
	int					mallen;
	int					nbr;
	int					n;
	unsigned int		unbr;
	unsigned int		un;
	unsigned long		lnbr;
	unsigned long		ln;
	char				*str;
	char				*str2;
	const char			*src;
}						t_struct;

int						ft_check_base(char *base);
int						ft_mallen(t_struct *flag, t_struct *digit);
int						ft_printf(const char *input, ...);
int						ft_is_in_specifier(int c);
char					*ft_strcpy(char *dest, char *src);
void					ft_init_count(t_struct *count, const char *input);
void					ft_init_flag(t_struct *flag);
void					ft_putnbr_base(long long nbr, char *base);
void					ft_putchar(char c);
void					ft_putstr(char *str);
void					ft_comb_s(t_struct *flag, t_struct *string);
void					ft_comb_minus_p(t_struct *flag, t_struct *pointer);
void					ft_comb_minus_yes_int(t_struct *count, t_struct *flag,
		t_struct *digit);
void					ft_comb_minus_yes_u(t_struct *count, t_struct *flag,
		t_struct *digit);
void					ft_comb_minus_yes_x(t_struct *count, t_struct *flag,
		t_struct *digit);
void					ft_comb_minus_yes_xx(t_struct *count, t_struct *flag,
		t_struct *digit);
void					ft_comb_minus_no_int(t_struct *count, t_struct *flag,
		t_struct *digit);
void					ft_comb_minus_no_u(t_struct *count, t_struct *flag,
		t_struct *digit);
void					ft_comb_minus_no_x(t_struct *count, t_struct *flag,
		t_struct *digit);
void					ft_comb_minus_no_xx(t_struct *count, t_struct *flag,
		t_struct *digit);
void					ft_comb_zero_yes_int(t_struct *count, t_struct *flag,
		t_struct *digit);
void					ft_comb_zero_yes_u(t_struct *count, t_struct *flag,
		t_struct *digit);
void					ft_comb_zero_yes_x(t_struct *count, t_struct *flag,
		t_struct *digit);
void					ft_comb_zero_yes_xx(t_struct *count, t_struct *flag,
		t_struct *digit);

void					ft_comb_zero_yes2(t_struct *flag, t_struct *digit);
void					ft_comb_zero_no_int(t_struct *count, t_struct *flag,
		t_struct *digit);
void					ft_comb_zero_no_u(t_struct *count, t_struct *flag,
		t_struct *digit);
void					ft_comb_zero_no_x(t_struct *count, t_struct *flag,
		t_struct *digit);
void					ft_comb_zero_no_xx(t_struct *count, t_struct *flag,
		t_struct *digit);
void					ft_comb_zero_no2_int(t_struct *count, t_struct *flag,
		t_struct *digit);
void					ft_comb_zero_no2_u(t_struct *count, t_struct *flag,
		t_struct *digit);
void					ft_comb_zero_no2_x(t_struct *count, t_struct *flag,
		t_struct *digit);
void					ft_comb_zero_no2_xx(t_struct *count, t_struct *flag,
		t_struct *digit);
void					ft_printf2(t_struct *count);
void					print_c(va_list *list, t_struct *count, t_struct *flag);
void					print_s(va_list *list, t_struct *count, t_struct *flag);
void					print_di(va_list *list, t_struct *count,
		t_struct *flag);
void					print_u(va_list *list, t_struct *count, t_struct *flag);
void					print_x(va_list *list, t_struct *count, t_struct *flag);
void					print_xx(va_list *list, t_struct *count,
		t_struct *flag);
void					print_pointer(va_list *list, t_struct *count,
		t_struct *flag);
void					print_percent(t_struct *count, t_struct *flag);
void					ft_treat_digit(t_struct *flag, t_struct *digit, int i);
void					ft_treat_integer(t_struct *flag, t_struct *integer,
		int i);
void					ft_output(va_list *list, t_struct *count,
		t_struct *flag);
void					ft_treat_flag(va_list *list, t_struct *count,
		t_struct *flag);
void					ft_treat_flag2(va_list *list, t_struct *count,
		t_struct *flag);

#endif
