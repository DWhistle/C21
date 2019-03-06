/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bturcott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:11:51 by bturcott          #+#    #+#             */
/*   Updated: 2019/02/05 15:08:01 by bturcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	generate_color(t_point prev, t_point curr, int delta, t_mlx *map)
{
	if (map->cam->color >= 1)
		return (0xFFFFFF - curr.z * map->cam->color);
	else if (curr.color)
		return (curr.color);
	return (0xFFFFFF);
}
