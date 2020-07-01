/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:29:50 by suahn             #+#    #+#             */
/*   Updated: 2020/01/03 10:56:40 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	size_t			len_needle;

	if (*needle == '\0')
		return ((char*)haystack);
	i = 0;
	len_needle = ft_strlen(needle);
	while (*haystack != '\0')
	{
		if (i + len_needle > len)
			return (NULL);
		if (ft_strncmp(haystack, needle, len_needle) == 0)
			return ((char*)haystack);
		haystack++;
		i++;
	}
	return (NULL);
}
