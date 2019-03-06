/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bturcott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:54:31 by bturcott          #+#    #+#             */
/*   Updated: 2019/02/05 14:55:11 by bturcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_pixel(int x, int y, int color, t_mlx *map)
{
	int i;

	i = 0;
	if (x > 0 && y > 0 && x < WINDOW_X && y < WINDOW_Y)
		*(map->img + (x + y * WINDOW_X)) = color;
}

int		ft_strlen2dim(char **array)
{
	int i;

	while (array[i])
		i++;
	return (i);
}

void	ft_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_struct_swap(t_point *prev, t_point *curr)
{
	t_point temp;

	temp = *prev;
	*prev = *curr;
	*curr = *prev;
}

void	*ft_del_elem(void **array, int size)
{
	void **temp;

	temp = array;
	while (*array)
	{
		free(*array);
		array++;
	}
	return (0);
}
