/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bturcott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 05:32:06 by bturcott          #+#    #+#             */
/*   Updated: 2018/11/27 20:16:53 by bturcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_split(char const *s, char c, char *d, int i)
{
	int mem;
	int temp;

	mem = 0;
	temp = i;
	while (s[i] != c && s[i])
	{
		i++;
		mem++;
	}
	if (!(d = (char *)malloc(sizeof(char) * (mem + 1))))
		return (NULL);
	mem = 0;
	while (s[temp] != c && s[temp])
	{
		d[mem] = s[temp];
		mem++;
		temp++;
	}
	d[mem] = '\0';
	return (d);
}

static int		ft_words(char const *s, char c)
{
	int i;
	int word;

	i = -1;
	word = 0;
	while (s[++i])
	{
		if (s[i] != c)
		{
			word++;
			while (s[i] != c && s[i])
				i++;
			i--;
		}
	}
	return (word);
}

static void		ft_free_array(char **dest, int i)
{
	while (i >= 0)
	{
		free(dest[i]);
		i--;
	}
	dest = NULL;
}

char			**ft_strsplit(char const *s, char c)
{
	char	**dest;
	int		j;
	int		i;

	j = 0;
	i = 0;
	if (!s || !(dest = (char **)malloc(sizeof(char *) * (ft_words(s, c) + 1))))
		return (NULL);
	while (s[i] && j < ft_words(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != c && s[i])
			if (!(dest[j] = ft_split(s, c, dest[j], i)))
			{
				ft_free_array(dest, ft_words(s, c) + 1);
				return (NULL);
			}
		j++;
		while (s[i] && s[i] != c)
			i++;
	}
	dest[j] = NULL;
	return (dest);
}
