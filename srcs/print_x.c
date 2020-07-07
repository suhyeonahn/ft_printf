/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:09:11 by suahn             #+#    #+#             */
/*   Updated: 2020/07/07 09:18:31 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_x(va_list *list, t_struct *count, t_struct *flag)
{
	t_struct hexa;

	hexa.prec = flag->prec;
	hexa.unbr = va_arg(*list, unsigned int);
	hexa.un = hexa.unbr;
	hexa.len = 0;
	ft_treat_digit(flag, &hexa, 16);
	if (flag->minus == 1)
		ft_comb_minus_yes_x(count, flag, &hexa);
	if (flag->minus == 0)
		ft_comb_minus_no_x(count, flag, &hexa);
}
