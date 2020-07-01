/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:05:30 by suahn             #+#    #+#             */
/*   Updated: 2020/07/01 14:23:33 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_init_count(t_struct *count, const char *input)
{
	count->len = 0;
	count->i = 0;
	count->src = input;
}

void	ft_init_flag(t_struct *flag)
{
	flag->prec = -1;
	flag->minus = 0;
	flag->width = 0;
	flag->zero = 0;
	flag->neg = 0;
}
