/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayegen <ayegen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 01:42:47 by ayegen            #+#    #+#             */
/*   Updated: 2024/07/06 21:40:48 by ayegen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "stdio.h"

static int	close_window(t_state *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_state	*data;

	if (argc == 2)
	{
		arg_check(argv[1]);
		data = malloc(sizeof(t_state));
		data->movement = 0;
		map_cord(argv[1], data);
		if (data->x >= 128 || data->y >= 128)
			ft_error("Map size isn't compatiable with mlx library.");
		data->map = (char **)malloc(sizeof(char *) * (data->y + 1));
		read_map(data, argv[1]);
		mapcheck(data);
		assign_image(data);
		put_map(data);
		mlx_key_hook(data->win, deal_key, data);
		mlx_hook(data->win, 17, 0, close_window, data);
		mlx_loop(data->mlx);
	}
	else
		write(1, "Usage : ./so_long <map_location>", 32);
}
