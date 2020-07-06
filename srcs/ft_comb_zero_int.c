/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comb_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 16:13:12 by suahn             #+#    #+#             */
/*   Updated: 2020/07/06 17:50:07 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_comb_zero_yes_int(t_struct *count, t_struct *flag, t_struct *digit)
{
	int prec;

	prec = flag->prec;
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
	if (digit->n == 0 && prec == 0)
		;
	else if (digit->n == -2147483648)
		ft_putstr("2147483648");
	else
		ft_putnbr_base(digit->n, "0123456789");
}

void	ft_comb_zero_no2_int(t_struct *count, t_struct *flag, t_struct *digit)
{
	int prec;

	prec = flag->prec;
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
		if (digit->n == 0 && prec == 0)
			;
		else if (digit->n == -2147483648)
			ft_putstr("2147483648");
		else
			ft_putnbr_base(digit->n, "0123456789");
	}
	else if ((flag->width >= digit->len) &&
			(digit->len >= (flag->prec + flag->neg)))
	{
		count->len += flag->width;
		while (flag->width-- > digit->len)
			ft_putchar(' ');
		if (flag->neg == 1)
			ft_putchar('-');
		if (digit->n == 0 && prec == 0)
			;
		else if (digit->n == -2147483648)
			ft_putstr("2147483648");
		else
			ft_putnbr_base(digit->n, "0123456789");
	}
}

void	ft_comb_zero_no_int(t_struct *count, t_struct *flag, t_struct *digit)
{
	int prec;

	prec = flag->prec;
	if ((digit->len >= flag->width) && (digit->len >= (flag->prec + flag->neg)))
	{
		count->len += digit->len;
		if (flag->neg == 1)
			ft_putchar('-');
		if (digit->n == 0 && flag->prec == 0)
			;
		else if (digit->n == -2147483648)
			ft_putstr("2147483648");
		else
			ft_putnbr_base(digit->n, "0123456789");
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
		if (digit->n == 0 && prec == 0)
			;
		else if (digit->n == -2147483648)
			ft_putstr("2147483648");
		else
			ft_putnbr_base(digit->n, "0123456789");
	}
	else
		ft_comb_zero_no2_int(count, flag, digit);
}
