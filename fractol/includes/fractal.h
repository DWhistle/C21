/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bturcott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 15:26:35 by bturcott          #+#    #+#             */
/*   Updated: 2019/03/11 21:29:42 by bturcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "mlx.h"
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include "libft.h"
# include "stdio.h"
# include <fcntl.h>
# include "OpenCL/cl.h"
# define WINDOW_X 2048
# define WINDOW_Y 2048
# define MAND "mandel.cl"

typedef struct			s_device
{
	cl_platform_id		platform;
	cl_device_id		device;
	cl_context			context;
	cl_program			program;
	cl_kernel			kernel;
	cl_command_queue	queue;
	cl_mem				buff;
	int					err;
}						t_dev;

typedef struct			s_fract
{
	void				*ptr;
	void				*window;
	void				*img;
	int					*array;
	int					bpp;
	int					sizeline;
	int					endian;
	struct s_mand		*e;
	char				f;
	struct s_terrain	**ter;
	float				seed;
	int					scale;
	int					mult;
	struct s_device		*cl;
	int					render;
}						t_fract;

typedef struct			s_mand
{
	double	min_re;
	double	min_im;
	double	c_x;
	double	c_y;
	double	z_x;
	double	z_y;
	int		x;
	int		y;
	int		mouse;
	double	scale;
	int		iter;
	int		color;
	void	*image;
}						t_calc;

typedef struct			s_terrain
{
	int		x;
	int		y;
	int		z;
	char	draw;
}						t_ter;

typedef struct			s_drawing
{
	int		dx;
	int		dy;
	int		d;
	char	l;
	double	r;
}						t_draw;

void					mlx_mandelbrot_set(t_fract *map);
void					mlx_initialize(t_fract *map);
void					mlx_julia_set(t_fract *map);
void					adjust_mandelbrot(t_fract *m);
void					set_fractal(t_calc *e, t_fract *m);
int						key_hook(int key, t_fract *e);
int						mouse_press(int button, int x, int y, t_fract *e);
int						calculate_julia(t_fract *m);
void					set_terrain(t_fract *m, char **av);
int						analyze(int x, int y, int rule, t_ter *e);
void					terrain(t_fract *m);
void					array_for_drawing(t_ter **e, t_fract *m);
void					rotate_z(t_ter *cpy);
void					rotate_an_array(t_ter **e, t_fract *map);
void					drawing(t_ter curr, t_ter prev, t_fract map);
void					create_device_n_context(t_dev *cl);
void					build_program(t_dev *cl, char *program);
void					prepare_opencl(t_fract *m, t_dev *cl);
int						render(t_fract *map);
void					calculate_opencl(t_fract *m, t_dev *cl);
int						mouse_move(int x, int y, t_fract *m);
void					normalize(t_ter **e, int scale, int rep);
void					ter_clean(t_ter **e, int scale);
void					set_terrain(t_fract *m, char **av);
#endif
