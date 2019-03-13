/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bturcott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 19:23:29 by bturcott          #+#    #+#             */
/*   Updated: 2019/03/11 20:55:08 by bturcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	set_fractal(t_calc *e, t_fract *m)
{
	e->min_re = -4.0;
	e->min_im = -1.0;
	e->scale = 300.0;
	e->iter = 500;
	e->color = 256;
	if (m->f == 'j')
	{
		e->c_x = 0.0;
		e->c_y = 0.8;
		e->mouse = 1;
	}
}

void	ft_put_pixel(int x, int y, int color, t_fract *map)
{
	int i;

	i = 0;
	if (x > 0 && y > 0 && x < WINDOW_X && y < WINDOW_Y)
		*(map->array + (x + y * WINDOW_X)) = color;
}

void	rotate_z(t_ter *cpy)
{
	int tx;
	int ty;
	int tz;

	tx = cpy->x;
	ty = cpy->y;
	tz = cpy->z;
	cpy->x = cos(0.53) * (tx - ty);
	cpy->y = -tz + (tx + ty) * sin(0.53);
}

void	draw_x_line(t_ter curr, t_ter prev, t_draw var, t_fract map)
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
		ft_put_pixel(x + prev.x + 1000, y + prev.y + 200, 0xFFFFFF, &map);
	}
}

void	drawing(t_ter curr, t_ter prev, t_fract map)
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
