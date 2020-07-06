/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:08:28 by suahn             #+#    #+#             */
/*   Updated: 2020/07/06 17:46:49 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_pointer(va_list *list, t_struct *count, t_struct *flag)
{
	void		*adress;
	t_struct	pointer;

	adress = va_arg(*list, void*);
	pointer.ln = (unsigned long)adress;
	pointer.lnbr = pointer.ln;
	pointer.len = 2;
	if (pointer.lnbr == 0 && flag->prec < 0)
		pointer.len++;
	while (pointer.lnbr > 0)
	{
		pointer.lnbr /= 16;
		pointer.len++;
	}
	if (pointer.len >= flag->width)
		count->len += pointer.len;
	else
		count->len += flag->width;
	ft_comb_minus_p(flag, &pointer);
}
