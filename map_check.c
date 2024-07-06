/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayegen <ayegen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 04:44:41 by ayegen            #+#    #+#             */
/*   Updated: 2024/07/06 16:18:58 by ayegen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_player(t_state *data, char **map)
{
	int	player_count;
	int	x;
	int	y;

	x = 0;
	player_count = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'P')
			{
				player_count++;
				data->player[0] = x;
				data->player[1] = y;
			}
			if (player_count == 2)
				free_map(map, "it has to be one player in the game.");
			y++;
		}
		x++;
	}
	if (player_count == 0)
		free_map(map, "There isn't any player in the map.");
}

void	check_map_chars(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i][j])
		{
			if (str[i][j] == '1' || str[i][j] == '0' || str[i][j] == 'P'
				|| str[i][j] == 'E' || str[i][j] == 'C' || str[i][j] == '\n')
				j++;
			else
				free_map(str, "The characters on the map are wrong!");
		}
		j = 0;
		i++;
	}
}

void	check_exit(t_state *data, char **map)
{
	int	exit_count;
	int	x;
	int	y;

	x = 0;
	exit_count = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'E')
			{
				exit_count++;
				data->exit[0] = x;
				data->exit[1] = y;
			}
			if (exit_count == 2)
				free_map(map, "it has to be one exit in the game.");
			y++;
		}
		x++;
	}
	if (exit_count == 0)
		free_map(map, "There isn't any exit in the map.");
}

void	col_check(t_state *data, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			if (map[i][j++] == 'C')
				data->collectiables++;
		i++;
	}
	if (data->collectiables == 0)
		free_map(map, "No collectible objects found on the map!");
}

void	is_closed_map(char **map)
{
	int	i;

	i = 0;
	while (map[strlen_y(map) - 1][i])
		if (map[strlen_y(map) - 1][i++] != '1')
			free_map(map, "The bottom of the map is not closed!");
	i = 0;
	while (map[0][i] != '\n')
		if (map[0][i++] != '1')
			free_map(map, "The top of the map is not closed!");
	i = 0;
	while (map[i])
		if (map[i++][0] != '1')
			free_map(map, "The left side of the map is not closed!");
	i = 0;
	while (map[i])
		if (map[i++][ft_strlen(map[0]) - 2] != '1')
			free_map(map, "The right side of the map is not closed!");
}
