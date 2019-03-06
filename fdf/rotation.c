/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bturcott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 21:27:39 by bturcott          #+#    #+#             */
/*   Updated: 2019/02/05 14:42:52 by bturcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		rotate_x(t_point *cpy, t_mlx map)
{
	int tx;
	int ty;
	int tz;

	tx = cpy->x;
	ty = cpy->y;
	tz = cpy->z;
	cpy->y = cos(map.cam->degx) * ty + tz * sin(map.cam->degx);
	cpy->z = -ty * sin(map.cam->degx) + tz * cos(map.cam->degx);
	cpy->x = tx;
}

void		rotate_y(t_point e, t_point *cpy, t_mlx map)
{
	int tx;
	int ty;
	int tz;

	tx = e.x * map.cam->offx;
	ty = e.y * map.cam->offx;
	tz = e.z * map.cam->offz;
	cpy->x = cos(map.cam->degy) * tx + tz * sin(map.cam->degy);
	cpy->z = -tx * sin(map.cam->degy) + tz * cos(map.cam->degy);
	cpy->y = ty;
	cpy->color = e.color;
}

void		rotate_z(t_point *cpy, t_mlx map)
{
	int tx;
	int ty;
	int tz;

	tx = cpy->x;
	ty = cpy->y;
	tz = cpy->z;
	cpy->x = cos(map.cam->degz) * tx - ty * sin(map.cam->degz);
	cpy->y = tx * sin(map.cam->degz) + ty * cos(map.cam->degz);
	cpy->z = tz;
}
