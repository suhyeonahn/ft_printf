/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comb_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 16:13:12 by suahn             #+#    #+#             */
/*   Updated: 2020/07/01 16:13:16 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_comb_zero_yes2(t_struct *flag, t_struct *digit)
{
	if (flag->prec > (digit->len - flag->neg))
	{
		while (flag->width-- > (flag->prec + flag->neg))
			ft_putchar(' ');
	}
	else if ((digit->len - flag->neg) >= flag->prec)
	{
		while (flag->width-- > digit->len)
			ft_putchar(' ');
	}
	if (flag->neg == 1)
		ft_putchar('-');
	while (flag->prec-- > (digit->len - flag->neg))
		ft_putchar('0');
}

void	ft_comb_zero_yes(t_struct *count, t_struct *flag, t_struct *digit)
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
	ft_putstr(digit->str);
}

void	ft_comb_zero_no2(t_struct *count, t_struct *flag, t_struct *digit)
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
		ft_putstr(digit->str);
	}
	else if ((flag->width >= digit->len) &&
			(digit->len >= (flag->prec + flag->neg)))
	{
		count->len += flag->width;
		while (flag->width-- > digit->len)
			ft_putchar(' ');
		if (flag->neg == 1)
			ft_putchar('-');
		ft_putstr(digit->str);
	}
}

void	ft_comb_zero_no(t_struct *count, t_struct *flag, t_struct *digit)
{
	if ((digit->len >= flag->width) && (digit->len >= (flag->prec + flag->neg)))
	{
		count->len += digit->len;
		if (flag->neg == 1)
			ft_putchar('-');
		ft_putstr(digit->str);
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
		ft_putstr(digit->str);
	}
	else
		ft_comb_zero_no2(count, flag, digit);
}
