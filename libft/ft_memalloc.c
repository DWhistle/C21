/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bturcott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:59:56 by bturcott          #+#    #+#             */
/*   Updated: 2018/11/26 16:22:07 by bturcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*mas;
	int		i;

	i = size;
	if (!(mas = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	while (i >= 0)
	{
		mas[i] = 0;
		i--;
	}
	return ((void *)mas);
}
