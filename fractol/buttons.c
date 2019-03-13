/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bturcott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 16:31:32 by bturcott          #+#    #+#             */
/*   Updated: 2019/03/11 20:53:31 by bturcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		mouse_move(int x, int y, t_fract *m)
{
	if (m->f == 'j' && m->e->mouse % 2 == 0)
	{
		m->e->c_x = (double)x / WINDOW_X;
		m->e->c_y = (double)y / WINDOW_Y;
	}
	m->render = 1;
	render(m);
	return (0);
}

void	ft_scale(t_fract *m, int x, int y)
{
	t_calc *e;

	e = m->e;
	e->min_re = (double)(x / e->scale + e->min_re) \
				- (double)(x / e->scale / 1.5);
	e->min_im = (double)(y / e->scale + e->min_im) \
				- (double)(y / e->scale / 1.5);
	e->scale *= 1.5;
}

void	ft_descale(t_fract *m, int x, int y)
{
	t_calc *e;

	e = m->e;
	e->min_re = (double)(x / e->scale + e->min_re) \
				- (double)(x / e->scale * 1.5);
	e->min_im = (double)(y / e->scale + e->min_im) \
				- (double)(y / e->scale * 1.5);
	e->scale /= 1.5;
}

int		mouse_press(int button, int x, int y, t_fract *e)
{
	if (button == 4)
		ft_scale(e, x, y);
	if (button == 5)
		ft_descale(e, x, y);
	e->render = 1;
	render(e);
	return (0);
}

int		key_hook(int key, t_fract *e)
{
	if (key == 53)
		exit(1);
	if (e->f != 't')
	{
		if (key == 24)
			e->e->iter += 50;
		if (key == 27)
			e->e->iter -= 50;
		if (key == 38)
			e->e->mouse += 1;
		if (key == 8)
			e->e->color += 20000;
		if (key == 15 && e->e->color > 20000)
			e->e->color -= 20000;
		e->render = 1;
		render(e);
	}
	return (0);
}
