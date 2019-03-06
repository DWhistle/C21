/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bturcott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 05:26:01 by bturcott          #+#    #+#             */
/*   Updated: 2018/11/27 18:56:09 by bturcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	size_t	temp;
	void	*c;

	temp = content_size;
	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!(c = malloc(content_size)))
	{
		content = NULL;
		free(new);
		new = NULL;
		return (NULL);
	}
	if (!(content))
	{
		c = NULL;
		temp = 0;
	}
	new->content_size = temp;
	new->content = ft_memcpy(c, content, temp);
	new->next = NULL;
	return (new);
}
