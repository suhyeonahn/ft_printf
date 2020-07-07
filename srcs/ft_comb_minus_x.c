/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comb_minus_x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 09:11:01 by suahn             #+#    #+#             */
/*   Updated: 2020/07/07 09:22:04 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_comb_minus_yes_x(t_struct *count, t_struct *flag, t_struct *digit)
{
	count->len += ft_mallen(flag, digit);
	while (flag->prec-- > digit->len)
		ft_putchar('0');
	if (digit->un == 0 && digit->prec == 0)
		;
	else
		ft_putnbr_base(digit->un, "0123456789abcdef");
	if (digit->len >= digit->prec)
	{
		while (flag->width-- > digit->len)
			ft_putchar(' ');
	}
	if (digit->prec > digit->len)
	{
		while (flag->width-- > digit->prec)
			ft_putchar(' ');
	}
}

void	ft_comb_minus_no_x(t_struct *count, t_struct *flag, t_struct *digit)
{
	if (flag->zero == 0)
		ft_comb_zero_no_x(count, flag, digit);
	else if (flag->zero == 1)
		ft_comb_zero_yes_x(count, flag, digit);
}
