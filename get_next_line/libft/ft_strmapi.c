/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bturcott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 21:10:26 by bturcott          #+#    #+#             */
/*   Updated: 2018/11/21 21:18:58 by bturcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		m;
	char	*dest;

	i = 0;
	m = 0;
	if (!f || !s)
		return (NULL);
	if (!(dest = ft_strdup(s)))
		return (NULL);
	while (s[i])
	{
		dest[m] = f(i, s[i]);
		m++;
		i++;
	}
	dest[m] = '\0';
	return (dest);
}
