/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bturcott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 21:49:09 by bturcott          #+#    #+#             */
/*   Updated: 2018/11/21 22:01:55 by bturcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		b;
	char	*dest;
	int		m;

	i = 0;
	b = 0;
	m = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[i])
		i++;
	while (s2[b])
		b++;
	if (!(dest = (char *)malloc(sizeof(char) * (i + b + 1))))
		return (NULL);
	while (m < i)
		dest[m++] = *(s1++);
	while (m < i + b)
		dest[m++] = *(s2++);
	dest[m] = '\0';
	return (dest);
}
