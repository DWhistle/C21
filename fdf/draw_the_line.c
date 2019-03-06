/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_the_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bturcott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:56:20 by bturcott          #+#    #+#             */
/*   Updated: 2019/02/05 14:59:20 by bturcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_x_line(t_point curr, t_point prev, t_draw var, t_mlx map)
{
	int		x;
	int		y;
	double	mistake;

	x = 0;
	y = 0;
	mistake = 0;
	while (--var.d + 1)
	{
		if (var.l == 'x')
			(var.dx > 0 ? x++ : x--);
		else
			(var.dy > 0 ? y++ : y--);
		mistake += var.r;
		if (mistake >= 1)
		{
			if (var.l == 'x')
				var.dy > 0 ? y++ : y--;
			else
				var.dx > 0 ? x++ : x--;
			mistake -= 1;
		}
		ft_put_pixel(x + prev.x + map.cam->x, y + prev.y + map.cam->y,
				generate_color(prev, curr, var.d, &map), &map);
	}
}

void	drawing(t_point curr, t_point prev, t_mlx map)
{
	t_draw var;

	var.dy = curr.y - prev.y;
	var.dx = curr.x - prev.x;
	var.dx = (var.dx < 0 ? -var.dx : var.dx);
	var.dy = (var.dy < 0 ? -var.dy : var.dy);
	var.l = (var.dx > var.dy ? 'x' : 'y');
	var.d = (var.dy > var.dx ? var.dy : var.dx);
	var.r = (double)(var.dy > var.dx ? (double)var.dx / var.dy :
			(double)var.dy / var.dx);
	var.dy = curr.y - prev.y;
	var.dx = curr.x - prev.x;
	draw_x_line(curr, prev, var, map);
}

void	draw_a_string_horizontal(t_point *e, t_mlx map)
{
	int i;

	i = 0;
	while (e[i + 1].color != -1)
	{
		drawing(e[i + 1], e[i], map);
		i++;
	}
}

void	draw_a_string_vertical(t_point *curr, t_point *prev, t_mlx map)
{
	int i;

	i = 0;
	while (curr[i].color != -1 && prev[i].color != -1)
	{
		drawing(curr[i], prev[i], map);
		i++;
	}
}

void	array_for_drawing(t_point **e, t_mlx map)
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
