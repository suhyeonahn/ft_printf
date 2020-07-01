/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:34:08 by suahn             #+#    #+#             */
/*   Updated: 2020/01/06 10:05:47 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static int	numstring(char const *s1, char c)
{
	int	count;
	int	cles;

	count = 0;
	cles = 0;
	if (*s1 == '\0')
		return (0);
	while (*s1)
	{
		if (*s1 == c)
			cles = 0;
		else if (cles == 0)
		{
			cles = 1;
			count++;
		}
		s1++;
	}
	return (count);
}

static int	numchar(char const *s2, char c, int i)
{
	int count;

	count = 0;
	while (s2[i] && s2[i] != c)
	{
		i++;
		count++;
	}
	return (count);
}

char		**freee(char const **dst, int j)
{
	while (j > 0)
	{
		j--;
		free((void *)dst[j]);
	}
	free(dst);
	return (NULL);
}

char		**ft_split(char	const *s, char c)
{
	size_t	i;
	int		k;
	int		j;
	char	**dst;

	if (s == NULL)
		return (NULL);
	if (!(dst = (char**)malloc(sizeof(char*) * (numstring(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && j < numstring(s, c))
	{
		while (s[i] == c)
			i++;
		k = 0;
		if (!(dst[j] = (char*)malloc(numchar(s, c, i) + 1)))
			return (freee((char const **)dst, j));
		while (s[i] && s[i] != c)
			dst[j][k++] = s[i++];
		dst[j][k] = '\0';
		j++;
	}
	dst[j] = 0;
	return (dst);
}
