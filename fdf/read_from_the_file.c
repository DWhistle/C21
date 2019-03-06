/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_the_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bturcott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 17:07:50 by bturcott          #+#    #+#             */
/*   Updated: 2019/01/11 19:24:15 by bturcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list	*ft_lst(t_list **begin, t_list *elem)
{
	t_list *temp;

	temp = NULL;
	if (!*begin)
	{
		*begin = ft_lstnew("", 0);
		elem = *begin;
		return (elem);
	}
	else
	{
		temp = ft_lstnew("", 0);
		elem->next = temp;
		return (temp);
	}
}

void	transform_into_struct(char *str, t_point *e, int i, int y)
{
	int j;

	j = 0;
	if (!ft_strchr(str, ','))
	{
		e[i].z = ft_atoi(str) * OFFSETZ;
		e[i].x = i + OFFSETX * i;
		e[i].y = y + OFFSETX * y;
	}
	else
	{
		e[i].z = ft_atoi(str) * OFFSETZ;
		e[i].x = i + OFFSETX * i;
		e[i].y = y + OFFSETX * y;
		e[i].color = ft_color(str);
	}
}

t_point	*transform_into_string(char **array, int y, t_point **e)
{
	t_point	*elem;
	int		i;

	i = ft_strlen2dim(array);
	if (!(elem = (t_point *)malloc(sizeof(t_point) * (i + 1))))
		return (NULL);
	if (!(*e = (t_point *)malloc(sizeof(t_point) * (i + 1))))
		return (NULL);
	i = 0;
	while (array[i])
	{
		transform_into_struct(array[i], elem, i, y);
		i++;
	}
	elem[i].color = -1;
	e[0][i].color = -1;
	return (elem);
}

t_point	**transform_into_array(t_list **begin, int counter, t_mlx *map)
{
	t_point	**e;
	int		i;
	t_list	*elem;

	i = 0;
	elem = *begin;
	if (!(e = (t_point **)malloc(sizeof(t_point *) * (counter + 1))))
		return (NULL);
	if (!(map->copy = (t_point **)malloc(sizeof(t_point *) * (counter + 1))))
		return (NULL);
	while (counter)
	{
		e[i] = transform_into_string((char **)(elem)->content,
		i, (&map->copy[i]));
		i++;
		free(*(elem)->content);
		counter--;
		elem = (elem)->next;
	}
	e[i] = NULL;
	map->copy[i] = NULL;
	return (e);
}

t_point	**file_reader(int fd, t_list **begin, t_mlx *map)
{
	char	*line;
	int		counter;
	t_list	*elem;
	t_point	**array;

	counter = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (!(elem = ft_lst(begin, elem)))
			return (NULL);
		elem->content = (void **)ft_strsplit(line, ' ');
		counter++;
	}
	array = transform_into_array(begin, counter, map);
	return (array);
}
