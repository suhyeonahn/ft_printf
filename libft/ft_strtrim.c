/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 15:46:39 by suahn             #+#    #+#             */
/*   Updated: 2020/01/06 10:05:31 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		isin_set(char c, char const *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int i;
	int j;

	i = 0;
	while (isin_set(s1[i], set) == 1 && s1[i])
	{
		i++;
		isin_set(s1[i], set);
	}
	j = ft_strlen(s1) - 1;
	while (isin_set(s1[j], set) == 1 && s1[j] && j > i)
	{
		j--;
		isin_set(s1[j], set);
	}
	if (s1 == NULL)
		return (NULL);
	else
		return (ft_substr(s1, i, j - i + 1));
}
