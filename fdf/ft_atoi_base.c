/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bturcott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:46:45 by bturcott          #+#    #+#             */
/*   Updated: 2019/02/05 14:50:23 by bturcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	base(char c, int base)
{
	char	*str;
	char	*str2;
	int		i;

	str = "0123456789abcdef";
	str2 = "0123456789ABCDEF";
	i = 0;
	while (i < base)
	{
		if (c == str[i] || c == str2[i])
			return (i);
		i++;
	}
	return (0);
}

int	ft_atoi_base(const char *str, int b)
{
	int nb;
	int neg;
	int i;

	nb = 0;
	neg = 0;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = 1;
		i++;
	}
	while (str[i])
	{
		nb = nb * b;
		nb = nb + base(str[i], b);
		i++;
	}
	if (neg)
		return (-nb);
	return (nb);
}

int	ft_color(char *str)
{
	int color;

	color = 0;
	while (*str != ',')
		str++;
	str += 3;
	color = ft_atoi_base(str, 16);
	return (color);
}
