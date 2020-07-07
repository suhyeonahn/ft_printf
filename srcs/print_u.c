/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:09:01 by suahn             #+#    #+#             */
/*   Updated: 2020/07/07 09:18:04 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_u(va_list *list, t_struct *count, t_struct *flag)
{
	t_struct uint;

	uint.prec = flag->prec;
	uint.unbr = va_arg(*list, unsigned int);
	uint.un = uint.unbr;
	uint.len = 0;
	ft_treat_digit(flag, &uint, 10);
	if (flag->minus == 1)
		ft_comb_minus_yes_u(count, flag, &uint);
	if (flag->minus == 0)
		ft_comb_minus_no_u(count, flag, &uint);
}
