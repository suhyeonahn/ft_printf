/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:07:45 by suahn             #+#    #+#             */
/*   Updated: 2020/07/01 15:18:18 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_c(va_list *list, t_struct *count, t_struct *flag)
{
	char c;

	c = va_arg(*list, int);
	flag->width -= 1;
	if (flag->width > 0)
		count->len += flag->width + 1;
	else
		count->len += 1;
	if (flag->minus == 1)
	{
		ft_putchar(c);
		while (0 < flag->width--)
			ft_putchar(' ');
	}
	else
	{
		while (0 < flag->width--)
			ft_putchar(' ');
		ft_putchar(c);
	}
}
