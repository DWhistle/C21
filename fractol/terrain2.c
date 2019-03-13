/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terrain2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bturcott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 21:05:32 by bturcott          #+#    #+#             */
/*   Updated: 2019/03/11 21:17:18 by bturcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	**filler(t_ter **a, int scale, int h)
{
	int y;
	int counter;

	y = 1500 / scale * h + 1;
	counter = 0;
	while (counter < scale)
	{
		a[0][counter].x = 1200 / scale * counter + 1;
		a[0][counter].y = y;
		a[0][counter].draw = 0;
		a[0][counter].z = 0;
		counter++;
	}
	a[0][counter].z = -1;
	return (NULL);
}

t_ter	**ft_ter(int scale, int seed)
{
	t_ter	**array;
	int		c;

	c = 0;
	if (!(array = (t_ter **)malloc(sizeof(t_ter *) * (scale + 1))))
		return (NULL);
	while (c < scale)
	{
		if (!(array[c] = (t_ter *)malloc(sizeof(t_ter) * (scale + 1))))
			return (NULL);
		filler(&array[c], scale, c);
		c++;
	}
	array[c] = NULL;
	return (array);
}

void	set_terrain(t_fract *m, char **av)
{
	m->seed = (float)ft_atoi(av[3]);
	m->scale = ft_atoi(av[2]);
	if (m->seed <= 0 || m->scale <= 0)
	{
		write(1, "Usage: -t [scale] [seed]\n", 26);
		exit(1);
	}
	m->ter = ft_ter(m->scale, m->seed);
	m->mult = m->scale - 1;
}

void	normalize_rep(t_ter **e, int scale, int i, int j)
{
	if (e[i][j].z == 0)
	{
		if (i - 1 > 0 && i + 1 < scale && j - 1 > 0 && j + 1 < scale)
			e[i][j].z = (e[i - 1][j].z + e[i][j + 1].z \
					+ e[i][j - 1].z + e[i + 1][j].z) / 4;
		else if (j - 1 > 0 && j + 1 < scale)
			e[i][j].z = (e[i][j + 1].z + e[i][j - 1].z) / 2;
		else if (i - 1 > 0 && i + 1 < scale)
			e[i][j].z = (e[i + 1][j].z + e[i - 1][j].z) / 2;
	}
}

void	normalize(t_ter **e, int scale, int rep)
{
	int i;
	int j;

	i = 0;
	while (e[++i])
	{
		j = -1;
		while (e[i][++j].z != -1)
		{
			if (rep == 1)
				normalize_rep(e, scale, i, j);
			else
			{
				if (i - 1 > 0 && i + 1 < scale && j - 1 > 0 && j + 1 < scale)
					e[i][j].z = (e[i - 1][j].z + e[i][j + 1].z \
							+ e[i][j - 1].z + e[i + 1][j].z) / 4;
				else if (j - 1 > 0 && j + 1 < scale)
					e[i][j].z = (e[i][j + 1].z + e[i][j - 1].z) / 2;
				else if (i - 1 > 0 && i + 1 < scale)
					e[i][j].z = (e[i + 1][j].z + e[i - 1][j].z) / 2;
			}
		}
	}
}
