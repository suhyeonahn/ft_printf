/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suahn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:24:57 by suahn             #+#    #+#             */
/*   Updated: 2020/01/06 16:45:56 by suahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	ss1;
	unsigned int	ss2;
	unsigned int	i;
	char			*new;

	ss2 = ft_strlen(s1);
	ss1 = ft_strlen(s2);
	if (!(new = (char *)malloc(sizeof(char) * (ss1 + ss2 + 1))))
		return (NULL);
	i = 0;
	while (*s1)
		new[i++] = *s1++;
	while (*s2)
		new[i++] = *s2++;
	new[i] = '\0';
	return (new);
}
