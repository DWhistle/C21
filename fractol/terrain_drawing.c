/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terrain_drawing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bturcott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 19:30:27 by bturcott          #+#    #+#             */
/*   Updated: 2019/03/11 20:56:01 by bturcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	draw_a_string_horizontal(t_ter *e, t_fract *map)
{
	int i;

	i = 0;
	while (e[i + 1].z != -1)
	{
		drawing(e[i + 1], e[i], *map);
		i++;
	}
}

void	draw_a_string_vertical(t_ter *curr, t_ter *prev, t_fract *map)
{
	int i;

	i = 0;
	while (curr[i].z != -1 && prev[i].z != -1)
	{
		drawing(curr[i], prev[i], *map);
		i++;
	}
}

void	array_for_drawing(t_ter **e, t_fract *map)
{
	int i;

	i = 0;
	while (e[i])
	{
		draw_a_string_horizontal(e[i], map);
		if (i > 0)
			draw_a_string_vertical(e[i], e[i - 1], map);
		i++;
	}
}

void	rotate_a_string(t_ter *e, t_fract map)
{
	int i;

	i = 0;
	while (e[i].z != -1)
	{
		rotate_z(&e[i]);
		i++;
	}
}

void	rotate_an_array(t_ter **e, t_fract *map)
{
	int i;

	i = 0;
	while (e[i])
	{
		rotate_a_string(e[i], *map);
		i++;
	}
}
