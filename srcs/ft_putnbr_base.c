/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:47:40 by suahn             #+#    #+#             */
/*   Updated: 2020/07/01 15:15:14 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int		ft_check_base(char *base)
{
	long int i;
	long int j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(long long nbr, char *base)
{
	unsigned int	size;
	long long		nb;

	size = ft_strlen(base);
	nb = nbr;
	if (ft_check_base(base) == 1)
	{
		if (nb < 0)
		{
			nb *= -1;
			ft_putchar('-');
		}
		if (nb >= size)
			ft_putnbr_base(nb / size, base);
		ft_putchar(base[nb % size]);
	}
}
