/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bturcott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:14:33 by bturcott          #+#    #+#             */
/*   Updated: 2018/11/23 19:46:24 by bturcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	int i;
	int mem;

	i = 0;
	mem = 0;
	if (*str2 == 0)
		return ((char *)str1);
	while (str1[i])
	{
		mem = 0;
		while (str1[i + mem] == str2[mem])
		{
			if (str2[mem + 1] == 0)
				return ((char *)str1 + i);
			mem++;
		}
		i++;
	}
	return (NULL);
}
