/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:59:35 by suahn             #+#    #+#             */
/*   Updated: 2020/01/09 14:03:05 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*sub;

	if (s == NULL)
		return (NULL);
	if ((sub = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	i = 0;
	if (!(start > ft_strlen(s)))
	{
		while (i < len && s[start + i])
		{
			sub[i] = s[start + i];
			i++;
		}
	}
	sub[i] = '\0';
	return (sub);
}
