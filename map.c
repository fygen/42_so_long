/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayegen <ayegen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 05:22:44 by ayegen            #+#    #+#             */
/*   Updated: 2024/07/06 20:15:40 by ayegen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_cord(char *map, t_state *data)
{
	int		fd;
	int		x;
	int		y;
	char	*tmp;

	fd = open(map, O_RDONLY, 0777);
	tmp = get_next_line(fd);
	x = 0;
	if (tmp == NULL)
		ft_error("map is null");
	while (tmp[x] != '\0' && tmp[x] != '\n')
		x++;
	free(tmp);
	y = 1;
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		free(tmp);
		y++;
	}
	data->y = y;
	data->x = x;
	close(fd);
}

void	read_map(t_state *data, char *map)
{
	char	*tmp;
	int		fd;
	int		i;

	fd = open(map, O_RDONLY);
	i = 0;
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
		{
			data->map[i] = NULL;
			break ;
		}
		data->map[i] = tmp;
		i++;
	}
	close(fd);
}

void	assign_image(t_state *data)
{
	int	w;
	int	h;

	data->mlx = mlx_init();
	data->img_paths = malloc(sizeof(t_xpm));
	data->win = mlx_new_window(data->mlx, (data->x) * 64, (data->y) * 64,
			"so_long");
	data->img_paths->img_1 = mlx_xpm_file_to_image(data->mlx,
			"./textures/wall.xpm", &w, &h);
	data->img_paths->img_c = mlx_xpm_file_to_image(data->mlx,
			"./textures/collectiable.xpm", &w, &h);
	data->img_paths->img_e = mlx_xpm_file_to_image(data->mlx,
			"./textures/exit.xpm", &w, &h);
	data->img_paths->img_p = mlx_xpm_file_to_image(data->mlx,
			"./textures/player.xpm", &w, &h);
	data->img_paths->img_0 = mlx_xpm_file_to_image(data->mlx,
			"./textures/empty.xpm", &w, &h);
}

void	put_image(t_state *data, char **map, int i, int j)
{
	if (map[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->img_paths->img_1, j
			* 64, i * 64);
	else if (map[i][j] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->img_paths->img_p, j
			* 64, i * 64);
	else if (map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->img_paths->img_e, j
			* 64, i * 64);
	else if (map[i][j] == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img_paths->img_c, j
			* 64, i * 64);
	}
	else if (map[i][j] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->img_paths->img_0, j
			* 64, i * 64);
}

void	put_map(t_state *data)
{
	char	**map;
	int		i;
	int		j;

	map = data->map;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			put_image(data, map, i, j);
		}
	}
}
