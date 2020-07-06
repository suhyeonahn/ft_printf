/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 12:42:24 by suahn             #+#    #+#             */
/*   Updated: 2020/07/06 12:42:27 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_is_in_specifier(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
			|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

void	ft_output(va_list *list, t_struct *count, t_struct *flag)
{
	if (count->src[count->i] == 'c')
		print_c(list, count, flag);
	if (count->src[count->i] == 's')
		print_s(list, count, flag);
	if (count->src[count->i] == 'd' || count->src[count->i] == 'i')
		print_di(list, count, flag);
	if (count->src[count->i] == 'u')
		print_u(list, count, flag);
	if (count->src[count->i] == 'x')
		print_x(list, count, flag);
	if (count->src[count->i] == 'X')
		print_xx(list, count, flag);
	if (count->src[count->i] == 'p')
		print_pointer(list, count, flag);
	if (count->src[count->i] == '%')
		print_percent(count, flag);
}

void	ft_printf2(t_struct *count)
{
	count->len++;
	ft_putchar(count->src[count->i]);
}

int		ft_printf(const char *input, ...)
{
	t_struct	count;
	t_struct	flag;
	va_list		list;

	va_start(list, input);
	ft_init_count(&count, input);
	ft_init_flag(&flag);
	while (count.src[count.i] != '\0')
	{
		if (count.src[count.i] == '%' && count.src[count.i + 1])
		{
			count.i++;
			ft_treat_flag(&list, &count, &flag);
			if (ft_is_in_specifier(count.src[count.i]))
				ft_output(&list, &count, &flag);
			else
				return (0);
		}
		else
			ft_printf2(&count);
		count.i++;
		ft_init_flag(&flag);
	}
	va_end(list);
	return (count.len);
}
