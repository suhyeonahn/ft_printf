/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 09:42:31 by suahn             #+#    #+#             */
/*   Updated: 2020/01/02 11:35:23 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
