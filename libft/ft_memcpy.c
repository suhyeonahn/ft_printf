/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:16:44 by suahn             #+#    #+#             */
/*   Updated: 2020/01/06 09:57:51 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *tmp;

	tmp = dst;
	if (!dst && !src)
		return (dst);
	while (n-- > 0)
		(*(unsigned char *)dst++) = (*(unsigned char *)src++);
	dst = tmp;
	return (dst);
}
