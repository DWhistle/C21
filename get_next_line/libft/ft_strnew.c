/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bturcott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 20:19:12 by bturcott          #+#    #+#             */
/*   Updated: 2018/11/26 17:39:37 by bturcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*dest;
	int		i;

	i = size;
	if (!(dest = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i >= 0)
	{
		dest[i] = 0;
		i--;
	}
	return (dest);
}
