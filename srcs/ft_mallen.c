/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mallen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:05:52 by suahn             #+#    #+#             */
/*   Updated: 2020/07/01 14:24:10 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_mallen(t_struct *flag, t_struct *digit)
{
	if (digit->len <= flag->width && flag->width >= flag->prec)
		digit->mallen = flag->width;
	if (flag->width <= digit->len && digit->len >= flag->prec)
		digit->mallen = digit->len;
	if (digit->len <= flag->prec && flag->prec >= flag->width)
		digit->mallen = flag->prec;
	return (digit->mallen);
}
