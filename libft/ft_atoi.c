/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bturcott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:56:27 by bturcott          #+#    #+#             */
/*   Updated: 2018/11/26 17:57:11 by bturcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int res;
	int neg;

	res = 0;
	neg = 0;
	while (((*str >= 9 && *str <= 13) || *str == 32) && *str)
		str++;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	if ((*str == '-' && neg == -1) || (*str == '+' && neg == -1))
		return (0);
	if (*str == '+')
		str++;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		res = res * 10 + (int)(*str - '0');
		str++;
	}
	if (neg == -1)
		return (-res);
	return (res);
}
