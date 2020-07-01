/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 12:05:10 by suahn             #+#    #+#             */
/*   Updated: 2020/01/28 17:16:08 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char	*copy;
	int		srclen;
	int		i;

	srclen = 0;
	while (src[srclen])
	{
		srclen++;
	}
	copy = NULL;
	if (!(copy = (char *)malloc(srclen + 1)))
		return (NULL);
	i = 0;
	while (i < srclen)
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
