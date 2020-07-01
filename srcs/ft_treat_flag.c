/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 15:11:09 by suahn             #+#    #+#             */
/*   Updated: 2020/07/01 16:01:57 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_treat_flag2(va_list *list, t_struct *count, t_struct *flag)
{
	if (count->src[count->i] == '.')
	{
		flag->prec = 0;
		while (count->src[count->i + 1] >= '0' &&
				count->src[count->i + 1] <= '9')
		{
			flag->prec = flag->prec * 10 + count->src[count->i + 1] - '0';
			count->i++;
		}
	}
	if (count->src[count->i] == '.' && count->src[count->i + 1] == '*')
		flag->prec = va_arg(*list, int);
	if (count->src[count->i] == '*' && count->src[count->i - 1] != '.')
	{
		flag->width = va_arg(*list, int);
		if (flag->width < 0)
		{
			flag->width *= -1;
			flag->minus = 1;
		}
	}
}

void	ft_treat_flag(va_list *list, t_struct *count, t_struct *flag)
{
	while (count->src[count->i])
	{
		if (count->src[count->i] == '-')
		{
			flag->minus = 1;
			flag->zero = 0;
		}
		if (count->src[count->i] == '0' && flag->minus == 0)
			flag->zero = 1;
		if (count->src[count->i] >= '1' && count->src[count->i] <= '9' &&
				count->src[count->i - 1] != '.')
		{
			flag->width = flag->width * 10 + count->src[count->i] - '0';
			while (count->src[count->i + 1] >= '0' &&
					count->src[count->i + 1] <= '9')
			{
				flag->width = flag->width * 10 + count->src[count->i + 1] - '0';
				count->i++;
			}
		}
		ft_treat_flag2(list, count, flag);
		if (ft_is_in_specifier(count->src[count->i]))
			break ;
		count->i++;
	}
}
