/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bturcott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:32:34 by bturcott          #+#    #+#             */
/*   Updated: 2018/11/26 16:25:33 by bturcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *source, size_t l)
{
	unsigned char *d;
	unsigned char *s;

	d = (unsigned char *)dest;
	s = (unsigned char *)source;
	if (d == s)
		return (dest);
	if (s < d)
	{
		s = (unsigned char *)source + l - 1;
		d = dest + l - 1;
		while (l)
		{
			*d-- = *s--;
			l--;
		}
	}
	else
		while (l)
		{
			*d++ = *s++;
			l--;
		}
	return (dest);
}
