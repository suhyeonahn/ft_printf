/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:17:25 by suahn             #+#    #+#             */
/*   Updated: 2020/01/06 09:58:08 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tmp;

	tmp = dst;
	if (!dst && !src)
		return (dst);
	if (src < dst)
		while (len--)
			*(unsigned char*)(dst + len) = *(unsigned char*)(src + len);
	else
		ft_memcpy(dst, src, len);
	dst = tmp;
	return (dst);
}
