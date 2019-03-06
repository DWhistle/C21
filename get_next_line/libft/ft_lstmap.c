/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bturcott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:19:10 by bturcott          #+#    #+#             */
/*   Updated: 2018/11/27 19:07:53 by bturcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_freelst(t_list **targ)
{
	t_list *cp;

	cp = *targ;
	while (*targ)
	{
		*targ = (*targ)->next;
		free(cp);
		cp = NULL;
		cp = *targ;
	}
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *mem;
	t_list *dest;

	if (lst && f)
		dest = f(lst);
	else
		return (NULL);
	if (!(mem = ft_lstnew(dest->content, dest->content_size)))
	{
		ft_freelst(&mem);
		return (NULL);
	}
	mem = dest;
	lst = lst->next;
	while (lst)
	{
		if (!(dest->next = f(ft_lstnew(lst->content, lst->content_size))))
		{
			ft_freelst(&mem);
			return (NULL);
		}
		lst = lst->next;
		dest = dest->next;
	}
	return (mem);
}
