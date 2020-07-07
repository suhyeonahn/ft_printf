/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comb_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 09:11:36 by suahn             #+#    #+#             */
/*   Updated: 2020/07/07 09:11:41 by suahn            ###   ########.fr       */
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
