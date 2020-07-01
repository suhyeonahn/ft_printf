/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:22:08 by suahn             #+#    #+#             */
/*   Updated: 2020/01/06 10:13:37 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	size_t	b;

	b = 0;
	if (s && f)
	{
		new = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (new == NULL)
			return (NULL);
		while (b < ft_strlen(s))
		{
			new[b] = f(b, s[b]);
			b++;
		}
		new[b] = '\0';
		return (new);
	}
	return (NULL);
}
