/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bturcott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:31:02 by bturcott          #+#    #+#             */
/*   Updated: 2018/11/27 18:14:22 by bturcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t l)
{
	size_t i;
	size_t m;

	i = 0;
	m = 0;
	if (*s2 == 0)
		return ((char *)s1);
	while (s1[i] && i < l)
	{
		m = 0;
		if (s1[i] == s2[m])
		{
			while (s1[i + m] == s2[m] && m + i < l)
			{
				m++;
				if (s2[m] == 0)
					return ((char *)(s1 + i));
			}
		}
		i++;
	}
	return (NULL);
}
