/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bturcott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:42:49 by bturcott          #+#    #+#             */
/*   Updated: 2018/11/27 20:18:41 by bturcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *so;

	so = (unsigned char *)s;
	while (n > 0)
	{
		if (*so == (unsigned char)c)
			return ((void *)so);
		n--;
		so++;
	}
	return (NULL);
}
