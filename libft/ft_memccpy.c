/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:30:56 by suahn             #+#    #+#             */
/*   Updated: 2019/11/29 13:10:48 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n-- > 0)
	{
		(*(unsigned char*)dst++) = (*(unsigned char*)src++);
		if (*(unsigned char*)src == (unsigned char)c)
		{
			*(unsigned char*)dst = *(unsigned char*)src;
			return (dst + 1);
		}
	}
	return (NULL);
}
