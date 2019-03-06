/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bturcott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:43:57 by bturcott          #+#    #+#             */
/*   Updated: 2018/11/30 18:48:48 by bturcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	char *temp;

	temp = (char *)dest;
	while (n > 0)
	{
		*temp = (char)c;
		n--;
		temp++;
	}
	return (dest);
}
