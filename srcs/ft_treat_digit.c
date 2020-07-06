/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:07:35 by suahn             #+#    #+#             */
/*   Updated: 2020/07/06 16:59:43 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_treat_integer(t_struct *flag, t_struct *integer, int i)
{
	if (integer->n == 0)
	{
		if (flag->prec == 0)
			integer->len = 0;
		else
			integer->len = 1;
	}
	while (integer->nbr > 0)
	{
		integer->nbr /= i;
		integer->len++;
	}
	if (integer->nbr == -2147483648)
		integer->len = 10;
}

void	ft_treat_digit(t_struct *flag, t_struct *digit, int i)
{
	if (digit->un == 0)
	{
		if (flag->prec == 0)
			digit->len = 0;
		else
			digit->len = 1;
	}
	while (digit->unbr > 0)
	{
		digit->unbr /= i;
		digit->len++;
	}
}
