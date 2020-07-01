/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:08:08 by suahn             #+#    #+#             */
/*   Updated: 2020/07/01 15:18:53 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_di(va_list *list, t_struct *count, t_struct *flag)
{
	t_struct integer;

	integer.nbr = va_arg(*list, int);
	flag->neg = (integer.nbr >= 0) ? 0 : 1;
	if (integer.nbr != -2147483648)
		integer.nbr = (integer.nbr > 0) ? integer.nbr : -integer.nbr;
	integer.n = integer.nbr;
	integer.len = 0;
	ft_treat_integer(flag, &integer, 10);
	if (integer.nbr == -2147483648)
		integer.str = "2147483648";
	while (integer.n > 0)
	{
		integer.str[integer.len2 - 1] = integer.n % 10 + '0';
		integer.n /= 10;
		integer.len2--;
	}
	integer.len += flag->neg;
	if (flag->minus == 1)
		ft_comb_minus_yes(count, flag, &integer);
	if (flag->minus == 0)
		ft_comb_minus_no(count, flag, &integer);
}
