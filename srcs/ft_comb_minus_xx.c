/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comb_minus_xx.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 09:11:14 by suahn             #+#    #+#             */
/*   Updated: 2020/07/07 09:22:43 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_comb_minus_yes_xx(t_struct *count, t_struct *flag, t_struct *digit)
{
	count->len += ft_mallen(flag, digit);
	while (flag->prec-- > digit->len)
		ft_putchar('0');
	if (digit->un == 0 && digit->prec == 0)
		;
	else
		ft_putnbr_base(digit->un, "0123456789ABCDEF");
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

void	ft_comb_minus_no_xx(t_struct *count, t_struct *flag, t_struct *digit)
{
	if (flag->zero == 0)
		ft_comb_zero_no_xx(count, flag, digit);
	else if (flag->zero == 1)
		ft_comb_zero_yes_xx(count, flag, digit);
}
