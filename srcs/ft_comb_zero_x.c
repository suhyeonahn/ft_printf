/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comb_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 16:13:12 by suahn             #+#    #+#             */
/*   Updated: 2020/07/06 18:02:57 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_comb_zero_yes_x(t_struct *count, t_struct *flag, t_struct *digit)
{
	int prec;

	prec = flag->prec;
	if (flag->width >= digit->len && flag->width >= flag->prec)
		count->len += flag->width;
	else if (flag->prec >= digit->len &&
			flag->prec >= flag->width)
		count->len += flag->prec;
	else
		count->len += digit->len;
	if (flag->prec > 0)
		ft_comb_zero_yes2(flag, digit);
	else if (flag->prec < 0)
	{
		while (flag->width-- > digit->len)
			ft_putchar('0');
	}
	else if (flag->prec == 0)
	{
		while (flag->width-- > digit->len)
			ft_putchar(' ');
	}
	if (digit->un == 0 && prec == 0)
		;
	else
		ft_putnbr_base(digit->un, "0123456789abcdef");
}

void	ft_comb_zero_no2_x(t_struct *count, t_struct *flag, t_struct *digit)
{
	int prec;

	prec = flag->prec;
	if ((flag->width >= flag->prec) &&
			(flag->prec >= digit->len))
	{
		count->len += flag->width;
		while (flag->width-- > flag->prec)
			ft_putchar(' ');
		while (flag->prec-- > digit->len)
			ft_putchar('0');
		if (digit->un == 0 && prec == 0)
			;
		else
			ft_putnbr_base(digit->un, "0123456789abcdef");
	}
	else if ((flag->width >= digit->len) &&
			(digit->len >= flag->prec))
	{
		count->len += flag->width;
		while (flag->width-- > digit->len)
			ft_putchar(' ');
		if (digit->un == 0 && prec == 0)
			;
		else
			ft_putnbr_base(digit->un, "0123456789abcdef");
	}
}

void	ft_comb_zero_no_x(t_struct *count, t_struct *flag, t_struct *digit)
{
	int precision;

	precision = flag->prec;
	if ((digit->len >= flag->width) && (digit->len >= flag->prec))
	{
		count->len += digit->len;
		if (digit->un == 0 && flag->prec == 0)
			;
		else
			ft_putnbr_base(digit->un, "0123456789abcdef");
	}
	else if ((flag->prec >= digit->len) &&
			(flag->prec >= flag->width))
	{
		count->len += flag->prec;
		while (flag->prec-- > digit->len)
			ft_putchar('0');
		if (digit->un == 0 && precision == 0)
			;
		else
			ft_putnbr_base(digit->un, "0123456789abcdef");
	}
	else
		ft_comb_zero_no2_x(count, flag, digit);
}
