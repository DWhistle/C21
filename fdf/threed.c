/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bturcott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:52:40 by bturcott          #+#    #+#             */
/*   Updated: 2019/02/05 14:53:02 by bturcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_a_string(t_point *e, t_mlx map, t_point *cpy)
{
	int i;

	i = 0;
	while (e[i].color != -1)
	{
		rotate_y(e[i], &cpy[i], map);
		rotate_x(&cpy[i], map);
		rotate_z(&cpy[i], map);
		i++;
	}
}

void	rotate_an_array(t_point **e, t_mlx *map)
{
	int i;

	i = 0;
	while (e[i])
	{
		rotate_a_string(e[i], *map, map->copy[i]);
		i++;
	}
}
