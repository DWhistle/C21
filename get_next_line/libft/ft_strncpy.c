/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bturcott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:41:56 by bturcott          #+#    #+#             */
/*   Updated: 2018/11/22 19:10:39 by bturcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t l)
{
	char *d;

	d = dest;
	while (l > 0 && *src)
	{
		*dest = *src;
		dest++;
		src++;
		l--;
	}
	while (l > 0)
	{
		*dest = 0;
		dest++;
		l--;
	}
	return (d);
}
