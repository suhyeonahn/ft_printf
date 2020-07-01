/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comb_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:17:08 by suahn             #+#    #+#             */
/*   Updated: 2020/07/01 15:54:43 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_comb_minus_p(t_struct *flag, t_struct *pointer)
{
	if (flag->minus == 1)
	{
		ft_putstr("0x");
		if (!(pointer->ln == 0 && flag->prec >= 0))
			ft_putnbr_base(pointer->ln, "0123456789abcdef");
		while (flag->width-- > pointer->len)
			ft_putchar(' ');
	}
	else if (flag->minus == 0)
	{
		while (flag->width-- > pointer->len)
			ft_putchar(' ');
		ft_putstr("0x");
		if (!(pointer->ln == 0 && flag->prec >= 0))
			ft_putnbr_base(pointer->ln, "0123456789abcdef");
	}
}

void	ft_comb_minus_yes(t_struct *count, t_struct *flag, t_struct *digit)
{
	int prec;

	prec = flag->prec;
	count->len += ft_mallen(flag, digit);
	if (flag->neg == 1)
	{
		ft_putchar('-');
		if ((flag->prec >= digit->len) && (flag->prec >= flag->width))
			count->len += flag->neg;
	}
	while (flag->prec-- > (digit->len - flag->neg))
		ft_putchar('0');
	ft_putstr(digit->str);
	if ((digit->len - flag->neg) >= prec)
	{
		while (flag->width-- > digit->len)
			ft_putchar(' ');
	}
	if (prec > (digit->len - flag->neg))
	{
		while (flag->width-- > (prec + flag->neg))
			ft_putchar(' ');
	}
}

void	ft_comb_minus_no(t_struct *count, t_struct *flag, t_struct *digit)
{
	if (flag->zero == 0)
		ft_comb_zero_no(count, flag, digit);
	else if (flag->zero == 1)
		ft_comb_zero_yes(count, flag, digit);
}
