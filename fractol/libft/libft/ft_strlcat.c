/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bturcott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:14:29 by bturcott          #+#    #+#             */
/*   Updated: 2018/11/25 05:21:36 by bturcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (*(dest + i) && i < size)
		i++;
	if ((*(dest + i)))
		return (i + ft_strlen(src));
	else
		while (*(src) && size - 1 > i)
		{
			*(dest + i) = *src;
			i++;
			src++;
		}
	*(dest + i) = 0;
	return (i + ft_strlen(src));
}
