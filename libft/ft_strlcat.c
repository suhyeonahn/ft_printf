/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:25:20 by suahn             #+#    #+#             */
/*   Updated: 2020/01/06 10:25:59 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t dstlen;
	size_t srclen;
	size_t i;
	size_t dstlength;

	dstlen = ft_strlen((const char*)dst);
	srclen = ft_strlen(src);
	dstlength = dstlen;
	if (dstlen >= dstsize)
		return (srclen + dstsize);
	i = 0;
	while (src[i] && (i + 1 < (dstsize - dstlength)))
		dst[dstlen++] = src[i++];
	dst[dstlen] = '\0';
	return (srclen + dstlength);
}
