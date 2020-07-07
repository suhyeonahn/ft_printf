/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comb_zero_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 09:11:52 by suahn             #+#    #+#             */
/*   Updated: 2020/07/07 09:31:32 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_comb_zero_print_int(t_struct *digit)
{
	if (digit->n == 0 && digit->prec == 0)
		;
	else if (digit->n == -2147483648)
		ft_putstr("2147483648");
	else
		ft_putnbr_base(digit->n, "0123456789");
}

void	ft_comb_zero_yes_int(t_struct *count, t_struct *flag, t_struct *digit)
{
	if (flag->width >= digit->len && flag->width >= (flag->prec + flag->neg))
		count->len += flag->width;
	else if ((flag->prec + flag->neg) >= digit->len &&
			(flag->prec + flag->neg) >= flag->width)
		count->len += flag->prec + flag->neg;
	else
		count->len += digit->len;
	if (flag->prec > 0)
		ft_comb_zero_yes2(flag, digit);
	else if (flag->prec < 0)
	{
		if (flag->neg == 1)
			ft_putchar('-');
		while (flag->width-- > digit->len)
			ft_putchar('0');
	}
	else if (flag->prec == 0)
	{
		while (flag->width-- > digit->len)
			ft_putchar(' ');
		if (flag->neg == 1)
			ft_putchar('-');
	}
	ft_comb_zero_print_int(digit);
}

void	ft_comb_zero_no2_int(t_struct *count, t_struct *flag, t_struct *digit)
{
	if ((flag->width >= (flag->prec + flag->neg)) &&
			((flag->prec + flag->neg) >= digit->len))
	{
		count->len += flag->width;
		while (flag->width-- > (flag->prec + flag->neg))
			ft_putchar(' ');
		if (flag->neg == 1)
			ft_putchar('-');
		while (flag->prec-- > (digit->len - flag->neg))
			ft_putchar('0');
		ft_comb_zero_print_int(digit);
	}
	else if ((flag->width >= digit->len) &&
			(digit->len >= (flag->prec + flag->neg)))
	{
		count->len += flag->width;
		while (flag->width-- > digit->len)
			ft_putchar(' ');
		if (flag->neg == 1)
			ft_putchar('-');
		ft_comb_zero_print_int(digit);
	}
}

void	ft_comb_zero_no_int(t_struct *count, t_struct *flag, t_struct *digit)
{
	if ((digit->len >= flag->width) && (digit->len >= (flag->prec + flag->neg)))
	{
		count->len += digit->len;
		if (flag->neg == 1)
			ft_putchar('-');
		ft_comb_zero_print_int(digit);
	}
	else if (((flag->prec + flag->neg) >= digit->len) &&
			((flag->prec + flag->neg) >= flag->width))
	{
		count->len += flag->prec;
		if (flag->neg == 1)
		{
			count->len += flag->neg;
			ft_putchar('-');
		}
		while (flag->prec-- > (digit->len - flag->neg))
			ft_putchar('0');
		ft_comb_zero_print_int(digit);
	}
	else
		ft_comb_zero_no2_int(count, flag, digit);
}
