/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bturcott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:24:18 by bturcott          #+#    #+#             */
/*   Updated: 2018/11/25 05:30:22 by bturcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *source, int c, size_t l)
{
	size_t			m;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)source;
	m = 0;
	while (m < l)
	{
		d[m] = s[m];
		if (s[m] == (unsigned char)c)
			return (d + m + 1);
		m++;
	}
	return (NULL);
}
