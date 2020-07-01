/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:08:56 by suahn             #+#    #+#             */
/*   Updated: 2019/11/29 11:20:48 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (c && s[i])
	{
		if (s[i] == c)
			return ((char*)s + i);
		i++;
	}
	while (c == '\0')
	{
		if (s[i] == '\0')
			return ((char*)s + i);
		i++;
	}
	return (NULL);
}
