/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bturcott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:20:00 by bturcott          #+#    #+#             */
/*   Updated: 2018/11/26 21:51:32 by bturcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countnums(int n)
{
	int i;

	i = 0;
	if (n < 0)
		i++;
	if (n == 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char		*ft_minint(char *dest)
{
	dest[0] = '-';
	dest[1] = '2';
	dest[2] = '1';
	dest[3] = '4';
	dest[4] = '7';
	dest[5] = '4';
	dest[6] = '8';
	dest[7] = '3';
	dest[8] = '6';
	dest[9] = '4';
	dest[10] = '8';
	dest[11] = '\0';
	return (dest);
}

char			*ft_itoa(int n)
{
	char	*dest;
	int		temp;
	int		num;

	temp = n;
	num = ft_countnums(n);
	if (!(dest = (char *)malloc(sizeof(char) * (num + 1))))
		return (NULL);
	if (n == -2147483648)
		return (ft_minint(dest));
	if (n < 0)
	{
		dest[0] = '-';
		n = -n;
	}
	dest[num--] = '\0';
	if (n == 0)
		dest[0] = '0';
	while (n)
	{
		temp = n;
		dest[num--] = temp % 10 + 48;
		n /= 10;
	}
	return (dest);
}
