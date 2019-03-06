/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bturcott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:11:33 by bturcott          #+#    #+#             */
/*   Updated: 2018/11/25 04:27:00 by bturcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t l)
{
	char		*d;
	const char	*s;

	d = (char *)dest;
	s = (char *)source;
	while (l > 0)
	{
		*d = *s;
		d++;
		s++;
		l--;
	}
	return (dest);
}
