/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bturcott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:57:18 by bturcott          #+#    #+#             */
/*   Updated: 2018/11/23 19:42:15 by bturcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *str1, const char *str2)
{
	char *dest;

	dest = str1;
	while (*dest)
		dest++;
	while (*str2)
	{
		*dest = *str2;
		dest++;
		str2++;
	}
	*dest = '\0';
	return (str1);
}
