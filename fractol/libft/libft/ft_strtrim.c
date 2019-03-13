/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bturcott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 22:02:13 by bturcott          #+#    #+#             */
/*   Updated: 2018/11/26 21:22:51 by bturcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_sp(char const *s)
{
	int sp;
	int i;
	int t;

	sp = 0;
	i = 0;
	t = 0;
	while (s[i] && (s[i] == 32 || s[i] == '\n' || s[i] == '\t'))
	{
		sp++;
		i++;
	}
	while (s[i])
		i++;
	if (sp == i)
		return (0);
	t = i;
	i--;
	while (s[i] == 32 || s[i] == '\n' || s[i] == '\t')
	{
		sp++;
		i--;
	}
	return (t - sp);
}

char			*ft_strtrim(char const *s)
{
	int		sp;
	char	*dest;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	sp = ft_sp(s);
	i = 0;
	j = 0;
	if (s == NULL)
		return ((char *)s);
	if (!(dest = (char *)malloc(sizeof(char) * (sp + 1))))
		return (NULL);
	while (s[i] && (s[i] == 32 || s[i] == '\n' || s[i] == '\t'))
		i++;
	while (j < sp)
	{
		dest[j] = s[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
