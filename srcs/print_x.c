/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:09:11 by suahn             #+#    #+#             */
/*   Updated: 2020/07/01 15:27:36 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_x(va_list *list, t_struct *count, t_struct *flag)
{
	t_struct hexa;

	hexa.unbr = va_arg(*list, unsigned int);
	hexa.un = hexa.unbr;
	hexa.len = 0;
	ft_treat_digit(flag, &hexa, 16);
	while (hexa.un > 0)
	{
		hexa.mod = hexa.un % 16;
		if (hexa.mod < 10)
			hexa.str[hexa.len2 - 1] = hexa.mod + 48;
		else
			hexa.str[hexa.len2 - 1] = (hexa.mod - 10) + 97;
		hexa.un = hexa.un / 16;
		hexa.len2--;
	}
	if (flag->minus == 1)
		ft_comb_minus_yes(count, flag, &hexa);
	if (flag->minus == 0)
		ft_comb_minus_no(count, flag, &hexa);
}
