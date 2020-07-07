/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comb_minus_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 09:07:57 by suahn             #+#    #+#             */
/*   Updated: 2020/07/07 09:21:00 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_comb_minus_yes_int(t_struct *count, t_struct *flag, t_struct *digit)
{
	count->len += ft_mallen(flag, digit);
	if (flag->neg == 1)
	{
		ft_putchar('-');
		if ((flag->prec >= digit->len) && (flag->prec >= flag->width))
			count->len += flag->neg;
	}
	while (flag->prec-- > (digit->len - flag->neg))
		ft_putchar('0');
	if (digit->n == 0 && digit->prec == 0)
		;
	else if (digit->n == -2147483648)
		ft_putstr("2147483648");
	else
		ft_putnbr_base(digit->n, "0123456789");
	if ((digit->len - flag->neg) >= digit->prec)
	{
		while (flag->width-- > digit->len)
			ft_putchar(' ');
	}
	if (digit->prec > (digit->len - flag->neg))
	{
		while (flag->width-- > (digit->prec + flag->neg))
			ft_putchar(' ');
	}
}

void	ft_comb_minus_no_int(t_struct *count, t_struct *flag, t_struct *digit)
{
	if (flag->zero == 0)
		ft_comb_zero_no_int(count, flag, digit);
	else if (flag->zero == 1)
		ft_comb_zero_yes_int(count, flag, digit);
}
