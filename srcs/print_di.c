/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:08:08 by suahn             #+#    #+#             */
/*   Updated: 2020/07/07 09:17:29 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_di(va_list *list, t_struct *count, t_struct *flag)
{
	t_struct integer;

	integer.prec = flag->prec;
	integer.nbr = va_arg(*list, int);
	flag->neg = (integer.nbr >= 0) ? 0 : 1;
	if (integer.nbr != -2147483648)
		integer.nbr = (integer.nbr > 0) ? integer.nbr : -integer.nbr;
	integer.n = integer.nbr;
	integer.len = 0;
	ft_treat_integer(flag, &integer, 10);
	integer.len += flag->neg;
	if (flag->minus == 1)
		ft_comb_minus_yes_int(count, flag, &integer);
	if (flag->minus == 0)
		ft_comb_minus_no_int(count, flag, &integer);
}
