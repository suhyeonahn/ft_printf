/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:08:18 by suahn             #+#    #+#             */
/*   Updated: 2020/07/01 15:19:15 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_percent(t_struct *count, t_struct *flag)
{
	if (flag->width > 1)
		count->len += flag->width;
	else
		count->len += 1;
	if (flag->minus == 1)
	{
		ft_putchar('%');
		while (1 < flag->width--)
			ft_putchar(' ');
	}
	else
	{
		if (flag->zero == 1)
		{
			while (1 < flag->width--)
				ft_putchar('0');
			ft_putchar('%');
		}
		else
		{
			while (1 < flag->width--)
				ft_putchar(' ');
			ft_putchar('%');
		}
	}
}
