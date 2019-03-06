/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libx.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bturcott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:44:22 by bturcott          #+#    #+#             */
/*   Updated: 2019/02/05 14:46:37 by bturcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook(int key, t_mlx *mlx)
{
	key == 53 ? exit(1) : 0;
	key == 125 ? mlx->cam->y += 10 : 0;
	key == 126 ? mlx->cam->y -= 10 : 0;
	key == 123 ? mlx->cam->x -= 10 : 0;
	key == 124 ? mlx->cam->x += 10 : 0;
	key == 16 ? mlx->cam->degy += 0.05 : 0;
	key == 6 ? mlx->cam->degz += 0.05 : 0;
	key == 7 ? mlx->cam->degx += 0.05 : 0;
	key == 8 ? mlx->cam->color += 20 : 0;
	key == 15 ? mlx->cam->color = -1 : 0;
	key == 32 ? mlx->cam->offx += 1 : 0;
	key == 34 ? mlx->cam->offx -= 1 : 0;
	key == 24 ? mlx->cam->offz += 1 : 0;
	key == 27 ? mlx->cam->offz -= 1 : 0;
	key == 46 ? mlx->cam->r += 1 : 0;
	mlx_destroy_image(mlx->start, mlx->image);
	draw_the_map(*mlx);
	return (0);
}

int		closet(t_mlx *param)
{
	exit(0);
	return (0);
}

int		mouse_move(int x, int y, t_mlx *mlx)
{
	if (x > 0 && x < WINDOW_X && mlx->cam->r % 2 == 0)
		mlx->cam->x = x / 2;
	if (y > 0 && y < WINDOW_Y && mlx->cam->r % 2 == 0)
		mlx->cam->y = y / 2;
	mlx_destroy_image(mlx->start, mlx->image);
	draw_the_map(*mlx);
	return (0);
}

void	set_camera(t_camera *cam)
{
	cam->offx = 1;
	cam->offy = 1;
	cam->offz = 2;
	cam->x = OFFSETH;
	cam->y = OFFSETL;
	cam->degz = 0.00;
	cam->degx = 0.00;
	cam->degy = 0.00;
	cam->color = -1;
}

t_mlx	draw_the_map(t_mlx mlx)
{
	if (!mlx.start)
		mlx.start = mlx_init();
	if (!mlx.window)
		mlx.window = mlx_new_window(mlx.start, WINDOW_X, WINDOW_Y, "fdf");
	mlx.image = mlx_new_image(mlx.start, WINDOW_X, WINDOW_Y);
	mlx.img = (int *)mlx_get_data_addr(mlx.image, &mlx.bpp,
			&mlx.sizeline, &mlx.endian);
	rotate_an_array(mlx.array, &mlx);
	array_for_drawing(mlx.copy, mlx);
	mlx_put_image_to_window(mlx.start, mlx.window, mlx.image, 0, 0);
	mlx_hook(mlx.window, 2, 0, key_hook, &mlx);
	mlx_hook(mlx.window, 6, 0, mouse_move, &mlx);
	mlx_hook(mlx.window, 17, 0, closet, &mlx);
	mlx_loop(mlx.start);
	return (mlx);
}
