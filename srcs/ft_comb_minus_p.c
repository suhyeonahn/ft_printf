/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comb_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:17:08 by suahn             #+#    #+#             */
/*   Updated: 2020/07/06 17:45:57 by suahn            ###   ########.fr       */
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
