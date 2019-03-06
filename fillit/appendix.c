/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   appendix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bturcott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 14:58:49 by bturcott          #+#    #+#             */
/*   Updated: 2019/02/02 15:12:55 by bturcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_append(char **input, char *map, char **argv)
{
	if (!get_input(&input, argv[1]) || !standartize_input(&input))
	{
		erase_all_memory(&input, &map);
		print_error_message();
		return (0);
	}
	else
		return (1);
}
