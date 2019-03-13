/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bturcott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 19:26:38 by bturcott          #+#    #+#             */
/*   Updated: 2019/03/11 20:49:28 by bturcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <stdio.h>

int		render(t_fract *map)
{
	if (map->render)
	{
		calculate_opencl(map, map->cl);
		mlx_put_image_to_window(map->ptr, map->window, map->img, 0, 0);
		map->render = 0;
	}
	return (0);
}

void	mlx_initialize(t_fract *map)
{
	map->render = 1;
	map->ptr = mlx_init();
	map->window = mlx_new_window(map->ptr, WINDOW_X, WINDOW_Y, "fractal");
	map->img = mlx_new_image(map->ptr, WINDOW_X, WINDOW_Y);
	map->array = (int *)mlx_get_data_addr(map->img, \
			&map->bpp, &map->sizeline, &map->endian);
	if (map->f != 't')
	{
		prepare_opencl(map, map->cl);
		mlx_put_image_to_window(map->ptr, map->window, map->img, 0, 0);
		mlx_hook(map->window, 4, 0, mouse_press, map);
		mlx_hook(map->window, 2, 0, key_hook, map);
		mlx_hook(map->window, 6, 0, mouse_move, map);
		mlx_loop_hook(map->ptr, render, map);
		mlx_loop(map->ptr);
	}
}

int		init_structures(t_fract **e, char **av)
{
	t_calc	*m;
	t_dev	*cl;

	if (!(*e = (t_fract *)malloc(sizeof(t_fract))))
		return (0);
	if (!(m = (t_calc *)malloc(sizeof(t_calc))))
		return (0);
	if (!(cl = (t_dev *)malloc(sizeof(t_dev))))
		return (0);
	(*e)->cl = cl;
	(*e)->e = m;
	if (av[1][1] == 't')
		(*e)->f = 't';
	if (av[1][1] == 'm' || av[1][1] == 'j')
	{
		create_device_n_context((*e)->cl);
		if (av[1][1] == 'm' && ((*e)->f = 'm'))
			build_program((*e)->cl, "mandel.cl");
		if (av[1][1] == 'j' && ((*e)->f = 'j'))
			build_program((*e)->cl, "julia.cl");
		set_fractal((*e)->e, *e);
	}
	mlx_initialize(*e);
	return (1);
}

int		main(int ac, char **av)
{
	t_fract *e;

	if (ac < 2 || av[1][0] != '-' || \
			(av[1][1] != 'j' && av[1][1] != 't' && av[1][1] != 'm'))
	{
		write(1, "usage: ./fractol -j -m -t\n", 27);
		return (0);
	}
	init_structures(&e, av);
	if (av[1][1] == 't' && ac > 3)
	{
		set_terrain(e, av);
		terrain(e);
	}
	else
		write(1, "Usage: -t [scale] [seed]\n", 26);
	return (0);
}
