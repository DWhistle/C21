/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bturcott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 18:07:32 by bturcott          #+#    #+#             */
/*   Updated: 2019/02/05 15:08:32 by bturcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	int		c;
	t_list	*begin;
	t_mlx	map;

	begin = NULL;
	map.window = NULL;
	map.start = NULL;
	map.cam = (t_camera *)malloc(sizeof(t_camera));
	set_camera(map.cam);
	if (argc == 2)
	{
		c = open(argv[1], O_RDONLY);
		if (c == -1)
			return (0);
		map.array = file_reader(c, &begin, &map);
	}
	else
	{
		write(1, "usage: ./fdf map\n", 16);
		return (0);
	}
	map = draw_the_map(map);
	return (0);
}
