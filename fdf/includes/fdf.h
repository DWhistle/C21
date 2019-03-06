/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bturcott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 17:05:27 by bturcott          #+#    #+#             */
/*   Updated: 2019/02/05 15:16:07 by bturcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <unistd.h>
# include "get_next_line.h"
# include <math.h>
# include <stdlib.h>
# include "libft.h"
# include <fcntl.h>
# define WINDOW_X 2700
# define WINDOW_Y 1500
# define OFFSETX 2
# define OFFSETZ 2
# define OFFSETL 400
# define OFFSETH 400

typedef struct	s_point
{
	int x;
	int y;
	int z;
	int color;
}				t_point;

typedef struct	s_camera
{
	int		offx;
	int		offy;
	int		offz;
	int		x;
	int		y;
	float	degz;
	float	degy;
	float	degx;
	char	r;
	int		color;
}				t_camera;

typedef struct	s_mlx
{
	t_camera	*cam;
	void		*start;
	void		*window;
	t_point		**array;
	t_point		**copy;
	int			len;
	void		*image;
	int			*img;
	int			bpp;
	int			sizeline;
	int			endian;
}				t_mlx;

typedef struct	s_drawing
{
	int		dx;
	int		dy;
	int		d;
	char	l;
	double	r;
}				t_draw;

int				ft_atoi_base(const char *str, int b);
t_point			**file_reader(int fd, t_list **begin, t_mlx *map);
t_point			**transform_into_array(t_list **begin, int counter, t_mlx *map);
t_point			*transform_into_string(char **array, int y, t_point **e);
void			transform_into_struct(char *str, t_point *e, int i, int y);
t_list			*ft_lst(t_list **begin, t_list *elem);
int				ft_strlen2dim(char **array);
int				ft_color(char *str);
t_mlx			draw_the_map(t_mlx mlx);
void			ft_swap(int *a, int *b);
void			ft_struct_swap(t_point *prev, t_point *curr);
void			array_for_drawing(t_point **e, t_mlx map);
void			rotate_an_array(t_point **e, t_mlx *map);
int				generate_color(t_point prev, t_point curr, int delta,
		t_mlx *map);
void			rotate_x(t_point *cpy, t_mlx map);
void			rotate_y(t_point e, t_point *cpy, t_mlx map);
void			rotate_z(t_point *cpy, t_mlx map);
void			set_camera (t_camera *cam);
void			*ft_del_elem(void **array, int size);
void			ft_clean(t_list **begin);
void			ft_put_pixel(int x, int y, int color, t_mlx *map);
#endif
