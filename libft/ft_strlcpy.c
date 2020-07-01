/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 11:50:34 by suahn             #+#    #+#             */
/*   Updated: 2020/01/06 10:25:49 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!dst)
		return (0);
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i])
	{
		if (dstsize && (i < (dstsize - 1)))
		{
			dst[i] = src[i];
			j++;
		}
		i++;
	}
	dst[j] = '\0';
	return (i);
}
