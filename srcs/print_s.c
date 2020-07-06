/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:08:38 by suahn             #+#    #+#             */
/*   Updated: 2020/07/06 12:55:44 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_comb_s(t_struct *flag, t_struct *string)
{
	if (flag->minus == 1)
	{
		write(1, string->str, string->len);
		while (0 < flag->width--)
			write(1, " ", 1);
	}
	else
	{
		while (0 < flag->width--)
			write(1, " ", 1);
		write(1, string->str, string->len);
	}
}

void	print_s(va_list *list, t_struct *count, t_struct *flag)
{
	t_struct string;

	string.str = va_arg(*list, char *);
	if (!string.str)
		string.str = "(null)\0";
	if ((-1 < flag->prec) && ((size_t)flag->prec < ft_strlen(string.str)))
	{
		flag->width = flag->width - flag->prec;
		string.len = flag->prec;
	}
	else
	{
		flag->width = flag->width - ft_strlen(string.str);
		string.len = ft_strlen(string.str);
	}
	if (flag->width > 0)
		count->len += string.len + flag->width;
	else
		count->len += string.len;
	ft_comb_s(flag, &string);
}
