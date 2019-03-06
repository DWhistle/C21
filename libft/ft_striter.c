/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bturcott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 20:38:07 by bturcott          #+#    #+#             */
/*   Updated: 2018/11/21 20:39:39 by bturcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *c, void (*f)(char *))
{
	if (!c || !f)
		return ;
	while (*c)
	{
		f(c);
		c++;
	}
}