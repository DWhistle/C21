/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terrain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bturcott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 18:49:16 by bturcott          #+#    #+#             */
/*   Updated: 2019/03/11 21:04:59 by bturcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	algo_diamond(int s, t_fract *m, int sp, int sy)
{
	t_ter **e;

	e = m->ter;
	if (sy + s / 4 < m->scale - 1 && s / 2 + sp < m->scale - 1)
		e[sy + s / 4][s / 2 + sp].z = (e[sy][s / 2 + sp].z \
				+ e[sy + s / 2][s + sp].z + e[sy + s][s / 2 + sp].z \
				+ e[sy + s / 2][sp].z + e[sy + s / 2][sp + s / 2].z) / 4 \
				+ rand() % (int)m->scale;
	if (sy + s / 2 < m->scale - 1 && s / 4 + sp < m->scale - 1)
		e[sy + s / 2][s / 4 + sp].z = (e[sy][s / 2 + sp].z \
				+ e[sy + s / 2][s + sp].z + e[sy + s][s / 2 + sp].z \
				+ e[sy + s / 2][sp].z + e[sy + s / 2][sp + s / 2].z) / \
				4 + rand() % (int)m->scale;
	if (sy + s * 3 / 4 < m->scale - 1 && s / 2 + sp < m->scale - 1)
		e[sy + s * 3 / 4][s / 2 + sp].z = (e[sy][s / 2 + sp].z \
				+ e[sy + s / 2][s + sp].z \
				+ e[sy + s][s / 2 + sp].z + e[sy + s / 2][sp].z + \
				e[sy + s / 2][sp + s / 2].z) / 4 + rand() % (int)m->scale;
	if (sy + s / 2 < m->scale - 1 && sp + s / 4 * 3 < m->scale - 1)
		e[sy + s / 2][sp + s / 4 * 3].z = (e[sy][s / 2 + sp].z + \
				e[sy + s / 2][s + sp].z + e[sy + s][s / 2 + sp].z \
				+ e[sy + s / 2][sp].z + e[sy + s / 2][sp + s / 2].z) / 4 \
				+ rand() % (int)m->scale;
}

void	algo_null(int scale, t_fract *m, int sp, int sy)
{
	t_ter	**e;
	int		c;

	e = m->ter;
	c = 1;
	if (sy < m->scale && scale / 2 + sp < m->scale && c++)
		e[sy][scale / 2 + sp].z = 0;
	if (sy + scale / 2 < m->scale && scale + sp < m->scale && c++)
		e[sy + scale / 2][scale + sp].z = 0;
	if (sy + scale < m->scale && scale / 2 + sp < m->scale && c++)
		e[sy + scale][scale / 2 + sp].z = 0;
	if (sy + scale / 2 < scale && sp < m->scale && c++)
		e[sy + scale / 2][sp].z = 0;
}

void	algo_square(int scale, t_fract *m, int sp, int sy)
{
	t_ter	**e;
	int		c;

	e = m->ter;
	c = 1;
	if (sy < m->scale && scale / 2 + sp < m->scale && c++)
		e[sy][scale / 2 + sp].z = rand() % (int)m->seed;
	if (sy + scale / 2 < m->scale && scale + sp < m->scale && c++)
		e[sy + scale / 2][scale + sp].z = rand() % (int)m->seed;
	if (sy + scale < m->scale && scale / 2 + sp < m->scale && c++)
		e[sy + scale][scale / 2 + sp].z = rand() % (int)m->seed;
	if (sy + scale / 2 < scale && sp < m->scale && c++)
		e[sy + scale / 2][sp].z = rand() % ((int)m->seed);
	if (c >= 4)
		e[sy + scale / 2][sp + scale / 2].z = (e[sy][scale / 2 + sp].z \
				+ e[sy + scale / 2][scale + sp].z \
				+ e[sy + scale][scale / 2 + sp].z \
				+ e[sy + scale / 2][sp].z) / 4;
}

void	algo(t_fract *m)
{
	int iter;
	int startx;
	int starty;
	int itprev;

	itprev = 0;
	iter = 1;
	while (m->mult > 2)
	{
		itprev = iter;
		startx = 0;
		starty = 0;
		while (--iter + 4)
		{
			if (startx >= m->scale - 1 && (starty += m->mult))
				startx = 0;
			algo_square(m->mult, m, startx, starty);
			algo_diamond(m->mult, m, startx, starty);
			startx += m->mult;
			m->seed = m->seed > 1.3 ? m->seed / 1.01 : 1.3;
		}
		iter = (itprev == 0) ? 1 : itprev * 4;
		m->mult /= 2;
	}
}

void	terrain(t_fract *m)
{
	algo(m);
	normalize(m->ter, m->scale, 1);
	normalize(m->ter, m->scale, 0);
	ter_clean(m->ter, m->scale);
	rotate_an_array(m->ter, m);
	array_for_drawing(m->ter, m);
	mlx_put_image_to_window(m->ptr, m->window, m->img, 0, 0);
	mlx_hook(m->window, 2, 0, key_hook, m);
	mlx_loop(m->ptr);
}
